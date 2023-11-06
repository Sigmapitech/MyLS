{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
  };

  outputs = { self, nixpkgs }:
    let
      forAllSystems = function:
        nixpkgs.lib.genAttrs [
          "x86_64-linux"
          "aarch64-linux"
        ]
          (system: function nixpkgs.legacyPackages.${system});
    in
    {
      formatter = forAllSystems (pkgs: pkgs.nixpkgs-fmt);

      devShells = forAllSystems (pkgs: {
        default = pkgs.mkShell {
          packages = with pkgs; [
            criterion
            gcc13
            gcovr
            glibc
            gnumake
            python310Packages.compiledb
            valgrind
          ];
        };
      });

      packages = forAllSystems (pkgs: rec {
        default = setting_up;
        setting_up = pkgs.stdenv.mkDerivation rec {
          name = "my_ls";
          src = ./.;

          makeFlags = [ "CC=${pkgs.gcc13}/bin/gcc" ];
          buildInputs = [ pkgs.gnumake ];

          hardeningDisable = [ "format" "fortify" ];
          enableParallelBuilding = true;

          installPhase = ''
            runHook preInstall

            mkdir -p $out/bin
            cp ${name} $out/bin/${name}

            runHook postInstall
          '';
        };

        debug = setting_up.overrideAttrs(prev: rec {
          name = "debug";

          buildPhase = ''
            runHook preBuild

            make ${name}

            runHook postBuild
          '';

          installPhase = ''
            runHook preInstall

            mkdir -p $out/bin
            cp ${name} $out/bin/${name}

            runHook postInstall
          '';
        });
      });
    };
}
