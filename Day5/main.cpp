#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <vector>
#include <regex>

#include "CrateSystem.h"

int main(int argc, char** argv) {
     CrateSystem* crateSys = new CrateSystem("input.txt");

     crateSys->Run("input.txt");

     delete crateSys;
     return 0;
}