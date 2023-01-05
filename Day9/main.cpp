#include <iostream>
#include <fstream>
#include <string>

#include "Rope.h"

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;

     Rope* rope = new Rope();

     //rope->PrintStart();

     while (!inputFile.eof()) {
          getline(inputFile, s);
          rope->Move(s.c_str()[0], stoi(s.substr(2)));
     }

     //rope->PrintEnd();
     rope->GetVisitedCount();

     delete rope;
     return 0;
}