{
  pkgs,
  cmake,
  ninja,
  qt5,
}:
pkgs.stdenv.mkDerivation {
  name = "webviewer";
  nativeBuildInputs = [cmake ninja qt5.wrapQtAppsHook];
  buildInputs = [qt5.qtbase qt5.qtwebview qt5.qtwayland];
  src = ./src;
}
