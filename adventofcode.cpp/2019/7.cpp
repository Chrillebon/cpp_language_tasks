#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

vector<int> start{3,52,1001,52,-5,52,3,53,1,52,56,54,1007,54,5,55,1005,55,26,1001,54,
-5,54,1105,1,12,1,53,54,53,1008,54,0,55,1001,55,1,55,2,53,55,53,4,
53,1001,56,-1,56,1005,56,6,99,0,0,0,0,10};
int tmp, res;
int where=0, amp = 0, high = -9999;
vector<int> list;
vector<int> parameter(4);
vector<int> best{-1,-1,-1,-1,-1};
vector<int> seq{9,0,7,0,8,0,5,0,6,0,0,0}; //Hver anden er seq, de ulige er amp.
//   settings:  ^   ^   ^   ^   ^
vector<vector<int>> allopt{{0,1,2,3,4}, {0,1,2,4,3}, {0,1,3,2,4}, {0,1,3,4,2}, {0,1,4,2,3}, {0,1,4,3,2}, {0,2,1,3,4}, {0,2,1,4,3}, {0,2,3,1,4}, {0,2,3,4,1}, {0,2,4,1,3}, {0,2,4,3,1}, {0,3,1,2,4}, {0,3,1,4,2}, {0,3,2,1,4}, {0,3,2,4,1}, {0,3,4,1,2}, {0,3,4,2,1}, {0,4,1,2,3}, {0,4,1,3,2}, {0,4,2,1,3}, {0,4,2,3,1}, {0,4,3,1,2}, {0,4,3,2,1}, {1,0,2,3,4}, {1,0,2,4,3}, {1,0,3,2,4}, {1,0,3,4,2}, {1,0,4,2,3}, {1,0,4,3,2}, {1,2,0,3,4}, {1,2,0,4,3}, {1,2,3,0,4}, {1,2,3,4,0}, {1,2,4,0,3}, {1,2,4,3,0}, {1,3,0,2,4}, {1,3,0,4,2}, {1,3,2,0,4}, {1,3,2,4,0}, {1,3,4,0,2}, {1,3,4,2,0}, {1,4,0,2,3}, {1,4,0,3,2}, {1,4,2,0,3}, {1,4,2,3,0}, {1,4,3,0,2}, {1,4,3,2,0}, {2,0,1,3,4}, {2,0,1,4,3}, {2,0,3,1,4}, {2,0,3,4,1}, {2,0,4,1,3}, {2,0,4,3,1}, {2,1,0,3,4}, {2,1,0,4,3}, {2,1,3,0,4}, {2,1,3,4,0}, {2,1,4,0,3}, {2,1,4,3,0}, {2,3,0,1,4}, {2,3,0,4,1}, {2,3,1,0,4}, {2,3,1,4,0}, {2,3,4,0,1}, {2,3,4,1,0}, {2,4,0,1,3}, {2,4,0,3,1}, {2,4,1,0,3}, {2,4,1,3,0}, {2,4,3,0,1}, {2,4,3,1,0}, {3,0,1,2,4}, {3,0,1,4,2}, {3,0,2,1,4}, {3,0,2,4,1}, {3,0,4,1,2}, {3,0,4,2,1}, {3,1,0,2,4}, {3,1,0,4,2}, {3,1,2,0,4}, {3,1,2,4,0}, {3,1,4,0,2}, {3,1,4,2,0}, {3,2,0,1,4}, {3,2,0,4,1}, {3,2,1,0,4}, {3,2,1,4,0}, {3,2,4,0,1}, {3,2,4,1,0}, {3,4,0,1,2}, {3,4,0,2,1}, {3,4,1,0,2}, {3,4,1,2,0}, {3,4,2,0,1}, {3,4,2,1,0}, {4,0,1,2,3}, {4,0,1,3,2}, {4,0,2,1,3}, {4,0,2,3,1}, {4,0,3,1,2}, {4,0,3,2,1}, {4,1,0,2,3}, {4,1,0,3,2}, {4,1,2,0,3}, {4,1,2,3,0}, {4,1,3,0,2}, {4,1,3,2,0}, {4,2,0,1,3}, {4,2,0,3,1}, {4,2,1,0,3}, {4,2,1,3,0}, {4,2,3,0,1}, {4,2,3,1,0}, {4,3,0,1,2}, {4,3,0,2,1}, {4,3,1,0,2}, {4,3,1,2,0}, {4,3,2,0,1}, {4,3,2,1,0}};

