#pragma once
#ifndef CRATE_SYSTEM_H
#define CRATE_SYSTEM_H
#include <string>
#include <vector>
#include <stack>

enum class Mode { SINGLE, MULTIPLE };

class CrateSystem {
private:
     std::vector<std::stack<char>> crates;

     CrateSystem& operator=(const CrateSystem&);

public:
     CrateSystem() {}
     CrateSystem(std::string);
     ~CrateSystem();

     void Run(std::string);
     void Move(int, int, int, Mode);

     void PrintCrates();
     void PrintTopCrates();
};
#endif