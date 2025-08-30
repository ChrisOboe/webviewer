{
  pkgs,
  cmake,
  ninja,
  kdePackages,
}:
pkgs.stdenv.mkDerivation {
  name = "webviewer";
  nativeBuildInputs = [
    cmake
    ninja
    kdePackages.wrapQtAppsHook
  ];
  buildInputs = [
    kdePackages.qtbase
    kdePackages.qtwebengine
    kdePackages.qtwayland
  ];
  src = ./src;
}
