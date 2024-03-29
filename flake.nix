{
  description = "crafting interpreters dev env";
  inputs = { nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable"; };
  outputs = { self, nixpkgs }:
    let
      supportedSystems = [ "x86_64-linux" "x86_64-darwin" ];
      forAllSystems = f:
        nixpkgs.lib.genAttrs supportedSystems (system: f system);
      nixpkgsFor = forAllSystems (system:
        import nixpkgs {
          inherit system;
          overlays = [ self.overlay ];
        });
    in {
      overlay = final: prev: { };
      devShell = forAllSystems (system:
        let pkgs = nixpkgsFor.${system};
        in pkgs.mkShell {
          buildInputs = with pkgs; [
            gcc # compiler, gnu cc
            gdb # debugger
            gnumake # build
            cmake # cmake, cross-platform make generator
            # pkg-config
            # m4
            # libtool
            # build
            clang-tools # formatter
            ccls # language server
            # automake
            # autoconf
            # checkmake
            # clang # formatter
            # valgrind # memory debugging
            # cbmc # bounded model checker
            # afl # fuzzing
          ];
          shellHook = ''
            set -a
            set +a
          '';
        });
    };
}
