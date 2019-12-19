#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

vector<long long> start{109,424,203,1,21102,11,1,0,1105,1,282,21101,0,18,0,1105,1,259,2101,0,1,221,203,1,21102,1,31,0,1105,1,282,21102,1,38,0,1105,1,259,20102,1,23,2,21201,1,0,3,21102,1,1,1,21102,57,1,0,1106,0,303,2102,1,1,222,21002,221,1,3,20101,0,221,2,21101,0,259,1,21101,0,80,0,1105,1,225,21101,44,0,2,21102,91,1,0,1105,1,303,1202,1,1,223,21002,222,1,4,21102,259,1,3,21102,1,225,2,21102,225,1,1,21101,118,0,0,1106,0,225,21002,222,1,3,21101,163,0,2,21101,0,133,0,1106,0,303,21202,1,-1,1,22001,223,1,1,21102,148,1,0,1106,0,259,1202,1,1,223,20101,0,221,4,21001,222,0,3,21102,1,24,2,1001,132,-2,224,1002,224,2,224,1001,224,3,224,1002,132,-1,132,1,224,132,224,21001,224,1,1,21101,195,0,0,105,1,108,20207,1,223,2,21002,23,1,1,21102,-1,1,3,21102,1,214,0,1106,0,303,22101,1,1,1,204,1,99,0,0,0,0,109,5,2101,0,-4,249,22102,1,-3,1,22101,0,-2,2,22101,0,-1,3,21102,250,1,0,1106,0,225,21202,1,1,-4,109,-5,2105,1,0,109,3,22107,0,-2,-1,21202,-1,2,-1,21201,-1,-1,-1,22202,-1,-2,-2,109,-3,2106,0,0,109,3,21207,-2,0,-1,1206,-1,294,104,0,99,22102,1,-2,-2,109,-3,2105,1,0,109,5,22207,-3,-4,-1,1206,-1,346,22201,-4,-3,-4,21202,-3,-1,-1,22201,-4,-1,2,21202,2,-1,-1,22201,-4,-1,1,21202,-2,1,3,21101,0,343,0,1106,0,303,1106,0,415,22207,-2,-3,-1,1206,-1,387,22201,-3,-2,-3,21202,-2,-1,-1,22201,-3,-1,3,21202,3,-1,-1,22201,-3,-1,2,21201,-4,0,1,21101,384,0,0,1105,1,303,1105,1,415,21202,-4,-1,-4,22201,-4,-3,-4,22202,-3,-2,-2,22202,-2,-4,-4,22202,-3,-2,-3,21202,-4,-1,-2,22201,-3,-2,1,21202,1,1,-4,109,-5,2105,1,0};
int tmp, res = 0, place = 0;
long long where=0, base = 0;
map<long long, long long> list;
vector<int> parameter(4);
pair<int,int> xy;
vector<vector<char>> look(50, vector<char>(50));

void display()
{
  for(int i=0;i<50;i++)
  {
    for(int o=0;o<50;o++)
    {
      std::cout << look[o][i];
    }
    std::cout << '\n';
  }
}

void debug()
{
  for(map<long long, long long>::iterator it=list.begin();it!=list.end();it++)
  {
    std::cout << it->first<<",";
  }
  std::cout << '\n';
  for(map<long long, long long>::iterator it=list.begin();it!=list.end();it++)
  {
    std::cout << it->second<<",";
  }
  std::cout << '\n';
  std::cout << "Vi er ved: " <<where<<" og basen er: "<<base<< '\n'<<'\n';
  return;
}

