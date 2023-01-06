#include <iostream>
#include <fstream>
#include <string>

#include "Rope.h"

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;

     Rope* firstRope = new Rope(2);
     Rope* secondRope = new Rope(10);


     while (!inputFile.eof()) {
          getline(inputFile, s);
          char dir = s.c_str()[0];
          int count = stoi(s.substr(2));

          firstRope->Move(dir, count);
          secondRope->Move(dir, count);
     }

     std::cout << "\nFirst Solution: \n";
     firstRope->GetVisitedCount();
     std::cout << "\nSecond Solution: \n";
     secondRope->GetVisitedCount();

     delete firstRope;
     return 0;
}