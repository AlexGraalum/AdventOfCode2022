#ifndef VERTEX_H
#define VERTEX_H

template<typename T>
class Vertex {
private:
     T data;
     int index;
public:
     Vertex() {}
     Vertex(T data, int index) { this->data = data; this->index = index; }
     ~Vertex() {}

     T GetData() { return this->data; }
     void SetData(T data) { this->data = data; }

     int GetIndex() { return this->index; }
     void SetIndex(int index) { this->index = index; }

     bool operator ==(const Vertex<T>& other) const {
          return data == other.data && index == other.index;
     }
};
#endif