void restart()
{
  list.clear();
  where = 0;
  for(int i=0;i<start.size();i++)
  {
    list[i] = start[i]; //mapping value to index
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

long long whatnum(int par, long long id)
{
  if(par == 0)
  {
    if(list.count(id) == 0) //Hvis den peger på én der ikke findes, peger den på 0:
    {
      return list[0];
    }
    else if(list.count(list[id]) == 0) //Hvis den der peges på peger ud i intet, returnerer den 0
    {
      return 0;
    }
    else
    {
      return list[list[id]];
    }
  }
  else if(par == 1)
  {
    if(list.count(id) == 0)
    {
      return 0;
    }
    else
    {
      return list[id];
    }
  }
  else if(par == 2)
  {
    return whatnum(1, list[id]+base);
  }
  else if(par == 3)
  {
    return list[id]+base;
  }
}

void com(int id)
{
  split(list[id]);
  //debug();
  if(parameter[0] == 1) //Ligger sammen
  {
    //std::cout << "a: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    list[whatnum(parameter[3]+1, id+3)] = whatnum(parameter[1], id+1) + whatnum(parameter[2],id+2);
    //For at forklare hvad f**k der sker her har jeg brug for nogle linjer:
    //Jeg skal bruge whatnum-funktionen, men den returnerer værdien, så Jeg
    //ligger én til for at få pointeren i stedet. dette passer endnu med den
    // stillede opgave. Dette gentager sig videre i de andre opgaver.
    where += 4;
  }
  else if(parameter[0] == 2) //Ganger sammen
  {
    //std::cout << "b: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    list[whatnum(parameter[3]+1, id+3)] = whatnum(parameter[1], id+1) * whatnum(parameter[2],id+2);
    where += 4;
  }
  else if(parameter[0] == 3) //Tager input
  {
    //std::cout << "c: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    if(place >= 5000)
    {
      std::cout << "END!!!" << '\n';
    }
    if(place % 2 == 0) //First input
    {
      list[whatnum(parameter[1]+1, id+1)] = (place/2) % 50; //x
      xy.first = (place/2) % 50;
      //std::cout << "tester: " <<list[whatnum(parameter[1]+1, id+1)]<< ", ";
    }
    else
    {
      list[whatnum(parameter[1]+1, id+1)] = (place/2) / 50; //y
      xy.second = (place/2) / 50;
      //std::cout << list[whatnum(parameter[1]+1, id+1)] << " med: "<< place<< '\n';
    }
    place++;

    where += 2;
  }
  else if(parameter[0] == 4) //Skriver til skærmen
  {
    //std::cout << "d: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    if(whatnum(parameter[1], id+1))
    {
      //std::cout << "ding" << '\n';
      res++;
      look[xy.first][xy.second] = '#';
    }
    else
    {
      look[xy.first][xy.second] = '.';
    }

    where += 2;
  }
  else if(parameter[0] == 5) //Hop, hvis pointer == 1
  {
    //std::cout << "e: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    if(whatnum(parameter[1], id+1))
    {
      where = whatnum(parameter[2], id+2);
    }
    else
    {
      where += 3;
    }
  }
  else if(parameter[0] == 6) //Hop, hvis pointer == 0
  {
    //std::cout << "f: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    if(!whatnum(parameter[1], id+1))
    {
      where = whatnum(parameter[2], id+2);
    }
    else
    {
      where += 3;
    }
  }
  else if(parameter[0] == 7) //T/F er 1. mindre end 2.
  {
    //std::cout << "g: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    list[whatnum(parameter[3]+1, id+3)] = (whatnum(parameter[1], id+1) < whatnum(parameter[2], id+2));
    where += 4;
  }
  else if(parameter[0] == 8) //T/F er 1. == 2.
  {
    //std::cout << "h: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    list[whatnum(parameter[3]+1, id+3)] = (whatnum(parameter[1], id+1) == whatnum(parameter[2], id+2));
    where += 4;
  }
  else if(parameter[0] == 9) //Ændrer basen
  {
    //std::cout << "i: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    base += whatnum(parameter[1], id+1);
    where += 2;
  }
  else
  {
    std::cout << "ERROR!!!" << '\n';
  }
  return;
}

int main()
{
  while(place < 5000)
  {
    restart();
    while(list[where] != 99)
    {
      com(where);
    }
  }
  std::cout << "the end result is: " <<res<< '\n';
  display();
  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
