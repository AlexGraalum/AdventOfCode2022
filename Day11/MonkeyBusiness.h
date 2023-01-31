#ifndef MONKEYBUSINESS_H
#define MONKEYBUSINESS_H
#include "Monkey.h"

#include <vector>
#include <functional>

class MonkeyBusiness {
private:
     std::vector<Monkey*> monkeys;
     int modulo;
public:
     MonkeyBusiness(std::string filename);

     void Run(unsigned int rounds, int relief, int modulo);

     int GetModulo() { return this->modulo; }

     void CalculateMonkeyBusiness(std::vector<Monkey*> monkeys);

     void PrintMonkeys();
};
#endif