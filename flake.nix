{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = {
    self,
    nixpkgs,
    flake-utils,
  }:
    flake-utils.lib.eachDefaultSystem (system: let
      pkgs = nixpkgs.legacyPackages.${system};
    in {
      packages = rec {
        default = webviewer;
        webviewer = pkgs.callPackage ./default.nix {};
      };
      devShell = pkgs.mkShell {
        buildInputs = with pkgs; [
          qt6.full
          cmake
          ninja
          gcc
          gdb
        ];
      };
    });
}
