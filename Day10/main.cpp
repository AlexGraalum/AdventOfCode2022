#include <iostream>
#include <fstream>
#include <string>
#include <queue>

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;
     std::queue<std::pair<int, int>> instructions;
     char CRT[6][40];

     for (int y = 0; y < 6; y++) {
          for (int x = 0; x < 40; x++) {
               CRT[y][x] = '.';
          }
     }

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

     while(!instructions.empty()){
          //Get Cycle Draw Positions
          int crtY = cycle / 40;
          int crtX = cycle - (crtY * 40);

          //Increment Cycle (Starts at 1 not 0)
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
          }

          //Draw Pixel
          if (registerX >= crtX - 1 && registerX <= crtX + 1) CRT[crtY][crtX] = '#';
     }

     std::cout << "\nSum of signal strengths: " << signalSum << "\n\n--CRT Output--\n";

     for (int y = 0; y < 6; y++) {
          for (int x = 0; x < 40; x++) {
               std::cout << CRT[y][x];
          }
          std::cout << std::endl;
     }

     return 0;
}