#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

bool SortValue(const std::pair<unsigned int, unsigned int>& a, const std::pair<unsigned int, unsigned int>& b) {
     return (a.second > b.second);
}

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");

     unsigned int calorieSum = 0;
     unsigned int elfIndex = 0;

     std::vector<std::pair<unsigned int, unsigned int> > calorieMap;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);

          if (s == "") {
               elfIndex++;
               calorieMap.push_back(std::make_pair(elfIndex, calorieSum));
               calorieSum = 0;
          }
          else {
               calorieSum += std::stoi(s);
          }
     }

     std::sort(calorieMap.begin(), calorieMap.end(), SortValue);

     calorieSum = 0;
     std::cout << "The top 3 Elfs with the highest calories are: \n";
     for (int i = 0; i < 3; i++) {
          std::cout << "Elf [" << calorieMap[i].first << "] has " << calorieMap[i].second << " calories\n";

          calorieSum += calorieMap[i].second;
     }

     std::cout << "The top 3 Elfs has a total of " << calorieSum << " calories\n";

     inputFile.close();
     return 0;
}