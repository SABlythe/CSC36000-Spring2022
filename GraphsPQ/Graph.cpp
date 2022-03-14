#include "Graph.hpp"

#include "VertexPQ.hpp"

#include <map>
#include <set>

using namespace std;

Graph::Graph(istream &is)
{
  string v1, v2;
  int cost;

  is >> v1 >> v2 >> cost;
  while (is)
    {
      addVertex(v1);
      addVertex(v2);

      addEdge(v1, v2, cost);

      is >> v1 >> v2 >> cost;
    }
}


Vertex*
Graph::getVertex(const std::string &id) const
{
  for (Vertex* vp : _vertices)
    if (vp->id() == id)
      return vp;

  return NULL; 
}


bool
Graph::addVertex(const std::string &id)
{
  if (!getVertex(id))
    {
      
      Vertex * newVert = new Vertex(id);
      _vertices.push_back(newVert);
      return true;
    }
  else
    return false; // vertex already existed !    
}


bool
Graph::addEdge(Vertex *from, Vertex *to, int cost)
{
  pair <Vertex*, int> newAdj(to, cost);

  from ->adjacencies().push_back(newAdj);
  
  return true;
}

bool
Graph::addEdge(const std::string &fromID, const std::string &toID, int cost)
{
  Vertex *from = getVertex(fromID);
  Vertex *to = getVertex(toID);

  if (! (from && to) )
    return false;

  return addEdge(from, to, cost); 
}

int
Graph::shortestPath(const std::string &sourceID, const std::string &sinkID) const
{
  // set of visited vertexes to which a minimum path has been found
  set<Vertex *> S;

  Vertex *targetNode = getVertex(sinkID);  //pointer to destination vertex data
 
  Vertex *nodeFound = getVertex(sourceID); //pointer to start (curr) vertex data
    
  map< Vertex*, int> distances; // maps vertexes to best path so far

  // initially all vertices cannot eb reached. 
  for (Vertex* pv : _vertices)
    distances[pv] = INT_MAX;



  // make a priority queue of vertices
  VertexPQ pq(_vertices);
  // distance to starting vertex (current at this point) is 0 by definition
  pq.update(nodeFound, 0);
  distances[nodeFound] = 0; 


  S.insert(nodeFound);

  // need to remove the start node from the pq
  pq.removeMin();

  // keep going untip we have gotten to the intended destination. 
  while(nodeFound!=targetNode)
    {
      // update all distance values to nodes adjacent to the next node
      for (auto hops: nodeFound->adjacencies())
	{
	  int costWithNewHop = distances[nodeFound] + hops.second; 

	  // if this hop gives a better path ...
	  if (costWithNewHop < distances[hops.first] )
	    {
	      // update distance using this hop if it is a better path
	      distances[hops.first] =  costWithNewHop;

	      // update heap.  Note that this will always be an upheap
	      pq.update(hops.first, costWithNewHop);
	    }
	}

      // min on heap is next node to visit (in next loop pass) and add to  S. 
      nodeFound=pq.removeMin().first;

      S.insert(nodeFound);

    }

  //return the distance to our destination. 
  return distances[targetNode];
}

std::ostream&
Graph::print(std::ostream &os) const
{
  for (Vertex* pv : _vertices)
    os << *pv << endl;
  
  return os;
}

std::ostream& operator<<(std::ostream &os, const Graph &g)
{
  return g.print(os); 
}
