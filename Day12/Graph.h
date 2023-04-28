#pragma once
#ifndef GRAPH_H
#define GRAPH_H

#include "Vertex.h"

#include <iostream>
#include <iomanip>
#include <vector>
#include <deque>
#include <queue>
#include <unordered_map>
#include <algorithm>
#include <sstream>

template<typename T>
class Graph {
private:
     std::vector<Vertex<T>> vertices;
     std::vector<std::pair<Vertex<T>, Vertex<T>>> edges;

     std::vector<int> adjacencyMatrix;
public:
     Graph() {}
     Graph(std::vector<Vertex<T>> vertices) {
          this->vertices = vertices;
          this->edges = {};
          adjacencyMatrix.resize(vertices.size() * vertices.size(), 0);
     }
     Graph(std::vector<Vertex<T>> vertices, std::vector<std::pair<Vertex<T>, Vertex<T>>> edges) {
          this->vertices = vertices;
          this->edges = edges;
          adjacencyMatrix.resize(vertices.size() * vertices.size(), 0);
     }

     ~Graph() { vertices.clear(); edges.clear(); }

     void AddUndirectedEdge(Vertex<T> u, Vertex<T> v) {
          std::pair<Vertex<T>, Vertex<T>> edgeA = {u, v};
          std::pair<Vertex<T>, Vertex<T>> edgeB = {v, u};

          if (!ContainsUndirectedEdge(edgeA)) {
               if (u.GetIndex() < v.GetIndex()) {
                    edges.emplace_back(edgeA);
                    edges.emplace_back(edgeB);
               } else {
                    edges.emplace_back(edgeB);
                    edges.emplace_back(edgeA);
               }
          }
     }

     bool ContainsUndirectedEdge(std::pair<Vertex<T>, Vertex<T>> e) {
          return std::any_of(edges.begin(), edges.end(),
               [&e](const std::pair<Vertex<T>, Vertex<T>>& edge) {
                    return (edge.first == e.first && edge.second == e.second) ||
                         (edge.first == e.second && edge.second == e.first);
               });
     }

     void AddDirectedEdge(Vertex<T> u, Vertex<T> v) {
          if (!ContainsDirectedEdge(std::make_pair(u, v))) {
               if (u.GetData().GetHeight() < v.GetData().GetHeight()) {
                    edges.emplace_back(std::make_pair(u, v));
               } else {
                    edges.emplace_back(std::make_pair(v, u));
               }
          }
     }

     bool ContainsDirectedEdge(std::pair<Vertex<T>, Vertex<T>> e) {
          return std::any_of(edges.begin(), edges.end(),
               [&e](const std::pair<Vertex<T>, Vertex<T>>& edge) {
                    return (edge.first == e.first && edge.second == e.second);
               });
     }

     std::vector<Vertex<T>> GetVertices() { return this->vertices; }
     void SetVertices(std::vector<Vertex<T>> vertices) { this->vertices = vertices; }

     Vertex<T> GetVertex(size_t index) { return this->vertices[index]; }

     void GenerateAdjacencyMatrix() {
          std::sort(edges.begin(), edges.end(),
               [](auto& a, auto& b) {
                    return a.first.GetIndex() < b.first.GetIndex();
               });

          for (auto& e : edges) {
               adjacencyMatrix[(e.first.GetIndex() * vertices.size()) + e.second.GetIndex()] = 1;
          }
     }

     void PrintAdjacencyMatrix() {
          for (size_t y = 0; y < vertices.size(); y++) {
               for (size_t x = 0; x < vertices.size(); x++) {
                    size_t matIndex = (y * vertices.size()) + x;
                    std::cout << std::setw(2) << (adjacencyMatrix[matIndex] ? '*' : '.');
               }
               std::cout << std::endl;
          }
     }

     std::vector<Vertex<T>*> pathFinding(Vertex<T>* start, Vertex<T>* end) {
          std::Vector<Vertex<T>*> path = {};

          return path;
     }

     void PrintEdges() {
          std::cout << "\nEdges\n<Char[Index]{Height}>\n";
          for (auto& e : edges) {
               std::stringstream indexA, indexB;
               indexA << e.first.GetIndex();
               indexB << e.second.GetIndex();
               std::stringstream heightA, heightB;
               heightA << e.first.GetData().GetHeight();
               heightB << e.second.GetData().GetHeight();

               std::string strA, strB;
               strA = strB = "";

               strA.append(1, e.first.GetData().GetCharacter())
                    .append(1, '[').append(indexA.str()).append(1, ']')
                    .append(1, '{').append(heightA.str()).append(1, '}');

               strB.append(1, e.second.GetData().GetCharacter())
                    .append(1, '[').append(indexB.str()).append(1, ']')
                    .append(1, '{').append(heightB.str()).append(1, '}');

               std::cout << std::setw(10) << strA << " -> " << std::setw(10) << strB << "\n";
          }
     }
};
#endif