#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> vel(4, vector<int>(3)); //The velocity of the four moons, x,y,z
vector<vector<int>> pos{{7,10,17},{-2,7,0},{12,5,12},{5,-8,6}}; //the posision of the four moons, x,y,z
vector<vector<int>> start = pos;

int same()
{
  int c=0;
  for(int i=0;i<4;i++)
  {
    if(pos[i][0] == start[i][0] && pos[i][1] == start[i][1] && pos[i][2] == start[i][2])
    {
      if(vel[i][0] == 0 && vel[i][1] == 0 && vel[i][2] == 0)
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

  while(!same() || steps < 0)
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
  return 0;
}
