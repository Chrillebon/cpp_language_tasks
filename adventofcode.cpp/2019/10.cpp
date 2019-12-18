#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;

int size = 23;

vector<vector<char>> field(size,vector<char>(size));

int gcd(int a, int b)
{
  int r = b;
  if(b > a)
  {
    r = a;
    a = b;
    b = r;
  }
  if(b == 0)
  {
    return a;
  }
  while(a % b != 0)
  {
    r = a % b;
    return gcd(b,r);
  }
  return r;
}

int in_sight(int x, int y)
{
  vector<vector<int>> spotted(2,vector<int>());
  int res = 0;
  for(int i=0;i<size;i++)
  {
    for(int o=0;o<size;o++)
    {
      if(!(i == y && o == x) && field[o][i] == '#')
      {
        int xdif = o - x;
        int ydif = i - y;
        int s = gcd(abs(xdif), abs(ydif)); //forkorter brøken
        xdif /= s;
        ydif /= s;
        //------------------exists command
        int exi = 0;
        for(int i=0;i<spotted[0].size();i++)
        {
          if(xdif == spotted[0][i] && ydif == spotted[1][i])
          {
            exi = 1;
          }
        }
        //--------------------
        if(exi == 0) //dårlig køretid, men ligeglad for this
        {
          spotted[0].push_back(xdif);
          spotted[1].push_back(ydif);
        }
      }
    }
  }
  return spotted[0].size();
}

int main()
{
  int total = 0;
  for(int i=0;i<size;i++)
  {
    for(int o=0;o<size;o++)
    {
      std::cin >> field[o][i];
    }
  }
  for(int i=0;i<size;i++)
  {
    for(int o=0;o<size;o++)
    {
      if(field[o][i] == '#')
      {
        int tmp = in_sight(o,i);
        total = max(total, tmp);
        if(tmp == 230) //den største
        {
          std::cout << "koor: " <<o<<", "<<i<< '\n';
        }
      }
    }
  }
  std::cout << "den største er: " <<total<< '\n';
  return 0;
}
