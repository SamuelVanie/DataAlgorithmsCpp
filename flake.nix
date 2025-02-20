{
  inputs.flake-utils.url = "github:numtide/flake-utils";

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachSystem flake-utils.lib.defaultSystems (system: let
      pkgs = import nixpkgs { inherit system; };
      junitJar = pkgs.fetchurl {
        url = "https://repo1.maven.org/maven2/junit/junit/4.13.2/junit-4.13.2.jar";
        sha256 = "sha256-jklbY0Rp1k+4rPo0laBly6zIoP/1XOHjEAe+TBbcV9M=";
      };
      hamcrestJar = pkgs.fetchurl {
        url = "https://repo1.maven.org/maven2/org/hamcrest/hamcrest-core/1.3/hamcrest-core-1.3.jar";
        sha256 = "sha256-Zv3vkelzk0jfeglqo4SlaF9Oh1WEzOiThqekclHE2Ok=";
      };
    in {
      devShells.default = pkgs.mkShell {
        packages = with pkgs; [
          jdt-language-server
          jdk
          emacsPackages.lsp-java
        ];
        # Add to emacs load path with
        # (use-package lsp-java :ensure nil :config (add-hook 'java-mode-hook 'lsp))
        # (smv/add-nix-pkg-to-lpath "EMACSPKGS_LSPJAVA")
        shellHook = ''
          export CLASSPATH="${junitJar}:${hamcrestJar}:$CLASSPATH"
          export EMACSPKGS_LSPJAVA="${pkgs.emacsPackages.lsp-java}"
        '';
      };
    });
}

