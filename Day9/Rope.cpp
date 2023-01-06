#include "Rope.h"
#include <iostream>
#include <cmath>

Rope::Rope(int segmentCount) {
     for (int i = 0; i < segmentCount; i++) {
          segments.push_back(new RopeSegment());
     }
     for (int i = 0; i < segmentCount - 1; i++) {
          segments[i]->nextSegment = segments[i + 1];
     }
}

Rope::~Rope() {
     for (auto r : segments) delete r;
     segments.clear();
}

void Rope::Move(char dir, int dist) {
     for (int d = 0; d < dist; d++) {
          //Move Head
          segments[0]->MoveX(dir == 'U' ? 1 : dir == 'D' ? -1 : 0);
          segments[0]->MoveY(dir == 'R' ? 1 : dir == 'L' ? -1 : 0);

          //Move Following Segments
          for (unsigned int i = 1; i < segments.size(); i++) {
               UpdateSegments(segments[i-1], segments[i]);
          }

          //Record Tail Location
          visitSet.insert(std::make_pair(segments[segments.size() - 1]->coord[0],
                                         segments[segments.size() - 1]->coord[1]));
     }
}

void Rope::UpdateSegments(RopeSegment* segmentA, RopeSegment* segmentB) {
     //Same Position
     if (segmentA->coord == segmentB->coord) return;

     //Different Positions
     int xDist = segmentA->coord[0] - segmentB->coord[0];
     int yDist = segmentA->coord[1] - segmentB->coord[1];
     //Diagonal
     if (segmentB->coord[0] != segmentA->coord[0] && segmentB->coord[1] != segmentA->coord[1]) {
          if (std::abs(xDist) > 1) {
               segmentB->MoveY(yDist / std::abs(yDist));
               segmentB->MoveX(xDist / std::abs(xDist));
          } else if (std::abs(yDist) > 1) {
               segmentB->MoveX(xDist / std::abs(xDist));
               segmentB->MoveY(yDist / std::abs(yDist));
          }
     } else {
          //Check Horizontal
          if (xDist > 1) {
               segmentB->MoveX(1);
          } else if (xDist < -1) {
               segmentB->MoveX(-1);
          }
          //Check Vertical
          if (yDist > 1) {
               segmentB->MoveY(1);
          } else if (yDist < -1) {
               segmentB->MoveY(-1);
          }
     }
}

void Rope::GetVisitedCount() {
     std::cout << "Positons visited by Tail: " << visitSet.size() << std::endl;
}