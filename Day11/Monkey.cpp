#pragma once
#include <iostream>
#include <regex>
#include "Monkey.h"

Monkey::Monkey(std::vector<std::string> inputBuffer) {
     std::cmatch c;
     std::regex re("[0-9]+");

     //Get ID
     std::regex_search(inputBuffer[0].c_str(), c, re);
     this->monkeyID = stoi(c[0]);

     //Get Items
     std::string items = inputBuffer[1].substr(inputBuffer[1].find(": ") + 2);
     for (std::sregex_iterator s = std::sregex_iterator(items.begin(), items.end(), re);
          s != std::sregex_iterator();
          s++) {
          this->items.push_back(stoi((*s).str()));
     }

     //Get Operation Type and Value
     this->operationType = OperationType::ADD;
     this->operationValue = 0;
     std::regex_search(inputBuffer[2].c_str(), c, (std::regex)"([*|+])\\s+([0-9]+|[o][l][d])");
     if (c[1] == "*") {
          if (c[2] == "old") {
               this->operationType = OperationType::SQUARE;
          } else {
               this->operationType = OperationType::MULTIPLY;
               this->operationValue = stoi(c[2]);
          }
     } else if (c[1] == "+") {
          if (c[2] == "old") {
               this->operationType = OperationType::MULTIPLY;
               this->operationValue = 2;
          } else {
               this->operationType = OperationType::ADD;
               this->operationValue = stoi(c[2]);
          }
     }

     //Get Test Value
     std::regex_search(inputBuffer[3].c_str(), c, (std::regex)"([0-9]+)");
     this->test = stoi(c[1]);

     //Get True
     std::regex_search(inputBuffer[4].c_str(), c, (std::regex)"([0-9]+)");
     this->trueMonkey = stoi(c[1]);

     //Get False
     std::regex_search(inputBuffer[5].c_str(), c, (std::regex)"([0-9]+)");
     this->falseMonkey = stoi(c[1]);

     //Set Inspection Count
     this->inspectionCount = 0;
}

void Monkey::InspectItems(std::vector<Monkey*> monkeys, unsigned int relief, int modulo) {
     //Inspect Each Item
     while (!this->GetItems().empty()) {
          //Get Value and Pop Item
          int64_t itemValue = this->GetFront();
          this->PopItem();

          //Calculate Worry
          itemValue = (int64_t)(this->Operate(itemValue)/relief);
          if (modulo != 0) itemValue %= modulo;

          //Increment Inspection Count
          this->IncrementInspectionCount();

          //Throw Item
          monkeys[this->GetThrowID(itemValue)]->PushItem(itemValue);
     }
}

int64_t Monkey::Operate(int64_t itemValue) {
     switch (this->GetOperationType()) {
     case OperationType::ADD:
          itemValue += this->GetOperationValue();
          break;
     case OperationType::MULTIPLY:
          itemValue *= this->GetOperationValue();
          break;
     case OperationType::SQUARE:
          itemValue *= itemValue;
          break;
     }
     return itemValue;
}

int Monkey::GetThrowID(uint64_t itemValue) {
     if (itemValue % this->GetTest() == 0) {
          return this->GetTrueMonkey();
     }
     return this->GetFalseMonkey();
}

void Monkey::PrintMonkey() {
     //Print ID
     std::cout << "Monkey " << this->monkeyID << std::endl;

     //Print Items
     std::cout << "  Items: ";
     std::deque<int64_t> itemsCopy = this->items;
     while (!itemsCopy.empty()) {
          std::cout << itemsCopy.front();
          if (itemsCopy.size() > 1) std::cout << ", ";
          itemsCopy.pop_front();
     }
     std::cout << std::endl;
     
     //Print Operation
     std::cout << "  Operation: old";
     switch (this->operationType) {
     case OperationType::ADD:
          std::cout << " + " << this->operationValue;
          break;
     case OperationType::MULTIPLY:
          std::cout << " * " << this->operationValue;
          break;
     case OperationType::SQUARE:
          std::cout << "^2";
          break;
     }

     //Print Test
     std::cout << "\n  Test: " << this->test << std::endl;

     //Print True
     std::cout << "    True: " << this->trueMonkey << std::endl;
     //Print False
     std::cout << "    False: " << this->falseMonkey << std::endl;

     std::cout << "\n";
}

void Monkey::PrintMonkeyItems() {
     std::cout << "Monkey " << this->monkeyID << ": ";

     std::deque<int64_t> itemsCopy = this->items;
     while (!itemsCopy.empty()) {
          std::cout << itemsCopy.front();
          if (itemsCopy.size() > 1) std::cout << ", ";
          itemsCopy.pop_front();
     }

     std::cout << std::endl;
}