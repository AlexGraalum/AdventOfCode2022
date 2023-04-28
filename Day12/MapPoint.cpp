#include "MapPoint.h"

#include <math.h>

MapPoint::MapPoint() {
     coord[0] = 0;
     coord[1] = 0;

     character = ' ';

     height = 0;

     direction = Direction::NONE;
}

//Custom Operators
//Is Adjacent (Non-Diagonal)
bool MapPoint::operator|=(const MapPoint& other) const {
     if (this == &other) return false;
     if (other.coord[0] == coord[0] && abs(other.coord[1] - coord[1]) == 1) return true;
     if (other.coord[1] == coord[1] && abs(other.coord[0] - coord[0]) == 1) return true;
     return false;
}

//Is Climbable
bool MapPoint::operator^(const MapPoint& other) const {
     int diff = height - other.height;
     if (diff == 0 || diff == 1) return true;
     return false;
}

//Is Adjacent AND Climbable
bool MapPoint::operator>>(const MapPoint& other) const {
     if ((*this |= other) && (*this ^ other)) return true;
     return false;
}

//Is The Same
bool MapPoint::operator==(const MapPoint& other) const {
     if (coord[0] != other.coord[0] && coord[1] != other.coord[1]) return false;
     if (character != other.character) return false;
     if (height != other.height) return false;
     if (direction != other.direction) return false;
     return true;
}