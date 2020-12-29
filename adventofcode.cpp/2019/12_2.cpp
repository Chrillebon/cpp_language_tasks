#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> vel(4, vector<int>(3)); //The velocity of the four moons, x,y,z
vector<vector<int>> pos{{7,10,17},{-2,7,0},{12,5,12},{5,-8,6}}; //the posision of the four moons, x,y,z
vector<vector<int>> start = pos;

int same(int axis)
{
  // 0 for x axis, 1 for y axis, 2 for z axis
  int c=0;
  for(int i=0;i<4;i++)
  {
    if(pos[i][axis] == start[i][axis])
    {
      if(vel[i][axis] == 0)
      {
        c++;
      }
    }
  }
  if(c == 4)
  {
    return 1;
  }
  return 0;
}

int energy()
{
  int total = 0;
  for(int i=0;i<4;i++)
  {
    int epot = abs(pos[i][0])+abs(pos[i][1])+abs(pos[i][2]);
    int ekin = abs(vel[i][0])+abs(vel[i][1])+abs(vel[i][2]);
    total += epot*ekin;
  }
  return total;
}

void disp(long long s)
{
  std::cout << "After " <<s<<" steps:"<< '\n';
  for(int i=0;i<4;i++)
  {
    std::cout << "pos=<x=" <<pos[i][0]<<", y="<<pos[i][1]<<", z="<<pos[i][2]<<">,    vel=<x="<<vel[i][0]<<", y="<<vel[i][1]<<", z="<<vel[i][2]<<">"<< '\n';
  }
  std::cout << '\n';
}

void speed(int m)
{
  for(int i=0;i<4;i++) //For de andre objekter
  {
    if(i != m)
    {
      for(int o=0;o<3;o++) //x,y,z
      {
        if(pos[i][o] > pos[m][o])
        {
          vel[m][o]++;
        }
        else if(pos[i][o] < pos[m][o])
        {
          vel[m][o]--;
        }
      }
    }
  }
  return;
}

void move()
{
  for(int i=0;i<4;i++)
  {
    for(int o=0;o<3;o++)
    {
      pos[i][o] += vel[i][o];
    }
  }
  return;
}

int main()
{
  long long steps = 0;
  for(int i=0;i<4;i++)
  {
    speed(i);
  }
  move();
  steps++;

  // Skift argument i same mellem 0, 1 og 2
  // Dette gøres, da x, y og z er uafhængige af hinanden,
  // Hvormed vi kan regne os til samlet tid før gentagelse

  while(!same(2) || steps < 0)
  {
    if(steps % 1000000 == 0)
    {
      std::cout << steps << '\n';
    }
    //std::cout << steps << '\n';
    //disp(steps);
    for(int i=0;i<4;i++)
    {
      speed(i);
    }
    move();
    steps++;
  }
  disp(steps);

  /*
  x-axis tager 28482 iterationer før gentagelse
  y-axis tager 231614 iterationer før gentagelse
  z-axis tager 193052 iterationer før gentagelse

  Mindst fælles multiplum er:
  318382803780324
  */
  return 0;
}
