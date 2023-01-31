#include "MonkeyBusiness.h"

int main(int argc, char** argv) {
     MonkeyBusiness partOne("input.txt");
     partOne.PrintMonkeys();
     partOne.Run(20, 3, 0);

     MonkeyBusiness partTwo("input.txt");
     partTwo.Run(10000, 1, partTwo.GetModulo());

     return 0;
}