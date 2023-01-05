#ifndef FOLDER_SYSTEM_H
#define FOLDER_SYSTEM_H

#include <vector>
#include "Folder.h"

class FolderSystem {
public:
     Folder* root;
     Folder* currFolder;

     FolderSystem();
     ~FolderSystem();

     void ParseLine(std::string);

     void PrintSystem();

     void PrintSystemSize();
     void PrintFirstHalf();
     void PrintSecondHalf();
};
#endif