void restart()
{
  list.clear();
  where = 0;
  for(int i=0;i<start.size();i++)
  {
    list.push_back(start[i]);
  }
  return;
}

void new_set(int a)
{
  seq[1] = 0;

  seq[0] = allopt[a][0];
  seq[2] = allopt[a][1];
  seq[4] = allopt[a][2];
  seq[6] = allopt[a][3];
  seq[8] = allopt[a][4];
  return;
}

void split(int nu)
{
  parameter[0] = nu % 100;
  parameter[1] = nu / 100 % 10;
  parameter[2] = nu / 1000 % 10;
  parameter[3] = nu / 10000 % 10;
}

int whatnum(int par, int id)
{
  if(par == 0)
  {
    return list[list[id]];
  }
  if(par == 1)
  {
    return list[id];
  }
}

void com(int id)
{
  split(list[id]);
  if(parameter[0] == 1)
  {
    //std::cout << "adding " <<list[list[id+1]]<<" med "<<list[list[id+2]]<< '\n';
    list[list[id+3]] = whatnum(parameter[1], id+1) + whatnum(parameter[2],id+2);
    where += 4;
  }
  else if(parameter[0] == 2)
  {
    //std::cout << "ganger " <<list[list[id+1]]<<" med "<<list[list[id+2]]<< '\n';
    list[list[id+3]] = whatnum(parameter[1], id+1) * whatnum(parameter[2],id+2);
    where += 4;
  }
  else if(parameter[0] == 3)
  {
    std::cin >> list[list[id+1]];
    //list[list[id+1]] = seq[amp];
    amp++;
    where += 2;
  }
  else if(parameter[0] == 4) //No longer cout-ing
  {
    std::cout << list[list[id+1]] << '\n';
    //seq[amp+1] = list[list[id+1]];
    //std::cout << "step: " <<amp/2<<" er nu: "<<seq[amp+1]<<" i "<<amp+1<< '\n';
    where += 2;
  }
  else if(parameter[0] == 5)
  {
    if(whatnum(parameter[1], id+1))
    {
      where = whatnum(parameter[2], id+2);
    }
    else
    {
      where += 3;
    }
  }
  else if(parameter[0] == 6)
  {
    if(!whatnum(parameter[1], id+1))
    {
      where = whatnum(parameter[2], id+2);
    }
    else
    {
      where += 3;
    }
  }
  else if(parameter[0] == 7)
  {
    list[list[id+3]] = (whatnum(parameter[1], id+1) < whatnum(parameter[2], id+2));
    where += 4;
  }
  else if(parameter[0] == 8)
  {
    list[list[id+3]] = (whatnum(parameter[1], id+1) == whatnum(parameter[2], id+2));
    where += 4;
  }
  else
  {
    std::cout << "ERROR!!!" << '\n';
  }
  return;
}

int main()
{
  for(int i=0;i<120;i++)
  {
    //new_set(i);
    restart();
    for(int o=0;o<5;o++)
    {
      while(list[where] != 99 || where >= list.size())
      {
        com(where);
      }
      std::cout << "done!" << '\n';
      where = 0;
    }
    if(seq[11] > high)
    {
      best[0] = seq[0];
      best[1] = seq[2];
      best[2] = seq[4];
      best[3] = seq[6];
      best[4] = seq[8];
    }
    high = max(high, seq[11]);
  }
  std::cout << "res= " <<high<<" from "<<best[0]<<best[1]<<best[2]<<best[3]<<best[4]<< '\n';

  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
