#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
#include <utility>
using namespace std;

vector<long long> start{3,8,1005,8,319,1106,0,11,0,0,0,104,1,104,0,3,8,1002,8,-1,10,101,1,10,10,4,10,108,0,8,10,4,10,1002,8,1,28,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,102,1,8,51,2,1008,18,10,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,101,0,8,77,1,1006,8,10,1006,0,88,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,1,10,4,10,1002,8,1,106,1006,0,47,2,5,0,10,3,8,102,-1,8,10,101,1,10,10,4,10,1008,8,0,10,4,10,101,0,8,135,2,105,3,10,2,1101,6,10,3,8,102,-1,8,10,101,1,10,10,4,10,1008,8,0,10,4,10,1002,8,1,165,3,8,102,-1,8,10,101,1,10,10,4,10,108,0,8,10,4,10,1002,8,1,186,1,1009,11,10,1,9,3,10,2,1003,10,10,1,107,11,10,3,8,1002,8,-1,10,101,1,10,10,4,10,1008,8,1,10,4,10,1002,8,1,225,1006,0,25,1,1009,14,10,1,1008,3,10,3,8,102,-1,8,10,101,1,10,10,4,10,108,1,8,10,4,10,1002,8,1,257,1,1006,2,10,3,8,1002,8,-1,10,1001,10,1,10,4,10,1008,8,0,10,4,10,101,0,8,284,2,1004,7,10,1006,0,41,2,1106,17,10,1,104,3,10,101,1,9,9,1007,9,919,10,1005,10,15,99,109,641,104,0,104,1,21101,0,937108545948,1,21102,1,336,0,1105,1,440,21102,1,386577203612,1,21102,347,1,0,1105,1,440,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,3,10,104,0,104,1,3,10,104,0,104,0,3,10,104,0,104,1,21102,1,21478178819,1,21102,1,394,0,1106,0,440,21102,21477985447,1,1,21101,405,0,0,1105,1,440,3,10,104,0,104,0,3,10,104,0,104,0,21101,984458351460,0,1,21101,428,0,0,1106,0,440,21101,709048034148,0,1,21102,439,1,0,1106,0,440,99,109,2,21201,-1,0,1,21101,0,40,2,21101,471,0,3,21102,461,1,0,1105,1,504,109,-2,2106,0,0,0,1,0,0,1,109,2,3,10,204,-1,1001,466,467,482,4,0,1001,466,1,466,108,4,466,10,1006,10,498,1101,0,0,466,109,-2,2105,1,0,0,109,4,2101,0,-1,503,1207,-3,0,10,1006,10,521,21101,0,0,-3,22102,1,-3,1,21201,-2,0,2,21102,1,1,3,21102,540,1,0,1106,0,545,109,-4,2105,1,0,109,5,1207,-3,1,10,1006,10,568,2207,-4,-2,10,1006,10,568,22101,0,-4,-4,1105,1,636,21201,-4,0,1,21201,-3,-1,2,21202,-2,2,3,21102,587,1,0,1106,0,545,21202,1,1,-4,21102,1,1,-1,2207,-4,-2,10,1006,10,606,21101,0,0,-1,22202,-2,-1,-2,2107,0,-3,10,1006,10,628,22101,0,-1,1,21101,628,0,0,105,1,503,21202,-2,-1,-2,22201,-4,-2,-4,109,-5,2105,1,0};
int tmp, res, x = 0, y = 0, totcol = 0, output_mode = 0;
pair<int,int> col_dir;
int heading = 0; //0=north, matematisk positiv
long long where=0, base = 0;
map<long long, long long> list;
vector<int> parameter(4);
vector<int> size {0,0,0,0}; //min-x, min-y, max-x, max-y

map<pair<int,int>, int> bot;

void move(int color, int dir)
{
  if(!bot.count({x,y})) //Hvis den ikke har været der
  {
    totcol++;
    bot[{x,y}] = 0;
  }
  bot[{x,y}] = color;
  if(dir == 0)
  {
    heading++;
  }
  else
  {
    heading+= 3;
  }
  heading %= 4;
  //moving now:
  if(heading == 0)
  {
    y++;
  }
  else if(heading == 1)
  {
    x--;
  }
  else if(heading == 2)
  {
    y--;
  }
  else if(heading == 3)
  {
    x++;
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
    //std::cin >> list[whatnum(parameter[1]+1, id+1)];
    if(!bot.count({x,y})) //Har ikke været her før
    {
      list[whatnum(parameter[1]+1, id+1)] = 0;
    }
    else
    {
      list[whatnum(parameter[1]+1, id+1)] = bot[{x,y}];
    }
    where += 2;
  }
  else if(parameter[0] == 4) //Skriver til skærmen
  {
    //std::cout << "d: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    //std::cout << whatnum(parameter[1], id+1) << '\n';
    if(output_mode == 0)
    {
      col_dir.first = whatnum(parameter[1],id+1);
    }
    else
    {
      col_dir.second = whatnum(parameter[1],id+1);
      move(col_dir.first, col_dir.second);
    }
    output_mode++;
    output_mode %= 2;

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
  restart();
  while(list[where] != 99)
  {
    com(where);
  }
  std::cout << "res: " <<totcol<< '\n';
  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
