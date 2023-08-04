{
  description = "Firefly Simulation";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-23.05";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      with import nixpkgs { inherit system; }; {
        devShells.default = mkShell {
          packages = [
            criterion
            gcc12
            glibc
            gcovr
            ltrace
            gnumake
            python311Packages.compiledb
            xloadimage
            valgrind
          ];
        };
      });
}
