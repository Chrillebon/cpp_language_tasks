#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> around(5,vector<int>(5));
vector<vector<vector<int>>> seen(0,vector<vector<int>>(5,vector<int>(5)));

int redo()
{
  for(int i=0;i<seen.size();i++)
  {
    if(around == seen[i])
    {
      return 1;
    }
  }
  seen.push_back(around);
  return 0;
}

int how_many(int x, int y)
{
  int res = 0;
  if(x-1 >= 0)
  {
    if(around[x-1][y])
    {
      res++;
    }
  }
  if(x+1 < 5)
  {
    if(around[x+1][y])
    {
      res++;
    }
  }
  if(y-1 >= 0)
  {
    if(around[x][y-1])
    {
      res++;
    }
  }
  if(y+1 < 5)
  {
    if(around[x][y+1])
    {
      res++;
    }
  }
  return res;
}

void change()
{
  vector<vector<int>> tmp(5,vector<int>(5));
  for(int i=0;i<5;i++)
  {
    for(int o=0;o<5;o++)
    {
      int a = how_many(o,i);
      if(a != 1 && around[o][i])
      {
        tmp[o][i] = 0;
      }
      else if((a == 1 || a == 2) && !around[o][i])
      {
        tmp[o][i] = 1;
      }
      else
      {
        tmp[o][i] = around[o][i];
      }
    }
  }
  for(int i=0;i<5;i++)
  {
    for(int o=0;o<5;o++)
    {
      around[o][i] = tmp[o][i];
    }
  }
  return;
}

void display()
{
  for(int i=0;i<5;i++)
  {
    for(int o=0;o<5;o++)
    {
      if(around[o][i])
      {
        std::cout << "#";
      }
      else
      {
        std::cout << ".";
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';
}

long long bioscore()
{
  long long res = 0;
  for(int i=0;i<25;i++)
  {
    if(around[i % 5][i / 5])
    {
      res += pow(2,i);
    }
  }
  return res;
}

int main()
{
  //initial:
  char t;
  for(int i=0;i<5;i++)
  {
    for(int o=0;o<5;o++)
    {
      std::cin >> t;
      if(t == '#')
      {
        around[o][i] = 1;
      }
      else if(t == '.')
      {
        around[o][i] = 0;
      }
    }
  }
  int res = 0;
  while(!redo())
  {
    change();
    display();
    res++;
  }
  std::cout << "det tog: " <<res<<" forsøg og resultatet var: "<<bioscore()<< '\n';
  return 0;
}
