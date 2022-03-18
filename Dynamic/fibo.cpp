#include <cstdlib>
#include <iostream>

using namespace std;

long int MemoizedResults[200];

long int fibo(int seqNum)
{
  /*
  int answer;

  if (MemoizedResults[seqNum] == -1)
    {
      if (seqNum == 0)
	answer = 1;
      
      else if (seqNum == 1)
	answer = 1;
      
      else
	answer =  fibo(seqNum-1) + fibo(seqNum-2);

      MemoizedResults[seqNum] =answer;
    }
  
  return MemoizedResults[seqNum];
  */

  for (int index=1; index<=seqNum; index++)
    {
      if (index==1 || index==2)
	MemoizedResults[index]=1;
      else
	MemoizedResults[index] =
	  MemoizedResults[index-1] + MemoizedResults[index-2];  
    }

  return MemoizedResults[seqNum];
}

int main(int argc, char *argv[])
{
  int request = atoi(argv[1]);

  for (int i=0; i< 200; i++)
    MemoizedResults[i]=-1;
  
  cout << fibo(request) << endl;

  return 0;
}
