#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

vector<long long> start{1102,34463338,34463338,63,1007,63,34463338,63,1005,63,53,1102,3,1,1000,109,988,209,12,9,1000,209,6,209,3,203,0,1008,1000,1,63,1005,63,65,1008,1000,2,63,1005,63,904,1008,1000,0,63,1005,63,58,4,25,104,0,99,4,0,104,0,99,4,17,104,0,99,0,0,1102,1,21,1008,1101,427,0,1028,1102,23,1,1012,1101,32,0,1009,1101,37,0,1007,1102,1,892,1023,1102,27,1,1004,1102,1,38,1013,1102,1,20,1005,1101,0,29,1001,1101,0,22,1015,1102,1,35,1003,1101,0,39,1016,1102,34,1,1011,1101,899,0,1022,1102,195,1,1024,1101,36,0,1014,1101,0,24,1000,1102,1,31,1006,1101,0,28,1017,1101,422,0,1029,1102,1,33,1019,1102,1,26,1018,1102,1,0,1020,1102,25,1,1002,1102,712,1,1027,1101,0,190,1025,1101,0,715,1026,1102,1,1,1021,1101,30,0,1010,109,30,2105,1,-6,4,187,1106,0,199,1001,64,1,64,1002,64,2,64,109,-19,1206,10,211,1106,0,217,4,205,1001,64,1,64,1002,64,2,64,109,-13,1202,8,1,63,1008,63,28,63,1005,63,241,1001,64,1,64,1106,0,243,4,223,1002,64,2,64,109,8,1201,-2,0,63,1008,63,29,63,1005,63,263,1105,1,269,4,249,1001,64,1,64,1002,64,2,64,109,-9,2101,0,3,63,1008,63,24,63,1005,63,295,4,275,1001,64,1,64,1106,0,295,1002,64,2,64,109,12,2107,31,0,63,1005,63,317,4,301,1001,64,1,64,1106,0,317,1002,64,2,64,109,7,21101,40,0,0,1008,1016,43,63,1005,63,341,1001,64,1,64,1106,0,343,4,323,1002,64,2,64,109,-14,1208,-1,31,63,1005,63,363,1001,64,1,64,1106,0,365,4,349,1002,64,2,64,109,9,1208,-6,20,63,1005,63,387,4,371,1001,64,1,64,1105,1,387,1002,64,2,64,109,2,2102,1,-7,63,1008,63,31,63,1005,63,413,4,393,1001,64,1,64,1106,0,413,1002,64,2,64,109,21,2106,0,-6,4,419,1106,0,431,1001,64,1,64,1002,64,2,64,109,-25,2108,35,-6,63,1005,63,449,4,437,1106,0,453,1001,64,1,64,1002,64,2,64,109,3,21107,41,42,0,1005,1012,471,4,459,1105,1,475,1001,64,1,64,1002,64,2,64,109,7,21108,42,39,-2,1005,1017,495,1001,64,1,64,1105,1,497,4,481,1002,64,2,64,109,-8,1206,9,515,4,503,1001,64,1,64,1106,0,515,1002,64,2,64,109,4,1205,6,529,4,521,1105,1,533,1001,64,1,64,1002,64,2,64,109,-8,2107,26,-5,63,1005,63,553,1001,64,1,64,1106,0,555,4,539,1002,64,2,64,109,-6,2102,1,1,63,1008,63,26,63,1005,63,575,1105,1,581,4,561,1001,64,1,64,1002,64,2,64,109,10,2101,0,-8,63,1008,63,37,63,1005,63,601,1105,1,607,4,587,1001,64,1,64,1002,64,2,64,109,-19,1207,8,23,63,1005,63,627,1001,64,1,64,1106,0,629,4,613,1002,64,2,64,109,18,21101,43,0,3,1008,1013,43,63,1005,63,655,4,635,1001,64,1,64,1106,0,655,1002,64,2,64,109,-16,1207,6,25,63,1005,63,677,4,661,1001,64,1,64,1106,0,677,1002,64,2,64,109,25,21102,44,1,-4,1008,1015,44,63,1005,63,703,4,683,1001,64,1,64,1106,0,703,1002,64,2,64,109,17,2106,0,-9,1106,0,721,4,709,1001,64,1,64,1002,64,2,64,109,-16,1205,0,737,1001,64,1,64,1105,1,739,4,727,1002,64,2,64,109,-12,21107,45,44,5,1005,1013,759,1001,64,1,64,1106,0,761,4,745,1002,64,2,64,109,4,1201,-8,0,63,1008,63,27,63,1005,63,783,4,767,1106,0,787,1001,64,1,64,1002,64,2,64,109,-16,2108,25,4,63,1005,63,803,1105,1,809,4,793,1001,64,1,64,1002,64,2,64,109,27,21102,46,1,-5,1008,1018,43,63,1005,63,829,1106,0,835,4,815,1001,64,1,64,1002,64,2,64,109,-27,1202,8,1,63,1008,63,27,63,1005,63,857,4,841,1105,1,861,1001,64,1,64,1002,64,2,64,109,23,21108,47,47,-2,1005,1017,883,4,867,1001,64,1,64,1106,0,883,1002,64,2,64,109,-1,2105,1,5,1001,64,1,64,1106,0,901,4,889,4,64,99,21102,1,27,1,21102,915,1,0,1105,1,922,21201,1,29589,1,204,1,99,109,3,1207,-2,3,63,1005,63,964,21201,-2,-1,1,21102,1,942,0,1106,0,922,21202,1,1,-1,21201,-2,-3,1,21102,957,1,0,1105,1,922,22201,1,-1,-2,1106,0,968,21202,-2,1,-2,109,-3,2106,0,0};
int tmp, res;
long long where=0, base = 0;
map<long long, long long> list;
vector<int> parameter(4);

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
    std::cin >> list[whatnum(parameter[1]+1, id+1)];
    where += 2;
  }
  else if(parameter[0] == 4) //Skriver til skærmen
  {
    //std::cout << "d: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    std::cout << whatnum(parameter[1], id+1) << '\n';
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
  return 0;
}

/*
1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,6,1,19,1,19,5,23,2,10,23,27,2,27,13,31,1,10,31,35,1,35,9,39,2,39,13,43,1,43,5,47,1,47,6,51,2,6,51,55,1,5,55,59,2,9,59,63,2,6,63,67,1,13,67,71,1,9,71,75,2,13,75,79,1,79,10,83,2,83,9,87,1,5,87,91,2,91,6,95,2,13,95,99,1,99,5,103,1,103,2,107,1,107,10,0,99,2,0,14,0
*/
