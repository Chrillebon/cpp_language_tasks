#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> vel(4, vector<int>(3)); //The velocity of the four moons, x,y,z
vector<vector<int>> pos{{7,10,17},{-2,7,0},{12,5,12},{5,-8,6}}; //the posision of the four moons, x,y,z

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

void disp(int s)
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
  int steps = 0;
  while(steps < 1000)
  {
    //disp(steps);
    for(int i=0;i<4;i++)
    {
      speed(i);
    }
    move();
    steps++;
  }
  disp(steps);
  std::cout << energy() << '\n';
  return 0;
}
