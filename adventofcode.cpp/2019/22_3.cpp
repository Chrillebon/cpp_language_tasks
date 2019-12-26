#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
#include "22_x.h"
using namespace std;

int e = 2020;
vector<int> final(10007);

void restart()
{
  for(int i=0;i<10007;i++)
  {
    final[i] = i;
  }
  return;
}


int main()
{
  string word;
  restart();
  for(long long i=0;i<101741582076661;i++)
  {
    e = go[e];
    if(i % 1000000000000 == 0)
    {
      std::cout << i / 1000000000000 <<"% done"<< '\n';
    }
  }
  std::cout << "done!" << '\n';
  return 0;
}

/*

efter gang:
1: 2916
2: 4293
3: 5202
4: 7568
5: 758
6: 4896
7: 7366
8: 2456
9:
*/
