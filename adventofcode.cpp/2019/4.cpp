#include <iostream>
#include <vector>
#include <math.h>
#include <cmath>
using namespace std;

vector<int> numlist(6);
int res = 0;

int good(int a)
{
  int last=-1, d = 0;
  for(int i=0;i<6;i++)
  {
    numlist[i] = (a / pow(10, 5-i));
    numlist[i] %= 10;
  }
  if(numlist[0] == numlist[1] && numlist[2] != numlist[0])
  {
    d=1;
  }
  if(numlist[0] != numlist[1] && numlist[1] == numlist[2] && numlist[2] != numlist[3])
  {
    d=1;
  }
  if(numlist[1] != numlist[2] && numlist[2] == numlist[3] && numlist[3] != numlist[4])
  {
    d=1;
  }
  if(numlist[2] != numlist[3] && numlist[3] == numlist[4] && numlist[4] != numlist[5])
  {
    d=1;
  }
  if(numlist[3] != numlist[4] && numlist[4] == numlist[5])
  {
    d=1;
  }
  for(int i=0;i<6;i++)
  {
    if(last > numlist[i])
    {
      return 0;
    }
    else
    {
      last = numlist[i];
    }
  }
  if(d)
  {
    return 1;
  }
  return 0;
}

int main()
{
  for(int i=145852;i<=616942;i++)
  {
    res+=good(i);
  }
  std::cout << res << '\n';
  return 0;
}
