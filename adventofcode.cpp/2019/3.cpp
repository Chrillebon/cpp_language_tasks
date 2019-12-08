#include <iostream>
#include <vector>
#include <string>
#include <math.h>
using namespace std;

int cx=5000, cy=5000, x=5000, y=5000, amo;
char dir;
int size[] = {11,11};
vector<vector<int>> map(10000,vector<int>(10000));
char f1[] = {"R8,U5,L5,D3"};
char s1[] = {"U7,R6,D4,L4"};
vector<char *> com = {f1,s1};

//vector<vector<char>> com(vector<char>(1000));

void cdist(int a,int b)
{
  std::cout << "placeringerne er: " <<a<<" og "<<b<< '\n';
  std::cout << "dist "<<abs(a-cx)+abs(b-cy) << '\n';
  return;
}

void move(int dir, int a, int nu)
{
  if(dir == 0)
  {
    for(int i=1;i<=a;i++)
    {
      if(map[y+i][x] > 0 && map[y+i][x]!=nu)
      {
        cdist(x,y+i);
      }
      map[y+i][x] = nu;
    }
    y+=a;
  }
  if(dir == 1)
  {
    for(int i=1;i<=a;i++)
    {
      if(map[y][x-i] > 0 && map[y][x-i]!=nu)
      {
        cdist(x-i,y);
      }
      map[y][x-i] = nu;
    }
    x-=a;
  }
  if(dir == 2)
  {
    for(int i=1;i<=a;i++)
    {
      if(map[y-i][x] > 0 && map[y-i][x]!=nu)
      {
        cdist(x,y-i);
      }
      map[y-i][x] = nu;
    }
    y-=a;
  }
  if(dir == 3)
  {
    for(int i=1;i<=a;i++)
    {
      if(map[y][x+i] > 0 && map[y][x+i]!=nu)
      {
        cdist(x+i,y);
      }
      map[y][x+i] = nu;
    }
    x+=a;
  }
}

void input(int nu)
{
  x=5000;y=5000;
  //fgets(com[nu-1]);
  std::cout << "test" << '\n';
  for(int i=0;i<size[nu-1];i+=3)
  {
    dir = com[nu-1][i];
    amo = com[nu-1][i+1]-48;
    std::cout << dir <<" og "<<amo<< '\n';
    if(dir == 'U')
    {
      move(0, amo, nu);
    }
    else if(dir == 'L')
    {
      move(1, amo, nu);
    }
    else if(dir == 'D')
    {
      move(2, amo, nu);
    }
    else if(dir == 'R')
    {
      move(3, amo, nu);
    }
    else
    {
      std::cout << "ERROR" << '\n';
    }
  }
  std::cout << "end of rec" << '\n';
}

int main()
{
  input(1);
  input(2);
  return 0;
}

/*
R75,D30,R83,U83,L12,D49,R71,U7,L72,U62,R66,U55,R34,D71,R55,D58,R83
R98,U47,R26,D63,R33,U87,L62,D20,R33,U53,R51,U98,R91,D20,R16,D67,R40,U7,R15,U6,R7
*/
