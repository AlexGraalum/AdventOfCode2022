#pragma once
#ifndef MAPPOINT_H
#define MAPPOINT_H

enum class Direction { NONE, UP, DOWN, LEFT, RIGHT};

class MapPoint {
private:
     int coord[2];
     char character;
     int height;
     Direction direction;
public:
     MapPoint();

     int* GetCoord() { return coord; }
     void SetCoord(int coord[2]) { this->coord[0] = coord[0]; this->coord[1] = coord[1]; }

     char GetCharacter() { return character; }
     void SetCharacter(char character) { this->character = character; }

     int& GetHeight() { return height; }
     void SetHeight(int height) { this->height = height; }

     Direction GetDirection() { return direction; }
     void SetDirection(Direction direction) { this->direction = direction; }

     bool operator|=(const MapPoint& other) const;
     bool operator^(const MapPoint& other) const;
     bool operator>>(const MapPoint& other) const;
     bool operator==(const MapPoint& other) const;
};

#endif