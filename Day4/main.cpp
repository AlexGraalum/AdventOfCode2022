#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

bool CompareTotalOverlap(std::pair<int, int>, std::pair<int, int>);
bool CompareAnyOverlap(std::pair<int, int>, std::pair<int, int>);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");

     int totalOverlapSum = 0;
     int anyOverlapSum = 0;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);
          s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());
          std::stringstream ss(s);
          std::vector<std::pair<int, int>> shiftPair;

          std::string temp;
          while (getline(ss, temp, ',')) {
               std::vector<int> v;
               std::stringstream tempSS(temp);

               std::string tempTemp;
               while (getline(tempSS, tempTemp, '-')) {
                    v.push_back(stoi(tempTemp));
               }

               shiftPair.push_back(std::make_pair(v[0], v[1]));
          }

          totalOverlapSum += CompareTotalOverlap(shiftPair[0], shiftPair[1]) ? 1 : 0;
          anyOverlapSum += CompareAnyOverlap(shiftPair[0], shiftPair[1]) ? 1 : 0;
     }
     std::cout << "Shifts With Total Overlap: " << totalOverlapSum << std::endl;
     std::cout << "Shifts With Any Overlap: " << anyOverlapSum << std::endl;
     return 0;
}

bool CompareTotalOverlap(std::pair<int, int> shiftOne, std::pair<int, int> shiftTwo) {
     if (shiftOne.first <= shiftTwo.first && shiftOne.second >= shiftTwo.second) return true;
     if (shiftTwo.first <= shiftOne.first && shiftTwo.second >= shiftOne.second) return true;
     return false;
}

bool CompareAnyOverlap(std::pair<int, int> shiftOne, std::pair<int, int> shiftTwo) {
     if (shiftOne.second < shiftTwo.first || shiftTwo.second < shiftOne.first) return false;
     if (shiftOne.first > shiftTwo.second || shiftTwo.first > shiftOne.second) return false;
     return true;
}