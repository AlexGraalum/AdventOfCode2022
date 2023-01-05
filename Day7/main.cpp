#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <regex>

#include "FolderSystem.h"

void ParseLine(std::string, FolderSystem*);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;

     FolderSystem* folderSys = new FolderSystem();

     while (!inputFile.eof()) {
          getline(inputFile, s);

          folderSys->ParseLine(s);
     }

     folderSys->PrintSystem();
     folderSys->PrintSystemSize();
     folderSys->PrintFirstHalf();
     folderSys->PrintSecondHalf();

     delete folderSys;
     return 0;
}
