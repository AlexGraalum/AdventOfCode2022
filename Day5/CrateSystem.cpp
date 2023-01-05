#include "CrateSystem.h"
#include <iostream>
#include <regex>

CrateSystem::CrateSystem(int stackCount, std::vector<std::string> input) {
     crates.resize(stackCount);

     unsigned int c;
     for (int i = input.size() - 1; i >= 0; i--) {
          std::regex fullBox("(([\\+[A-Z])|\\s{3})+\\s*");

          c = 0;
          for (std::sregex_iterator s = std::sregex_iterator(input[i].begin(), input[i].end(), fullBox);
               s != std::sregex_iterator();
               s++) {
               std::smatch match = *s;

               if (match.str()[1] != ' ') {
                    crates[c].push(match.str()[1]);
               }
               c++;
          }
     }
}

CrateSystem::~CrateSystem() {
     crates.clear();
}

void CrateSystem::Move(int count, int from, int to) {
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