#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

vector<int> start{1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0};
int tmp, res;
vector<int> list;

void restart()
{
  list.clear();
  for(int i=0;i<start.size();i++)
  {
    list.push_back(start[i]);
  }
  return;
}

void com(int id)
{
  if(list[id] == 1)
  {
    //std::cout << "adding " <<list[list[id+1]]<<" med "<<list[list[id+2]]<< '\n';
    list[list[id+3]] = list[list[id+1]] + list[list[id+2]];
  }
  else if(list[id] == 2)
  {
    //std::cout << "ganger " <<list[list[id+1]]<<" med "<<list[list[id+2]]<< '\n';
    list[list[id+3]] = list[list[id+1]] * list[list[id+2]];
  }
  else
  {
    std::cout << "ERROR!!!" << '\n';
  }
  return;
}

int main()
{
  int where=0;
  restart();
  for(int a=0;a<100;a++)
  {
    for(int b=0;b<100;b++)
    {
      restart();
      where = 0;
      list[1] = a;
      list[2] = b;
      while(list[where] != 99 || where >= list.size())
      {
        //std::cout << "testing " <<where<< '\n';
        com(where);
        where+=4;
      }
      if(list[0] == 19690720)
      {
        std::cout << "svaret er: " <<a<< " og "<<b<<" lig med: "<<100*a+b<< '\n';
      }
    }
  }
  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
