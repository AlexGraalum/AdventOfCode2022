#pragma once
#ifndef HILLMAP_H
#define HILLMAP_H

#include <string>
#include <vector>

enum class Direction {UP, DOWN, LEFT, RIGHT, NONE};

struct MapPoint {
     char c;
     int h;
     Direction d;
};
class HillMap {
private:
     std::vector<std::vector<MapPoint>> hillMap;

     int start[2] = {};
     int end[2] = {};
public:
     HillMap(std::string);
     ~HillMap();

     void PrintHillMap();

     void FindPath();
     void PrintPathMap();
};

#endif