#include "Rope.h"
#include <iostream>
#include <cmath>

Rope::Rope() {
     head = new RopeEnd();
     tail = new RopeEnd();
}

Rope::~Rope() {
     delete head;
     delete tail;
}

void Rope::Move(char dir, int dist) {
     std::cout << dir << " - " << dist << std::endl;

     for (unsigned int d = 0; d < dist; d++) {
          if (dir == 'U') {
               head->MoveY(1);
          }
          else if (dir == 'D') {
               head->MoveY(-1);
          }
          else if (dir == 'L') {
               head->MoveX(-1);
          }
          else if (dir == 'R') {
               head->MoveX(1);
          }

          UpdateTail();
          PrintPositions();
     }
}

void Rope::UpdateTail() {
     int xDist = head->coord[0] - tail->coord[0];
     int yDist = head->coord[1] - tail->coord[1];

     //Diagonal
     if (tail->coord[0] != head->coord[0] && tail->coord[1] != head->coord[1]) {


     }
     else
          //Check Horizontal
          if (xDist > 1) {
               tail->MoveX(1);
          }
          else if (xDist < -1) {
               tail->MoveX(-1);
          }
          else
               //Check Vertical
               if (yDist > 1) {
                    tail->MoveY(1);
               }
               else if (yDist < -1) {
                    tail->MoveY(-1);
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
     //std::cout << "Positons visited by Tail: " << visited->size() << std::endl;
}