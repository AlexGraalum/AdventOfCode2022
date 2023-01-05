#ifndef FOREST_H
#define FOREST_H
#include <string>
#include <vector>

class Forest {
public:
     Forest(std::string);
     ~Forest();

     void PushString(std::string);
     void PrintForest();

     void ProcessSightLines();
     std::pair<bool, int> CheckSight(int, unsigned int, unsigned int);

     int VisibleCount();
     int ScenicScore();
private:
     std::vector<std::vector<std::pair<int, std::pair<bool, int>>>> forest;

     unsigned int forestWidth, forestHeight;
};

#endif FOREST_H