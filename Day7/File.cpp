#include <iostream>
#include "File.h"

File::File(std::string fileName, unsigned int fileSize) {
     this->fileName = fileName;
     this->fileSize = fileSize;
}

File::~File() {

}

void File::PrintFile(unsigned int depth) {
     for (unsigned int i = 0; i < depth; i++) {
          std::cout << "  ";
     }
     std::cout << "- " << fileName << "(file, " << fileSize << ")\n";
}