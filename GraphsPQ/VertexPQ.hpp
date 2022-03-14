#ifndef _VERTEX_PQ_HPP_
#define _VERTEX_PQ_HPP_

#include <iostream>
#include <map>
#include "Vertex.hpp"


class VertexPQ
{
private:
  std::pair< Vertex*, int > *_heap;
  int _size;
  int _numEls;
  std::map< Vertex *, int> _vertToIndex;
public:
  VertexPQ(int size);
  VertexPQ(const std::list<Vertex *> &_nodes);

  void upheap(Vertex *v);
  
  void insert( Vertex *v, int dist=INT_MAX);
  std::pair< Vertex*, int> removeMin();

  void update( Vertex *v, int newDist);

  friend std::ostream& operator<<(std::ostream &os, const VertexPQ &vpq);
};

#endif
