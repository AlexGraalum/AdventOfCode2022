#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>

int GetFirstScore(char, char);
int GetSecondScore(char, char);
int GetPlayScore(char);
int GetDrawScore(char, char);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     int firstScoreSum = 0;
     int secondScoreSum = 0;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);
          std::stringstream ss(s);

          char opponent, player;
          ss >> opponent >> player;

          firstScoreSum += GetFirstScore(opponent, player);
          secondScoreSum += GetSecondScore(opponent, player);
     }
     std::cout << "First Final Score: " << firstScoreSum << "\tSecond Final Score: " << secondScoreSum << std::endl;
     return 0;
}

int GetFirstScore(char opponent, char player) {
     int score = 0;

     score += GetPlayScore(player);
     score += GetDrawScore(opponent, player);

     return score;
}

int GetSecondScore(char opponent, char round) {
     int score = 0;
     char player;

     switch (round) {
     case 'X':
          if (opponent == 'A') {
               player = 'Z';
          }
          else if (opponent == 'B') {
               player = 'X';
          }
          else {
               player = 'Y';
          }
          break;
     case 'Y':
          if (opponent == 'A') {
               player = 'X';
          }
          else if (opponent == 'B') {
               player = 'Y';
          }
          else {
               player = 'Z';
          }
          break;
     default:
          if (opponent == 'A') {
               player = 'Y';
          }
          else if (opponent == 'B') {
               player = 'Z';
          }
          else {
               player = 'X';
          }
          break;
     }


     score += GetPlayScore(player);
     score += GetDrawScore(opponent, player);
     return score;
}

int GetPlayScore(char player) {
     if (player == 'X') {
          return 1;
     }
     if (player == 'Y') {
          return 2;
     }
     return 3;
}

int GetDrawScore(char opponent, char player) {
     //Draw
     //Rock & Rock
     //Paper & Paper
     //Scissors & Scissors
     if ((player == 'X' && opponent == 'A') ||
          (player == 'Y' && opponent == 'B') ||
          (player == 'Z' && opponent == 'C')) {
          return 3;
     }
     //Win
     //Rock & Scissors
     //Paper & Rock
     //Scissors & Paper
     if ((player == 'X' && opponent == 'C') ||
          (player == 'Y' && opponent == 'A') ||
          (player == 'Z' && opponent == 'B')) {
          return 6;
     }
     //Lose
     //Rock & Paper
     //Paper & Scissors
     //Scissors & Rock
     return 0;
}