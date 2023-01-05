#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

int CommonItem(std::string);
int GetPriority(char);
int GroupPriorities(std::vector<std::string>);
int CompareRucksacks(std::string, std::string, std::string);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::vector<std::string> rucksacks;

     int prioritySum = 0;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);
          s.erase(std::remove(s.begin(), s.end(), '\n'), s.end());

          rucksacks.push_back(s);

          prioritySum += CommonItem(s);
     }

     std::cout << "Sum of Individual Priorities: " << prioritySum << std::endl;
     std::cout << "Sum of Group Priorities: " << GroupPriorities(rucksacks) << std::endl;

     return 0;
}

int CommonItem(std::string rucksack) {
     std::string compartmentOne = rucksack.substr(0, rucksack.length() / 2);
     std::string compartmentTwo = rucksack.substr(compartmentOne.length(), rucksack.length() - 1);

     //std::cout << "Compartment One: " << compartmentOne << "\tCompartment Two: " << compartmentTwo << std::endl;

     for (unsigned int i = 0; i < compartmentOne.length(); i++) {
          for (unsigned int j = 0; j < compartmentTwo.length(); j++) {
               if (compartmentOne[i] == compartmentTwo[j]) {
                    int priority = GetPriority(compartmentOne[i]);

                    //std::cout << "Matching cargo : " << compartmentOne[i] << "\tPriority: " << priority << std::endl;

                    return priority;
               }
          }
     }
     std::cout << "No matching cargo.\n";
     return 0;
}

int GroupPriorities(std::vector<std::string> rucksacks) {
     int sum = 0;

     for (unsigned int i = 0; i < rucksacks.size(); i += 3) {
          sum += CompareRucksacks(rucksacks[i], rucksacks[i + 1], rucksacks[i + 2]);
     }

     return sum;
}

int CompareRucksacks(std::string rucksackOne, std::string rucksackTwo, std::string rucksackThree) {
     for (unsigned int a = 0; a < rucksackOne.length(); a++) {
          char one = rucksackOne[a];
          for (unsigned int b = 0; b < rucksackTwo.length(); b++) {
               char two = rucksackTwo[b];
               for (unsigned int c = 0; c < rucksackThree.length(); c++) {
                    char three = rucksackThree[c];

                    if (one == two && two == three) {
                         return GetPriority(one);
                    }
               }
          }
     }

     return 0;
}

int GetPriority(char item) {
     int priority = item;

     if (islower(item)) {
          priority -= 96;
     }
     else {
          priority -= 38;
     }

     return priority;
}