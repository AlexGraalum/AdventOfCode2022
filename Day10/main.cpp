#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;
     std::queue<std::pair<int, int>> instructions;

     //Prepare Input
     while (!inputFile.eof()) {
          //Read Line
          getline(inputFile, s);
          std::string command = s.substr(0, s.find(' '));

          //Push Command
          if (command == "noop") {
               instructions.push(std::make_pair(0, 1));
          } else if(command == "addx") {
               instructions.push(std::make_pair(stoi(s.substr(s.find(' '))), 2));
          }
     }

     int cycle = 0;
     int registerX = 1;
     int signalSum = 0;
     std::vector<int> values;
     do{
          cycle++;

          //Check Execution
          if (instructions.front().second == 0) {
               registerX += instructions.front().first;
               instructions.pop();
          }

          //Tick Top Instruction
          if(!instructions.empty()) --instructions.front().second;

          //Check Cycle
          if ((cycle - 20) % 40 == 0) {
               int signal = cycle * registerX;
               signalSum += signal;

               std::cout << "Cycle " << cycle << "\t-- X: " << registerX << "\t-- Signal Strength: " << signal << std::endl;
          }
     } while (!instructions.empty());

     std::cout << "Sum of signal strengths: " << signalSum << std::endl;
     return 0;
}