#include "VertexPQ.hpp"

using namespace std;

VertexPQ::VertexPQ(int size)
{
  _size = size;
  _heap = new pair<Vertex*,int> [_size+1];
  _numEls = 0;
}

VertexPQ::VertexPQ(const list<Vertex *> &verts)
{
  _size = verts.size();
  _heap = new pair<Vertex*,int> [_size+1];
  _numEls = 0;

  for (Vertex* pv: verts)
    insert(pv); 
}



void
VertexPQ::insert( Vertex *v, int dist)
{
  pair<Vertex*, int> newNode( v, dist);

  _heap[++_numEls] = newNode;
  newNode.first->heapIndex()=_numEls;

  upheap(newNode.first);
  // now do an upheap
  /*
  int index = _numEls; 
  while (index>1 && (_heap[index].second < _heap[index/2].second ) )
    {
      pair<Vertex*, int> temp = _heap[index];
      _heap[index] = _heap[index/2];
      _heap[index/2] = temp;

      _heap[index]->heapIndex() = index;
      _heap[index/2]->heapIndex()=index/2;
      
      index/=2;
    }
  */
}

void
VertexPQ::upheap(Vertex *v)
{
  int index = v->heapIndex(); 
  while (index>1 && (_heap[index].second < _heap[index/2].second ) )
    {
      pair<Vertex*, int> temp = _heap[index];
      _heap[index] = _heap[index/2];
      _heap[index/2] = temp;

      _heap[index].first->heapIndex() = index;
      _heap[index/2].first->heapIndex()=index/2;
      
      index/=2;
    }

}

void
VertexPQ::update( Vertex *v, int newDist)
{
  _heap[v->heapIndex()].second = newDist;
  upheap(v);
}

std::pair< Vertex*, int>
VertexPQ::removeMin()
{
  // 1. pull minimum
  pair<Vertex*, int> minVal = _heap[1];
  
  // 2. take last element, move it to root
  _heap[1] = _heap[_numEls];
  _numEls--;
  
  // 3. and downheap
  int index=1;

  // while not in last level
  while(2*index <= _numEls)
    {
      // temporarily assume minimum child is left child
      int minChildIndex = 2*index;

      // if we have a right child, maybe it is smaller ...
      if (2*index+1 <= _numEls)
	{
	  if (_heap[minChildIndex].second > _heap[2*index+1].second )
	    minChildIndex = 2*index +1;
	}

      // if we are bigger than our smallest child, downheap one more level. 
      if (_heap[index].second >= _heap[minChildIndex].second )
	{
          // swap with smaller child ...
	  pair<Vertex*, int> temp = _heap[index];
	  _heap[index] = _heap[minChildIndex];
	  _heap[minChildIndex] = temp;

          // update vertex indexes into heap ...
	  _heap[index].first->heapIndex() = index;
	  _heap[minChildIndex].first->heapIndex() = minChildIndex;;
	  
          // move down heap one level in heap and repeat. 
	  index=minChildIndex; 
	}
      else // if we didn't need to down heap here, break out of loop (nothing else will move up) 
	break;
    }

  return minVal;
}

std::ostream& operator<<(std::ostream &os, const VertexPQ &vpq)
{
  for (int index =1; index<=vpq._numEls; index++)
    os << * ( vpq._heap[index].first )
       << "    ["  << vpq._heap[index].second << "]" << endl;
  return os;
}
