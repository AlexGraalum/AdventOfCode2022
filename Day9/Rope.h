#include <string>
#include <vector>
#include <set>

struct RopeSegment {
     int coord[2] = { 0,0 };
     RopeSegment* nextSegment = nullptr;

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
     std::vector<RopeSegment*> segments;
     std::set<std::pair<int, int>> visitSet;

public:
     Rope(int);
     ~Rope();

     void Move(char, int);
     void UpdateSegments(RopeSegment*, RopeSegment*);
     void GetVisitedCount();
};
#endif ROPE_H