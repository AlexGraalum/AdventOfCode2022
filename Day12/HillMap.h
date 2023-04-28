#pragma once
#ifndef HILLMAP_H
#define HILLMAP_H

#include "MapPoint.h"
#include "Graph.h"

#include <string>
#include <vector>

class HillMap {
private:
     Graph<MapPoint>* hillMap;

     size_t width = 0;
     size_t height = 0;

     size_t start[2] = {};
     size_t end[2] = {};
public:
     HillMap(std::string);
     ~HillMap();

     void PrintMaps();

     void PrintHillMap();
     void PrintHillHeightMap();
     void PrintPathMap();

     void FindPath();

     void PrintAdjMat();
     void PrintEdges();
};

#endif