#ifndef FILE_H
#define FILE_H

#include <string>

class File {
public:
     std::string fileName;
     unsigned int fileSize;

     File(std::string, unsigned int);
     ~File();

     void PrintFile(unsigned int);
};
#endif