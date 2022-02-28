#include <iostream>
#include <set>

using namespace std;

int main(int argc, char *argv[])
{
  set<string>  myArgs;

  for (int index=1; index<argc; index++)
    {
      myArgs.insert(argv[index]);
    }

  /*
  for (string str : myArgs)
    {
      cout << str << endl;
    }
  */
  
  //set<string>::iterator myArgsIterator;

  for(auto myArgsIterator = myArgs.begin();
      myArgsIterator != myArgs.end();
      myArgsIterator++)
    {
      cout << *myArgsIterator << endl;
    }
  
  cout << "first item:" << *(myArgs.begin()) << endl;
  
  return 0;
}
