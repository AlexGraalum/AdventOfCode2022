#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#include "Monkey.h"

void Run(std::vector<Monkey*> monkeys);

int main(int argc, char** argv) {
     std::ifstream inputFile("input.txt");
     std::vector<std::string> inputBuffer;
     std::vector<Monkey*> monkeys;
     
     while (!inputFile.eof()) {
          std::string s;
          getline(inputFile, s);

          if (s == "") {
               monkeys.push_back(new Monkey(inputBuffer));
               inputBuffer.clear();
          } else {
               inputBuffer.push_back(s);
          }
     }
     monkeys.push_back(new Monkey(inputBuffer));
     inputBuffer.clear();

     for (auto m : monkeys) {
          m->PrintMonkey();
     }

     Run(monkeys);

     std::vector<int> counts;
     for (auto m : monkeys) {
          std::cout << "Monkey " << m->GetID() << " inspected items " << m->GetInspectionCount() << " times\n";
          counts.push_back(m->GetInspectionCount());
     }
     std::sort(counts.begin(), counts.end());
     std::cout << "The first highest inspection count was " << counts[counts.size() - 1] << std::endl;
     std::cout << "The second highest inspection count was " << counts[counts.size() - 2] << std::endl;
     std::cout << "The level of monkey business is: " << (counts[counts.size() - 1] * counts[counts.size() - 2]) << std::endl;

     monkeys.clear();
     return 0;
}

void Run(std::vector<Monkey*> monkeys) {
     for (int r = 0; r < 20; r++) {
          //For Each Monkey
          for (int m = 0; m < monkeys.size(); m++) {
               std::cout << "Monkey " << m << ":\n";
               OperationType opType = monkeys[m]->GetOperationType();

               //Inspect Each Item
               while (!monkeys[m]->GetItems().empty()) {
                    int itemValue = monkeys[m]->GetFront();
                    monkeys[m]->PopItem();

                    std::cout << "  Monkey inspects an item with worry level of " << itemValue << std::endl;

                    //Increase Worry
                    std::cout << "    Worry level ";
                    switch (opType) {
                    case OperationType::ADD:
                         std::cout << "increases by " << monkeys[m]->GetOperationValue();
                         itemValue += monkeys[m]->GetOperationValue();
                         break;
                    case OperationType::MULTIPLY:
                         std::cout << "is multiplied by " << monkeys[m]->GetOperationValue();
                         itemValue *= monkeys[m]->GetOperationValue();
                         break;
                    case OperationType::SQUARE:
                         std::cout << "is multiplied by " << itemValue;
                         itemValue *= itemValue;
                         break;
                    }
                    std::cout << " to " << itemValue << std::endl;

                    //Divide Worry
                    itemValue /= 3;
                    std::cout << "    Monkey gets bored with item. Worry level is divided by 3 to " << itemValue << std::endl;

                    //Test Worry
                    bool test = itemValue % monkeys[m]->GetTest() == 0;
                    std::cout << "    Current worry level is " << (test ? "" : "not ") << "divisible by " << monkeys[m]->GetTest() << std::endl;

                    //Throw Item
                    monkeys[(test ? monkeys[m]->GetTrueMonkey() : monkeys[m]->GetFalseMonkey())]->PushItem(itemValue);
                    monkeys[m]->SetInspectionCount(monkeys[m]->GetInspectionCount() + 1);
               }
          }

          std::cout << "Round " << r + 1 << std::endl;
          for (auto m : monkeys) {
               m->PrintMonkeyItems();
          }
     }
}