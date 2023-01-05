#include <string>
#include <set>

struct RopeEnd {
     int coord[2];

     std::string GetCoordString() {
          return "(" + std::to_string(coord[0]) + ", " + std::to_string(coord[1]) + ")";
     }

     void MoveX(int dist) {
          coord[0] += dist;
     }

     void MoveY(int dist) {
          coord[1] += dist;
     }
};

#ifndef ROPE_H
#define ROPE_H
class Rope {
private:
     RopeEnd* head, * tail;
     std::set<std::pair<int, int>> visitSet;

public:
     Rope();
     ~Rope();

     void Move(char, int);
     void UpdateTail();

     void PrintStart();
     void PrintEnd();
     void PrintPositions();

     void GetVisitedCount();
};
#endif ROPE_H