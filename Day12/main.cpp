#include "HillMap.h"

#include <iostream>

int main(int argc, char** argv) {
     HillMap* hillMap = new HillMap("input.txt");

     hillMap->PrintHillMap();
     std::cout << "\nFinding Path\n\n";
     hillMap->FindPath();
     hillMap->PrintPathMap();

     delete hillMap;
     return 0;
}