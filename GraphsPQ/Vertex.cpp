#include "Vertex.hpp"

using namespace std;


ostream&
Vertex::print(ostream &os) const
{
  os << _id << ": ";

  for(  pair<Vertex*, int>  adj : _adj)
    {
      os << adj.first->id() << ":" << adj.second << " ";
    }
  return os;
}

ostream& operator<<(ostream &os, const Vertex &v)
{
  return v.print(os);
}
