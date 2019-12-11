#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>
using namespace std;

vector<int> start{3,26,1001,26,-4,26,3,27,1002,27,2,27,1,27,26,
27,4,27,1001,28,-1,28,1005,28,6,99,0,0,5};
int tmp, res;
int where=0, amp = 0;
pair<int,int> ls = {0,1};
long long high = -9999;
vector<int> list;
vector<int> parameter(4);
vector<int> best{-1,-1,-1,-1,-1};
vector<int> settings{0,0,0,0,0};
vector<long long> seq{0,0,0,0,0,0};
vector<vector<int>> allopt{{5,6,7,8,9}, {5,6,7,9,8}, {5,6,8,7,9}, {5,6,8,9,7}, {5,6,9,7,8}, {5,6,9,8,7}, {5,7,6,8,9}, {5,7,6,9,8}, {5,7,8,6,9}, {5,7,8,9,6}, {5,7,9,6,8}, {5,7,9,8,6}, {5,8,6,7,9}, {5,8,6,9,7}, {5,8,7,6,9}, {5,8,7,9,6}, {5,8,9,6,7}, {5,8,9,7,6}, {5,9,6,7,8}, {5,9,6,8,7}, {5,9,7,6,8}, {5,9,7,8,6}, {5,9,8,6,7}, {5,9,8,7,6}, {6,5,7,8,9}, {6,5,7,9,8}, {6,5,8,7,9}, {6,5,8,9,7}, {6,5,9,7,8}, {6,5,9,8,7}, {6,7,5,8,9}, {6,7,5,9,8}, {6,7,8,5,9}, {6,7,8,9,5}, {6,7,9,5,8}, {6,7,9,8,5}, {6,8,5,7,9}, {6,8,5,9,7}, {6,8,7,5,9}, {6,8,7,9,5}, {6,8,9,5,7}, {6,8,9,7,5}, {6,9,5,7,8}, {6,9,5,8,7}, {6,9,7,5,8}, {6,9,7,8,5}, {6,9,8,5,7}, {6,9,8,7,5}, {7,5,6,8,9}, {7,5,6,9,8}, {7,5,8,6,9}, {7,5,8,9,6}, {7,5,9,6,8}, {7,5,9,8,6}, {7,6,5,8,9}, {7,6,5,9,8}, {7,6,8,5,9}, {7,6,8,9,5}, {7,6,9,5,8}, {7,6,9,8,5}, {7,8,5,6,9}, {7,8,5,9,6}, {7,8,6,5,9}, {7,8,6,9,5}, {7,8,9,5,6}, {7,8,9,6,5}, {7,9,5,6,8}, {7,9,5,8,6}, {7,9,6,5,8}, {7,9,6,8,5}, {7,9,8,5,6}, {7,9,8,6,5}, {8,5,6,7,9}, {8,5,6,9,7}, {8,5,7,6,9}, {8,5,7,9,6}, {8,5,9,6,7}, {8,5,9,7,6}, {8,6,5,7,9}, {8,6,5,9,7}, {8,6,7,5,9}, {8,6,7,9,5}, {8,6,9,5,7}, {8,6,9,7,5}, {8,7,5,6,9}, {8,7,5,9,6}, {8,7,6,5,9}, {8,7,6,9,5}, {8,7,9,5,6}, {8,7,9,6,5}, {8,9,5,6,7}, {8,9,5,7,6}, {8,9,6,5,7}, {8,9,6,7,5}, {8,9,7,5,6}, {8,9,7,6,5}, {9,5,6,7,8}, {9,5,6,8,7}, {9,5,7,6,8}, {9,5,7,8,6}, {9,5,8,6,7}, {9,5,8,7,6}, {9,6,5,7,8}, {9,6,5,8,7}, {9,6,7,5,8}, {9,6,7,8,5}, {9,6,8,5,7}, {9,6,8,7,5}, {9,7,5,6,8}, {9,7,5,8,6}, {9,7,6,5,8}, {9,7,6,8,5}, {9,7,8,5,6}, {9,7,8,6,5}, {9,8,5,6,7}, {9,8,5,7,6}, {9,8,6,5,7}, {9,8,6,7,5}, {9,8,7,5,6}, {9,8,7,6,5}};

void debug()
{
  for(int i=0;i<list.size();i++)
  {
    std::cout << list[i]<<",";
  }
  std::cout << '\n';
  std::cout << "Vi er ved: " <<where<< '\n'<<'\n';
  return;
}

void restart()
{
  list.clear();
  where = 0;
  for(int i=0;i<start.size();i++)
  {
    list.push_back(start[i]);
  }
  for(int i=0;i<6;i++)
  {
    seq[i] = 0;
  }
  ls.first = 0;
  ls.second = 1;
  return;
}

void new_set(int a)
{
  seq[1] = 0;

  for(int i=0;i<5;i++)
  {
    settings[i] = allopt[a][i];
  }
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
  //debug();
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
    //std::cout << "læser id: " <<amp<< '\n';
    if(ls.second == 0 || ls.first >= 5) //Beder om amp-output
    {
      std::cout << "- ";
      if(amp >= 5) //feedback loop...
      {
        amp = 0;
      }
      if(amp == 0) //amp A tager E
      {
        std::cout << seq[4] << '\n';
        list[list[id+1]] = seq[4];
      }
      else
      {
        std::cout << seq[amp] << '\n';
        list[list[id+1]] = seq[amp];
      }
    }
    else //Beder om indstillingerne
    {
      std::cout << "beder om setting: " <<ls.first<< '\n';
      list[list[id+1]] = settings[ls.first];
      ls.first++;
      ls.second = 0;
    }
    where += 2;
  }
  else if(parameter[0] == 4) //No longer cout-ing
  {
    //std::cout << "+" << '\n';
    seq[amp] = list[list[id+1]];
    std::cout << "gemmer "<<list[list[id+1]]<<" i: " <<amp<< '\n';
    ls.second = 1;
    amp++;
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
    restart();
    new_set(i);
    amp = 0;
    while(list[where] != 99 || where >= list.size())
    {
      com(where);
    }
    if(seq[4] > high)
    {
      best[0] = seq[0];
      best[1] = seq[1];
      best[2] = seq[2];
      best[3] = seq[3];
      best[4] = seq[4];
    }
    std::cout << "Got: " <<seq[4]<< '\n';
    high = max(high, seq[4]);
  }
  std::cout << "res= " <<high<<" from "<<best[0]<<","<<best[1]<<","<<best[2]<<","<<best[3]<<","<<best[4]<< '\n';

  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
