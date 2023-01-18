#pragma once
#ifndef MONKEY_H
#define MONKEY_H
#include <queue>
#include <string>
enum class OperationType {ADD, MULTIPLY, SQUARE};

class Monkey {
private:
     int monkeyID;
     std::queue<int> items;
     OperationType operationType;
     int operationValue;
     int test;
     int trueMonkey;
     int falseMonkey;

     int inspectionCount;

public:
     Monkey(std::vector<std::string> inputBuffer);
     ~Monkey();

     void SetID(int ID) { this->monkeyID = ID; }
     int GetID() { return this->monkeyID; }
     
     void SetItems(std::queue<int> items) { this->items = items; }
     std::queue<int> GetItems() { return this->items; }
     void PushItem(int value) { this->items.push(value); }
     void PopItem() { this->items.pop(); }
     int GetFront() { return this->items.front(); }
     
     void SetOperationType(OperationType operationType) { this->operationType = operationType; }
     OperationType GetOperationType() { return this->operationType; }

     void SetOperationValue(int value) { this->operationValue = value; }
     int GetOperationValue() { return this->operationValue; }

     void SetTest(int test) { this->test = test; }
     int GetTest() { return this->test; }

     void SetTrueMonkey(int monkeyID) { this->trueMonkey = monkeyID; }
     int GetTrueMonkey() { return this->trueMonkey; }

     void SetFalseMonkey(int monkeyID) { this->falseMonkey = monkeyID; }
     int GetFalseMonkey() { return this->falseMonkey; }

     void SetInspectionCount(int inspectionCount) { this->inspectionCount = inspectionCount; }
     int GetInspectionCount() { return this->inspectionCount; }

     void PrintMonkey();
     void PrintMonkeyItems();
};
#endif