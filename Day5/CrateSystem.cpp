#include "CrateSystem.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>

CrateSystem::CrateSystem(std::string file) {
     std::ifstream inputFile(file);
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

     crates.resize(stackCount);

     unsigned int c;
     for (int i = boxStrings.size() - 1; i >= 0; i--) {
          std::regex fullBox("(([\\+[A-Z])|\\s{3})+\\s*");

          c = 0;
          for (std::sregex_iterator s = std::sregex_iterator(boxStrings[i].begin(), boxStrings[i].end(), fullBox);
               s != std::sregex_iterator();
               s++) {
               std::smatch match = *s;

               if (match.str()[1] != ' ') {
                    crates[c].push(match.str()[1]);
               }
               c++;
          }
     }

     this->PrintCrates();
}

CrateSystem::~CrateSystem() {
     crates.clear();
}

CrateSystem& CrateSystem::operator=(const CrateSystem& CS) {
     if (this == &CS) return *this;

     for (auto c : CS.crates) {
          this->crates.push_back(c);
     }

     return *this;
}

void CrateSystem::Run(std::string file) {
     CrateSystem copy = *this;

     std::ifstream inputFile(file);
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
     
               this->Move(moves[0], moves[1], moves[2], Mode::SINGLE);
               copy.Move(moves[0], moves[1], moves[2], Mode::MULTIPLE);
          }
          moves.clear();
     }

     std::cout << "FIRST SOLUTION CRATE STACK\n\n";
     this->PrintCrates();
     this->PrintTopCrates();

     std::cout << "\nSECOND SOLUTION CRATE STACK\n\n";
     copy.PrintCrates();
     copy.PrintTopCrates();
}

void CrateSystem::Move(int count, int from, int to, Mode mode) {

     if (mode == Mode::SINGLE) {
          for (int i = 0; i < count; i++) {
               crates[to - 1].push(crates[from-1].top());
               crates[from - 1].pop();
          }
     } else if(mode == Mode::MULTIPLE){
          std::vector<char> pull;
          for (int i = 0; i < count; i++) {
               pull.push_back(crates[from - 1].top());
               crates[from - 1].pop();
          }

          for (int i = 0; i < count; i++) {
               crates[to - 1].push(pull.back());
               pull.pop_back();
          }
     }
}

void CrateSystem::PrintCrates() {
     unsigned int height = 0;
     unsigned int i;
     int j;

     for (i = 0; i < crates.size(); i++) {
          if (crates[i].size() > height) height = crates[i].size();
     }

     std::vector<std::stack<char>> tempCrates = crates;

     for (j = (signed int)height - 1; j >= 0; j--) {

          for (int c = 0; c < tempCrates.size(); c++) {
               if (j < tempCrates[c].size()) {
                    std::cout << "[" << tempCrates[c].top() << "] ";
                    tempCrates[c].pop();
               }
               else {
                    std::cout << "    ";
               }
          }
          std::cout << std::endl;
     }
}

void CrateSystem::PrintTopCrates() {
     std::cout << "Top Crates: ";
     for (auto c : crates) {
          std::cout << c.top() << " ";
     }
     std::cout << std::endl;
}