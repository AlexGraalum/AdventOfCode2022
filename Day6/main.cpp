#include <iostream>
#include <string>
#include <fstream>

bool AnalyzeSubString(std::string);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::string s;
     getline(inputFile, s);

     bool four = false, fourteen = false;

     for (int c = 0; c < s.length() - 3; c++) {
          if ((four == false) && (AnalyzeSubString(s.substr(c, 4)) == true)) {
               std::cout << "\nFour Character Packet Marker Located After Character " << c + 4 << "\n";
               four = true;
          }
          if ((fourteen == false) && (AnalyzeSubString(s.substr(c, 14)) == true)) {
               std::cout << "\nFourteen Character Packet Marker Located After Character " << c + 14 << "\n";
               fourteen = true;
          }

          if (four && fourteen) return 0;
     }
     return 0;
}

bool AnalyzeSubString(std::string s) {
     for (int i = 0; i < s.length() - 1; i++) {
          for (int j = i + 1; j < s.length(); j++) {
               if ((char)s[i] == (char)s[j]) return false;
          }
     }
     return true;
}