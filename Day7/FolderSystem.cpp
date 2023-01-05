#include <iostream>
#include <regex>

#include "Foldersystem.h"

FolderSystem::FolderSystem() {
     this->root = new Folder("/");
     this->currFolder = this->root;
}

FolderSystem::~FolderSystem() {
     delete root;
}

void FolderSystem::ParseLine(std::string s) {
     std::smatch match;
     if (std::regex_match(s, match, (std::regex)"([$][ ][c][d][ ])([a-zA-Z0-9]+|[\/]|[.]+)")) {

          if (match.str(2) == "/") {
               //Return to Root
               currFolder = root;
          }
          else if (match.str(2) == "..") {
               //Ascend Folder
               currFolder = root->RecursivelyContainsFolder(currFolder);
          }
          else {
               //Descend Folder
               currFolder = currFolder->DescendFolder(match.str(2));
          }
          return;
     }

     if (std::regex_match(s, match, (std::regex)"([d][i][r][ ])([a-zA-Z0-9]+)")) {
          currFolder->AddFolder(match.str(2));
          return;
     }

     if (std::regex_match(s, match, (std::regex)"([0-9]+)([ ])([a-zA-Z0-9.]+)")) {
          currFolder->AddFile(match.str(3), stoul(match.str(1)));
     }
}

void FolderSystem::PrintSystem() {
     currFolder = root;
     root->PrintFolder(0);
     std::cout << std::endl;
}

void FolderSystem::PrintSystemSize() {
     std::cout << "System Size: " << root->GetFolderSize() << "\n\n";
}

void FolderSystem::PrintFirstHalf() {
     std::cout << "First Answer: " << root->GetFirstHalf() << "\n\n";
}

void FolderSystem::PrintSecondHalf() {
     unsigned int reqSize = 30000000 - (70000000 - root->GetFolderSize());
     std::cout << "Looking to free " << reqSize << " disk space\n";
     std::cout << "Second Answer: " << root->GetSecondHalf(reqSize) << "\n\n";
}