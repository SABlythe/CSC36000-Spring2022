#ifndef _VERTEX_HPP_
#define _VERTEX_HPP_

#include <iostream>
#include <list>
#include <string>

class Vertex
{
private:
  std::string _id;				//unique ID for this node`
  std::list< std::pair<Vertex*, int> > _adj;    //list of outgoing edges (to ID, cost)
  int _heapIndex;                               //current array index in PQ heap
public:
  Vertex(std::string id) : _id(id), _adj(), _heapIndex(-1) {}

  const std::string& id() const {return _id;}
  
  const std::list< std::pair<Vertex*, int> > &  adjacencies() const {return _adj;}
  std::list< std::pair<Vertex*, int> > &  adjacencies() {return _adj;}

  const int heapIndex() const {return _heapIndex;}
  int& heapIndex() {return _heapIndex;}
  
  std::ostream& print(std::ostream &os) const;

  friend std::ostream& operator<<(std::ostream &os, const Vertex &v); 
};

#endif
