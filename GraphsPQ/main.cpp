#include <fstream>
#include <iostream>

#include "Graph.hpp"
#include "Vertex.hpp"

using namespace std;

int main(int argc, char **argv)
{
  ifstream ifile(argv[1]);

  Graph g(ifile);

  cout << g.shortestPath("s", "t") << endl; 
  
  return 0;
}
