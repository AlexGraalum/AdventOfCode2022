#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

#include "CrateSystem.h"

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::vector<std::string> boxStrings;
     std::vector<int[3]> commands;
     unsigned int stackCount = 0;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);

          if (s.substr(0, 2) == " 1") {
               std::stringstream ss(s);
               int tempInt;

               while (!ss.eof()) {
                    if (ss >> tempInt) {
                         stackCount = tempInt;
                    }
               }
               break;
          }
          else {
               boxStrings.push_back(s);
          }
     }

     CrateSystem* crateSys = new CrateSystem(stackCount, boxStrings);

     crateSys->PrintCrates();

     std::cout << "\n\n";

     std::string s;
     std::regex moveRule("([0-9]+)");
     std::vector<int> moves;
     moves.resize(3);
     while (!inputFile.eof()) {
          getline(inputFile, s);

          if (s.substr(0, 4) == "move") {
               for (std::sregex_iterator i = std::sregex_iterator(s.begin(), s.end(), moveRule);
                    i != std::sregex_iterator();
                    i++) {
                    std::smatch match = *i;
                    moves.push_back(stoi(match.str()));
               }

               crateSys->Move(moves[0], moves[1], moves[2]);
          }
          moves.clear();
     }

     crateSys->PrintCrates();
     std::cout << "\n\n";
     crateSys->PrintTopCrates();

     delete crateSys;
     return 0;
}