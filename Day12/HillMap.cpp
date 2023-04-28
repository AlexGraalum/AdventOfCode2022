#include "HillMap.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>

HillMap::HillMap(std::string file) {
     std::ifstream inputFile(file);
     std::string s;

     std::vector<Vertex<MapPoint>> mapVertices;

     while (!inputFile.eof()) {
          getline(inputFile, s);

          if (width == 0) width = s.length();
          
          int x = 0;
          for (auto& c : s) {
               MapPoint p;

               p.SetCharacter(c);
               p.SetHeight(c == 'S' ? 'a' - 97 : c == 'E' ? 'z' - 95 : c - 96);

               int coord[2];
               coord[0] = x;
               coord[1] = (int)height;
               p.SetCoord(coord);

               mapVertices.emplace_back(Vertex<MapPoint>(p, (int)mapVertices.size()));

               x++;
          }
          height++;
     }

     this->hillMap = new Graph<MapPoint>(mapVertices);

     for(size_t y = 0; y < height; y++){
          for(size_t x = 0; x < width; x++){
               if(mapVertices[(y * width) + x].GetData().GetCharacter() == 'S'){
                    start[0] = x;
                    start[1] = y;
               }
     
               if(mapVertices[(y * width) + x].GetData().GetCharacter() == 'E'){
                    end[0] = x;
                    end[1] = y;
               }

               Vertex<MapPoint> u = hillMap->GetVertex((y * width) + x);
               size_t v[4] = {
                    ((y - 1) * width) + x,   //UP
                    (y * width) + x + 1,     //RIGHT
                    ((y + 1) * width) + x,   //DOWN
                    (y * width) + x - 1      //LEFT
                    
               };

               for (int i = 0; i < 4; i++) {
                    if (v[i] >= 0 && v[i] < (width * height) &&
                         u.GetData() >> hillMap->GetVertex(v[i]).GetData())

                         //hillMap->AddUndirectedEdge(u, hillMap->GetVertex(v[i]));
                         hillMap->AddDirectedEdge(u, hillMap->GetVertex(v[i]));
               }
          }
     }
}

HillMap::~HillMap() {
     delete hillMap;
}

void HillMap::PrintMaps() {
     std::vector<Vertex<MapPoint>> mapVertices = hillMap->GetVertices();

     std::cout << "\tHill Map\t\t\tHill Index Map\t\t\tHill Height Map\t\tPath Map\n";

     for (size_t y = 0; y < height; y++) {

          //Hill Map
          for (size_t x = 0; x < width; x++) {
               std::cout << std::setw(3) << mapVertices[(y * width) + x].GetData().GetCharacter();
          }
          std::cout << "\t";
          //Hill Index Map
          for (size_t x = 0; x < width; x++) {
               std::cout << std::setw(3) << (y * width) + x;
          }
          std::cout << "\t";
          //Hill Height Map
          for (size_t x = 0; x < width; x++) {
               std::cout << std::setw(3) << mapVertices[(y * width) + x].GetData().GetHeight();
          }
          std::cout << "\t";
          //Hill Path Map
          for (size_t x = 0; x < width; x++) {
               switch (mapVertices[(y * width) + x].GetData().GetDirection()) {
               case Direction::NONE:
                    std::cout << ".";
                    break;
               case Direction::UP:
                    std::cout << "^";
                    break;
               case Direction::DOWN:
                    std::cout << "v";
                    break;
               case Direction::LEFT:
                    std::cout << "<";
                    break;
               case Direction::RIGHT:
                    std::cout << ">";
                    break;
               }
          }

          std::cout << std::endl;
     }
}

void HillMap::PrintHillMap() {
     std::vector<Vertex<MapPoint>> mapVertices = hillMap->GetVertices();

     std::cout << "Hill Map\n";

     for (size_t y = 0; y < height; y++) {
          for (size_t x = 0; x < width; x++) {
               std::cout << std::setw(1);
               std::cout << mapVertices[(y * width) + x].GetData().GetCharacter();
          }
          std::cout << std::endl;
     }
}

void HillMap::PrintHillHeightMap() {
     std::vector<Vertex<MapPoint>> mapVertices = hillMap->GetVertices();

     std::cout << "Hill Height Map\n";

     for (size_t y = 0; y < height; y++) {
          for (size_t x = 0; x < width; x++) {
               std::cout << std::setw(3);
               std::cout << mapVertices[(y * width) + x].GetData().GetHeight();
          }
          std::cout << std::endl;
     }
}

void HillMap::FindPath() {
     hillMap->GenerateAdjacencyMatrix();

     //std::vector<Vertex<MapPoint>*> path = aStarPathFinding(&hillMap->GetVertex((start[0] * width) + start[1]), &hillMap->GetVertex((end[0] * width) + end[1]));
     std::vector<Vertex<MapPoint>*> path = this->hillMap->pathFinding(&hillMap->GetVertex((start[1] * width) + start[0]), &hillMap->GetVertex((end[1] * width) + end[0]));
     if (path.empty()) {
          std::cout << "Path Not Found\n";
     }
}

void HillMap::PrintPathMap() {
     std::vector<Vertex<MapPoint>> mapVertices = hillMap->GetVertices();
     int pathLength = 0;

     for (size_t y = 0; y < height; y++) {
          for (size_t x = 0; x < width; x++) {
               switch (mapVertices[(y * width) + x].GetData().GetDirection()) {
               case Direction::NONE:
                    std::cout << ".";
                    break;
               case Direction::UP:
                    std::cout << "^";
                    pathLength++;
                    break;
               case Direction::DOWN:
                    std::cout << "v";
                    pathLength++;
                    break;
               case Direction::LEFT:
                    std::cout << "<";
                    pathLength++;
                    break;
               case Direction::RIGHT:
                    std::cout << ">";
                    pathLength++;
                    break;
               }
          }
          std::cout << std::endl;
     }

     std::cout << "\nPath Length: " << pathLength << std::endl;
}

void HillMap::PrintAdjMat() {
     std::cout << "Hill Adjacency Matrix\n";

     this->hillMap->PrintAdjacencyMatrix();
}

void HillMap::PrintEdges() {
     this->hillMap->PrintEdges();
}