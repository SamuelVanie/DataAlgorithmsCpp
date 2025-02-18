{
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachSystem flake-utils.lib.defaultSystems (system: let
      pkgs = import nixpkgs { inherit system; };
      junitJar = pkgs.fetchurl {
        url = "https://repo1.maven.org/maven2/junit/junit/4.13.2/junit-4.13.2.jar";
        sha256 = "sha256-jklbY0Rp1k+4rPo0laBly6zIoP/1XOHjEAe+TBbcV9M=";
      };
    in {
      devShells.default = pkgs.mkShell {
        packages = with pkgs; [
          jdt-language-server
          jdk
        ];
        shellHook = ''
          export CLASSPATH="${junitJar}:$CLASSPATH"
        '';
      };
    });
}

