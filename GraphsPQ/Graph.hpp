#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <iostream>

#include "Vertex.hpp"

class Graph
{
private:
  std::list <Vertex *> _vertices; 
public:
  Graph(): _vertices()  {}
  Graph(std::istream &is); 

  const std::list< Vertex* >& vertices() const {return _vertices; }
  std::list< Vertex* >& vertices() {return _vertices; }

  Vertex* getVertex(const std::string &id) const;
  
  bool addVertex(const std::string &id);
  bool addEdge(Vertex *from, Vertex *to, int cost);
  bool addEdge(const std::string &fromID, const std::string &toID, int cost); 

  int shortestPath(const std::string &sourceID, const std::string &sinkID) const; 
  
  std::ostream& print(std::ostream &os) const;

  friend std::ostream& operator<<(std::ostream &os, const Graph &g); 
};

#endif
