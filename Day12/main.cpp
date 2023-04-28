#include "HillMap.h"

#include <iostream>
#include <cwchar>
#include <windows.h>

int main(int argc, char** argv) {
     HANDLE stdOutHandle = GetStdHandle(STD_OUTPUT_HANDLE);

     CONSOLE_FONT_INFOEX cfi;
     cfi.cbSize = sizeof(cfi);
     cfi.nFont = 0;
     cfi.dwFontSize.X = 0;
     cfi.dwFontSize.Y = 14;
     cfi.FontFamily = FF_DONTCARE;
     cfi.FontWeight = FW_NORMAL;
     wcscpy_s(cfi.FaceName, L"Consolas");

     SetCurrentConsoleFontEx(stdOutHandle, FALSE, &cfi);

     HillMap* hillMap = new HillMap("input.txt");
     hillMap->FindPath();
     hillMap->PrintMaps();

     hillMap->PrintEdges();

     //hillMap->PrintHillMap();
     //std::cout << "\n";
     //hillMap->PrintHillHeightMap();
     std::cout << "\n";
     //hillMap->PrintPathMap();
     //std::cout << "\n";
     //hillMap->FindPath();

     hillMap->PrintAdjMat();


     delete hillMap;
     return 0;
}