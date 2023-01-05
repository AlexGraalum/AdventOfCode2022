#include "Rope.h"
#include <iostream>
#include <cmath>

Rope::Rope() {
     head = new RopeEnd();
     tail = new RopeEnd();
     //visitMap = new std::map<int[2], int>();
}

Rope::~Rope() {
     delete head;
     delete tail;
}

void Rope::Move(char dir, int dist) {
     //std::cout << dir << " - " << dist << std::endl;

     for (unsigned int d = 0; d < dist; d++) {
          head->MoveY(dir == 'U' ? 1 : dir == 'D' ? -1 : 0);
          head->MoveX(dir == 'R' ? 1 : dir == 'L' ? -1 : 0);

          UpdateTail();
          visitSet.insert(std::make_pair(tail->coord[0], tail->coord[1]));
          //PrintPositions();
     }
}

void Rope::UpdateTail() {
     int xDist = head->coord[0] - tail->coord[0];
     int yDist = head->coord[1] - tail->coord[1];

     //Diagonal
     if (tail->coord[0] != head->coord[0] && tail->coord[1] != head->coord[1]) {
          if (std::abs(xDist) > 1) {
               tail->MoveY(yDist / std::abs(yDist));
               tail->MoveX(xDist / std::abs(xDist));
          } else if (std::abs(yDist) > 1) {
               tail->MoveX(xDist / std::abs(xDist));
               tail->MoveY(yDist / std::abs(yDist));
          }
     } else {
          //Check Horizontal
          if (xDist > 1) {
               tail->MoveX(1);
          } else if (xDist < -1) {
               tail->MoveX(-1);
          }
          //Check Vertical
          else if (yDist > 1) {
               tail->MoveY(1);
          } else if (yDist < -1) {
               tail->MoveY(-1);
          }
     }
}

void Rope::PrintStart() {
     std::cout << "Start Positions\n";
     PrintPositions();
}

void Rope::PrintEnd() {
     std::cout << "End Positions\n";
     PrintPositions();
}

void Rope::PrintPositions() {
     std::cout << "Head: " << head->GetCoordString() << "\tTail: " << tail->GetCoordString() << std::endl;
}

void Rope::GetVisitedCount() {
     std::cout << "Positons visited by Tail: " << visitSet.size() << std::endl;
}