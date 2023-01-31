#include "MonkeyBusiness.h"

#include <iostream>
#include <fstream>

MonkeyBusiness::MonkeyBusiness(std::string filename) {
     std::ifstream inputFile(filename);
     std::vector<std::string> inputBuffer;

     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);

          if (s == "") {
               monkeys.push_back(new Monkey(inputBuffer));
               inputBuffer.clear();
          }
          else {
               inputBuffer.push_back(s);
          }
     }
     monkeys.push_back(new Monkey(inputBuffer));
     inputBuffer.clear();
     
     modulo = 1;
     for (Monkey* m : monkeys) {
          modulo *= m->GetTest();
     }
}

void MonkeyBusiness::Run(unsigned int rounds, int relief, int modulo) {
     //For Each Round
     for (unsigned int r = 0; r < rounds; r++) {
          //For Each Monkey
          for (unsigned int m = 0; m < monkeys.size(); m++) {
               //Inspect and Throw
               monkeys[m]->InspectItems(monkeys, relief, modulo);
          }
     }

     CalculateMonkeyBusiness(monkeys);
}

void MonkeyBusiness::CalculateMonkeyBusiness(std::vector<Monkey*> monkeys) {
     //Get and Sort Inspection Counts
     std::vector<int> counts;
     for (Monkey* m : monkeys) {
          std::cout << "Monkey " << m->GetID() << " inspected items " << m->GetInspectionCount() << " times\n";
          counts.push_back(m->GetInspectionCount());
     }
     std::sort(counts.begin(), counts.end());

     //Print Results
     std::cout << "The first highest inspection count was " << counts[counts.size() - 1] << std::endl;
     std::cout << "The second highest inspection count was " << counts[counts.size() - 2] << std::endl;
     std::cout << "The level of monkey business is: " << (uint64_t)((uint64_t)counts[counts.size() - 1] * (uint64_t)counts[counts.size() - 2]) << "\n\n";
}

void MonkeyBusiness::PrintMonkeys() {
     for (Monkey* m : monkeys) {
          m->PrintMonkey();
     }
}