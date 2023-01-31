#include "HillMap.h"

#include <fstream>
#include <iostream>

HillMap::HillMap(std::string file) {
     std::ifstream inputFile(file);
     std::string s;

     while (!inputFile.eof()) {
          getline(inputFile, s);

          std::vector<MapPoint> mapRow;
          for (auto& c : s) {
               MapPoint point;
               point.c = c;
               point.h = c == 'S' ? 'a' - 97 : c == 'E' ? 'z' - 97 : c - 97;
               point.d = Direction::NONE;

               mapRow.push_back(point);
          }
          hillMap.push_back(mapRow);
     }

     for (unsigned int y = 0; y < hillMap.size(); y++) {
          for (unsigned int x = 0; x < hillMap.size(); x++) {
               if (hillMap[y][x].c == 'S') {
                    start[0] = x;
                    start[1] = y;
               }

               if (hillMap[y][x].c == 'E') {
                    end[0] = x;
                    end[1] = y;
               }
          }
     }
}

HillMap::~HillMap() {
     for (auto h : hillMap) {
          h.clear();
     }
     hillMap.clear();
}

void HillMap::PrintHillMap() {
     for (auto h : hillMap) {
          for (const auto& p : h) {
               std::cout << p.c;
          }
          std::cout << std::endl;
     }
}

void HillMap::FindPath() {

}

void HillMap::PrintPathMap() {
     int pathLength = 0;
     for (auto h : hillMap) {
          for (const auto& p : h) {
               switch (p.d) {
               case Direction::NONE:
                    std::cout << ".";
                    //std::cout << p.c;
                    break;
               case Direction::UP:
                    std::cout << "^";
                    pathLength++;
                    break;
               case Direction::DOWN:
                    std::cout << "v";
                    pathLength++;
                    break;
               case Direction::LEFT:
                    std::cout << "<";
                    pathLength++;
                    break;
               case Direction::RIGHT:
                    std::cout << ">";
                    pathLength++;
                    break;
               }
          }
          std::cout << std::endl;
     }
     std::cout << "\nPath Length: " << pathLength << std::endl;
}