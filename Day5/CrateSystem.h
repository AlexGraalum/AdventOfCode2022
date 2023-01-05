#pragma once
#ifndef CRATE_SYSTEM_H
#define CRATE_SYSTEM_H
#include <string>
#include <vector>
#include <stack>

class CrateSystem {
public:
     std::vector<std::stack<char>> crates;

     CrateSystem(int, std::vector<std::string>);
     ~CrateSystem();

     void Move(int, int, int);
     void PrintCrates();
     void PrintTopCrates();
};
#endif