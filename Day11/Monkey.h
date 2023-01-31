#pragma once
#ifndef MONKEY_H
#define MONKEY_H
#include <queue>
#include <string>
enum class OperationType {ADD, MULTIPLY, SQUARE};

class Monkey {
private:
     int monkeyID;

     std::deque<int64_t> items;

     OperationType operationType;
     unsigned int operationValue;

     int test;
     int trueMonkey;
     int falseMonkey;

     int inspectionCount;

public:
     Monkey(std::vector<std::string> inputBuffer);

     void InspectItems(std::vector<Monkey*> monkeys, unsigned int relief, int modulo);

     int64_t Operate(int64_t);

     int GetThrowID(uint64_t itemValue);

     void PrintMonkey();
     void PrintMonkeyItems();

     void SetID(int ID) { this->monkeyID = ID; }
     int GetID() { return this->monkeyID; }
     
     void SetItems(std::deque<int64_t> items) { this->items = items; }
     std::deque<int64_t> GetItems() { return this->items; }
     void PushItem(int64_t value) { this->items.push_back(value); }
     void PopItem() { this->items.pop_front(); }
     int64_t GetFront() { return this->items.front(); }
     
     void SetOperationType(OperationType operationType) { this->operationType = operationType; }
     OperationType GetOperationType() { return this->operationType; }

     void SetOperationValue(unsigned int value) { this->operationValue = value; }
     unsigned int GetOperationValue() { return this->operationValue; }

     void SetTest(int test) { this->test = test; }
     int GetTest() { return this->test; }

     void SetTrueMonkey(int monkeyID) { this->trueMonkey = monkeyID; }
     int GetTrueMonkey() { return this->trueMonkey; }

     void SetFalseMonkey(int monkeyID) { this->falseMonkey = monkeyID; }
     int GetFalseMonkey() { return this->falseMonkey; }

     void SetInspectionCount(int inspectionCount) { this->inspectionCount = inspectionCount; }
     int GetInspectionCount() { return this->inspectionCount; }
     void IncrementInspectionCount() { this->inspectionCount++; }
};
#endif