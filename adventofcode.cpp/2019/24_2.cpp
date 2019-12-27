#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<vector<int>>> around(203, vector<vector<int>>(5,vector<int>(5)));

int how_many(int l, int x, int y)
{
  int res = 0;
  if(x-1 >= 0)
  {
    if(x-1 == 2 && y == 2) //Niveu ind fra højre
    {
      for(int i=0;i<5;i++)
      {
        res += around[l+1][4][i]; //Alle 4 i højre
      }
    }
    else if(around[l][x-1][y])
    {
      res++;
    }
  }
  else //Uden for venstre
  {
    res += around[l-1][1][2];
  }
  if(x+1 < 5)
  {
    if(x+1 == 2 && y == 2) //Niveu ind fra venstre
    {
      for(int i=0;i<5;i++)
      {
        res += around[l+1][0][i]; //Alle 4 i højre
      }
    }
    else if(around[l][x+1][y])
    {
      res++;
    }
  }
  else //Uden for højre
  {
    res += around[l-1][3][2];
  }
  if(y-1 >= 0)
  {
    if(x == 2 && y-1 == 2) //Niveu ind fra bunden
    {
      for(int i=0;i<5;i++)
      {
        res += around[l+1][i][4]; //Alle 4 i højre
      }
    }
    else if(around[l][x][y-1])
    {
      res++;
    }
  }
  else //Uden for over, er nu lige over midten
  {
    res += around[l-1][2][1];
  }
  if(y+1 < 5)
  {
    if(x == 2 && y+1 == 2) //Niveu ind fra toppen
    {
      for(int i=0;i<5;i++)
      {
        res += around[l+1][i][0]; //Alle 4 i højre
      }
    }
    else if(around[l][x][y+1])
    {
      res++;
    }
  }
  else //Uden for under
  {
    res += around[l-1][2][3];
  }
  return res;
}

void change()
{
  vector<vector<vector<int>>> tmp(203,vector<vector<int>>(5,vector<int>(5)));
  for(int rec=1;rec<202;rec++) //Så ender jeg ikke i out of bounds
  {
    for(int i=0;i<5;i++)
    {
      for(int o=0;o<5;o++)
      {
        if(!(o == 2 && i == 2)) //Spring midten over
        {
          int a = how_many(rec,o,i);
          if(a != 1 && around[rec][o][i])
          {
            tmp[rec][o][i] = 0;
          }
          else if((a == 1 || a == 2) && !around[rec][o][i])
          {
            tmp[rec][o][i] = 1;
          }
          else
          {
            tmp[rec][o][i] = around[rec][o][i];
          }
        }
      }
    }
  }
  for(int rec=0;rec<203;rec++)
  {
    for(int i=0;i<5;i++)
    {
      for(int o=0;o<5;o++)
      {
        around[rec][o][i] = tmp[rec][o][i];
      }
    }
  }
  return;
}

void display(int lvl)
{
  for(int i=0;i<5;i++)
  {
    for(int o=0;o<5;o++)
    {
      if(around[lvl][o][i])
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

long long bugscore()
{
  long long res = 0;
  for(int rec=0;rec<203;rec++)
  {
    for(int i=0;i<5;i++)
    {
      for(int o=0;o<5;o++)
      {
        res += around[rec][o][i];
      }
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
        around[101][o][i] = 1;
      }
      else if(t == '.')
      {
        around[101][o][i] = 0;
      }
    }
  }
  int minutes = 0;
  while(minutes < 200)
  {
    change();
    minutes++;
  }
  display(101);
  std::cout << "efter: " <<minutes<<" endte vi med: "<<bugscore()<<" insekter"<< '\n';
  return 0;
}
