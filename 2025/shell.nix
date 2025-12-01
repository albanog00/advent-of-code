{
  pkgs ? import <nixpkgs> { },
}:
pkgs.mkShell {
  packages = with pkgs; [
    gccNGPackages_15.libstdcxx
    gcc
  ];
}
