#include "Folder.h"
#include <iostream>

Folder::Folder(std::string folderName) {
     this->folderName = folderName;
}

Folder::~Folder() {
     for (auto f : folders) {
          delete f;
     }
     for (auto f : files) {
          delete f;
     }
}

void Folder::AddFolder(std::string folderName) {
     folders.push_back(new Folder(folderName));
}

Folder* Folder::DescendFolder(std::string searchName) {
     for (auto f : folders) {
          if (f->folderName == searchName) return f;
     }
     exit(-1);
}

Folder* Folder::RecursivelyContainsFolder(Folder* folder) {
     for (auto f : folders) {
          if (f == folder) return this;

          Folder* folderSearch = f->RecursivelyContainsFolder(folder);
          if (folderSearch) return folderSearch;
     }
     return nullptr;
}

void Folder::AddFile(std::string fileName, unsigned int fileSize) {
     files.push_back(new File(fileName, fileSize));
}

void Folder::PrintFolder(unsigned int depth) {
     for (unsigned int i = 0; i < depth; i++) {
          std::cout << "  ";
     }
     std::cout << "- " << folderName << " (dir)\n";
     for (auto f : folders) {
          f->PrintFolder(depth + 1);
     }
     for (auto f : files) {
          f->PrintFile(depth + 1);
     }
}

unsigned int Folder::GetFolderSize() {
     unsigned int sum = 0;

     for (auto f : folders) {
          sum += f->GetFolderSize();
     }
     for (auto f : files) {
          sum += f->fileSize;
     }

     return sum;
}

unsigned int Folder::GetFirstHalf() {
     unsigned int sum = 0;

     unsigned int s = this->GetFolderSize();
     if (s <= 100000) sum += s;

     for (auto f : folders) {
          sum += f->GetFirstHalf();
     }

     return sum;
}

unsigned int Folder::GetSecondHalf(unsigned int requiredSpace) {
     unsigned int s;
     for (auto f : folders) {
          s = f->GetSecondHalf(requiredSpace);
          if (s >= requiredSpace) return s;
     }

     return GetFolderSize();
}