#ifndef FOLDER_H
#define FOLDER_H

#include <string>
#include <vector>

#include "File.h"

class Folder {
public:
     std::string folderName;

     std::vector<Folder*> folders;
     std::vector<File*> files;

     Folder(std::string);
     ~Folder();

     void AddFolder(std::string);
     void AddFile(std::string, unsigned int);

     Folder* DescendFolder(std::string);
     Folder* RecursivelyContainsFolder(Folder*);

     void PrintFolder(unsigned int);

     unsigned int GetFolderSize();
     unsigned int GetFirstHalf();
     unsigned int GetSecondHalf(unsigned int);
};
#endif FOLDER_H