#include "Forest.h"

#include <iostream>
#include <string>

Forest::Forest(std::string s) {
     forestWidth = s.length();
     forestHeight = 0;
}

Forest::~Forest() {

}

void Forest::PushString(std::string line) {
     std::vector<std::pair<int, std::pair<bool, int>>> treeRow;
     for (unsigned int c = 0; c < line.length(); c++) {
          treeRow.push_back(std::make_pair(line[c] - '0', std::make_pair(true, 0)));
     }
     forest.push_back(treeRow);
     forestHeight++;
}

void Forest::PrintForest() {
     for (unsigned int y = 0; y < forestHeight; y++) {
          for (unsigned int x = 0; x < forestHeight; x++) {
               std::cout << forest[y][x].first;
          }
          std::cout << std::endl;
     }

     std::cout << "\nForest Height: " << forestHeight << "\tForest Width: " << forestWidth << std::endl;
}

void Forest::ProcessSightLines() {
     for (unsigned int y = 1; y < forestHeight - 1; y++) {
          for (unsigned int x = 1; x < forestWidth - 1; x++) {
               forest[y][x].second = CheckSight(forest[y][x].first, x, y);
          }
     }
}

std::pair<bool, int> Forest::CheckSight(int height, unsigned int x, unsigned int y) {
     bool u = true, d = true, l = true, r = true;
     unsigned int su = 0, sd = 0, sl = 0, sr = 0;

     //std::cout << "DEBUG\tTree X: " << x << "\tY: " << y << std::endl;

     ////Check
     //Up
     int yUp = y - 1;
     while (yUp >= 0 && u) {
          if (forest[yUp][x].first >= height) {
               u = false;
          }
          else {
               yUp--;
          }
     }
     su = u ? y : y - yUp;

     //Left
     int xLeft = x - 1;
     while (xLeft >= 0 && l) {
          if (forest[y][xLeft].first >= height) {
               l = false;
          }
          else {
               xLeft--;
          }
     }
     sl = l ? x : x - xLeft;

     //Right
     unsigned int xRight = x + 1;
     while (xRight < forestWidth && r) {
          if (forest[y][xRight].first >= height) {
               r = false;
          }
          else {
               xRight++;
          }
     }
     sr = r ? forestWidth - 1 - x : xRight - x;

     //Down
     unsigned int yDown = y + 1;
     while (yDown < forestHeight && d) {
          if (forest[yDown][x].first >= height) {
               d = false;
          }
          else {
               yDown++;
          }
     }
     sd = d ? forestHeight - 1 - y : yDown - y;

     int score = su * sd * sl * sr;

     //std::cout << "\tsu: " << su << "\tsl: " << sl << "\tsr: " << sr << "\tsd: " << sd << "\n";
     //std::cout << "Scenic Score: " << score << "\n\n";

     return std::make_pair((u || d || l || r), (su * sl * sr * sd));
}

int Forest::VisibleCount() {
     int sum = 0;
     for (unsigned int y = 0; y < forest.size(); y++) {
          for (unsigned int x = 0; x < forest.size(); x++) {
               if (forest[y][x].second.first) sum++;
          }
     }
     return sum;
}

int Forest::ScenicScore() {
     int score = 0;
     for (unsigned int y = 1; y < forest.size() - 1; y++) {
          for (unsigned int x = 1; x < forest.size() - 1; x++) {
               if (forest[y][x].second.second > score) score = forest[y][x].second.second;
          }
     }
     return score;
}