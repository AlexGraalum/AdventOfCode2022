#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Forest.h"

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;

     Forest* forest = nullptr;

     while (!inputFile.eof()) {
          getline(inputFile, s);
          if (forest == nullptr) forest = new Forest(s);
          forest->PushString(s);
     }

     forest->ProcessSightLines();
     //forest->PrintForest();

     std::cout << "There are " << forest->VisibleCount() << " trees visible\n\n";
     std::cout << "Highest Scenic Score: " << forest->ScenicScore() << "\n\n";

     return 0;
}