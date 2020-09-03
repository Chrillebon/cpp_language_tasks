#include <iostream>
#include <vector>
#include <stdio.h>
#include <map>
using namespace std;

vector<long long> start{109,2050,21102,966,1,1,21101,0,13,0,1105,1,1378,21101,20,0,0,1105,1,1337,21101,27,0,0,1105,1,1279,1208,1,65,748,1005,748,73,1208,1,79,748,1005,748,110,1208,1,78,748,1005,748,132,1208,1,87,748,1005,748,169,1208,1,82,748,1005,748,239,21101,0,1041,1,21102,73,1,0,1105,1,1421,21101,0,78,1,21101,1041,0,2,21102,1,88,0,1105,1,1301,21101,0,68,1,21101,1041,0,2,21102,1,103,0,1105,1,1301,1102,1,1,750,1105,1,298,21102,1,82,1,21102,1041,1,2,21101,0,125,0,1106,0,1301,1101,2,0,750,1105,1,298,21102,1,79,1,21102,1041,1,2,21101,147,0,0,1106,0,1301,21101,0,84,1,21101,0,1041,2,21101,162,0,0,1105,1,1301,1101,0,3,750,1105,1,298,21101,0,65,1,21101,0,1041,2,21102,184,1,0,1105,1,1301,21102,76,1,1,21102,1,1041,2,21102,1,199,0,1106,0,1301,21101,0,75,1,21102,1041,1,2,21102,214,1,0,1106,0,1301,21101,221,0,0,1105,1,1337,21102,1,10,1,21101,1041,0,2,21101,236,0,0,1106,0,1301,1106,0,553,21101,85,0,1,21101,1041,0,2,21102,1,254,0,1106,0,1301,21101,0,78,1,21102,1,1041,2,21101,0,269,0,1106,0,1301,21102,276,1,0,1105,1,1337,21102,1,10,1,21102,1041,1,2,21101,291,0,0,1105,1,1301,1102,1,1,755,1106,0,553,21101,32,0,1,21102,1,1041,2,21101,313,0,0,1105,1,1301,21102,1,320,0,1106,0,1337,21102,1,327,0,1105,1,1279,2101,0,1,749,21102,1,65,2,21101,0,73,3,21102,1,346,0,1106,0,1889,1206,1,367,1007,749,69,748,1005,748,360,1102,1,1,756,1001,749,-64,751,1106,0,406,1008,749,74,748,1006,748,381,1102,-1,1,751,1106,0,406,1008,749,84,748,1006,748,395,1102,-2,1,751,1106,0,406,21102,1100,1,1,21101,406,0,0,1105,1,1421,21102,1,32,1,21101,0,1100,2,21101,421,0,0,1105,1,1301,21102,1,428,0,1106,0,1337,21102,435,1,0,1106,0,1279,1201,1,0,749,1008,749,74,748,1006,748,453,1102,-1,1,752,1105,1,478,1008,749,84,748,1006,748,467,1101,-2,0,752,1106,0,478,21102,1168,1,1,21102,1,478,0,1105,1,1421,21101,485,0,0,1105,1,1337,21101,10,0,1,21102,1,1168,2,21101,0,500,0,1106,0,1301,1007,920,15,748,1005,748,518,21102,1209,1,1,21101,0,518,0,1106,0,1421,1002,920,3,529,1001,529,921,529,1002,750,1,0,1001,529,1,537,1001,751,0,0,1001,537,1,545,1001,752,0,0,1001,920,1,920,1106,0,13,1005,755,577,1006,756,570,21101,0,1100,1,21101,570,0,0,1106,0,1421,21102,987,1,1,1105,1,581,21101,1001,0,1,21101,588,0,0,1106,0,1378,1101,0,758,594,102,1,0,753,1006,753,654,21001,753,0,1,21102,1,610,0,1106,0,667,21102,1,0,1,21101,621,0,0,1106,0,1463,1205,1,647,21101,0,1015,1,21102,635,1,0,1105,1,1378,21102,1,1,1,21102,1,646,0,1106,0,1463,99,1001,594,1,594,1106,0,592,1006,755,664,1101,0,0,755,1106,0,647,4,754,99,109,2,1101,0,726,757,22102,1,-1,1,21102,9,1,2,21101,0,697,3,21101,0,692,0,1106,0,1913,109,-2,2105,1,0,109,2,1002,757,1,706,1201,-1,0,0,1001,757,1,757,109,-2,2105,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,255,63,159,223,95,191,127,0,168,220,38,249,172,248,153,207,78,212,241,244,110,143,217,226,84,121,169,58,235,163,154,213,233,251,214,229,115,252,93,109,245,142,101,54,171,175,69,126,50,118,119,250,188,141,174,221,185,100,47,228,59,254,247,87,179,253,125,136,206,120,246,239,198,76,237,140,68,61,230,197,204,117,56,201,236,187,152,103,189,138,178,116,35,158,42,190,123,94,60,70,113,238,79,200,183,156,196,155,202,182,85,215,227,108,98,122,243,231,46,199,43,162,107,203,114,167,92,232,86,157,55,102,222,77,71,242,106,51,53,39,99,186,139,49,181,170,62,111,173,234,57,184,177,205,166,219,216,124,137,34,218,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,20,73,110,112,117,116,32,105,110,115,116,114,117,99,116,105,111,110,115,58,10,13,10,87,97,108,107,105,110,103,46,46,46,10,10,13,10,82,117,110,110,105,110,103,46,46,46,10,10,25,10,68,105,100,110,39,116,32,109,97,107,101,32,105,116,32,97,99,114,111,115,115,58,10,10,58,73,110,118,97,108,105,100,32,111,112,101,114,97,116,105,111,110,59,32,101,120,112,101,99,116,101,100,32,115,111,109,101,116,104,105,110,103,32,108,105,107,101,32,65,78,68,44,32,79,82,44,32,111,114,32,78,79,84,67,73,110,118,97,108,105,100,32,102,105,114,115,116,32,97,114,103,117,109,101,110,116,59,32,101,120,112,101,99,116,101,100,32,115,111,109,101,116,104,105,110,103,32,108,105,107,101,32,65,44,32,66,44,32,67,44,32,68,44,32,74,44,32,111,114,32,84,40,73,110,118,97,108,105,100,32,115,101,99,111,110,100,32,97,114,103,117,109,101,110,116,59,32,101,120,112,101,99,116,101,100,32,74,32,111,114,32,84,52,79,117,116,32,111,102,32,109,101,109,111,114,121,59,32,97,116,32,109,111,115,116,32,49,53,32,105,110,115,116,114,117,99,116,105,111,110,115,32,99,97,110,32,98,101,32,115,116,111,114,101,100,0,109,1,1005,1262,1270,3,1262,20102,1,1262,0,109,-1,2106,0,0,109,1,21101,0,1288,0,1105,1,1263,20101,0,1262,0,1102,0,1,1262,109,-1,2106,0,0,109,5,21101,0,1310,0,1106,0,1279,22102,1,1,-2,22208,-2,-4,-1,1205,-1,1332,22102,1,-3,1,21101,0,1332,0,1105,1,1421,109,-5,2105,1,0,109,2,21101,1346,0,0,1105,1,1263,21208,1,32,-1,1205,-1,1363,21208,1,9,-1,1205,-1,1363,1106,0,1373,21101,0,1370,0,1106,0,1279,1105,1,1339,109,-2,2105,1,0,109,5,2101,0,-4,1385,21001,0,0,-2,22101,1,-4,-4,21102,1,0,-3,22208,-3,-2,-1,1205,-1,1416,2201,-4,-3,1408,4,0,21201,-3,1,-3,1106,0,1396,109,-5,2106,0,0,109,2,104,10,21201,-1,0,1,21102,1436,1,0,1106,0,1378,104,10,99,109,-2,2106,0,0,109,3,20002,594,753,-1,22202,-1,-2,-1,201,-1,754,754,109,-3,2105,1,0,109,10,21102,5,1,-5,21101,0,1,-4,21101,0,0,-3,1206,-9,1555,21101,3,0,-6,21102,5,1,-7,22208,-7,-5,-8,1206,-8,1507,22208,-6,-4,-8,1206,-8,1507,104,64,1105,1,1529,1205,-6,1527,1201,-7,716,1515,21002,0,-11,-8,21201,-8,46,-8,204,-8,1105,1,1529,104,46,21201,-7,1,-7,21207,-7,22,-8,1205,-8,1488,104,10,21201,-6,-1,-6,21207,-6,0,-8,1206,-8,1484,104,10,21207,-4,1,-8,1206,-8,1569,21101,0,0,-9,1105,1,1689,21208,-5,21,-8,1206,-8,1583,21101,1,0,-9,1106,0,1689,1201,-5,716,1589,20102,1,0,-2,21208,-4,1,-1,22202,-2,-1,-1,1205,-2,1613,22101,0,-5,1,21101,0,1613,0,1105,1,1444,1206,-1,1634,21201,-5,0,1,21102,1,1627,0,1105,1,1694,1206,1,1634,21101,0,2,-3,22107,1,-4,-8,22201,-1,-8,-8,1206,-8,1649,21201,-5,1,-5,1206,-3,1663,21201,-3,-1,-3,21201,-4,1,-4,1105,1,1667,21201,-4,-1,-4,21208,-4,0,-1,1201,-5,716,1676,22002,0,-1,-1,1206,-1,1686,21102,1,1,-4,1105,1,1477,109,-10,2106,0,0,109,11,21102,1,0,-6,21101,0,0,-8,21102,1,0,-7,20208,-6,920,-9,1205,-9,1880,21202,-6,3,-9,1201,-9,921,1724,21002,0,1,-5,1001,1724,1,1733,20102,1,0,-4,22101,0,-4,1,21101,0,1,2,21102,1,9,3,21102,1,1754,0,1105,1,1889,1206,1,1772,2201,-10,-4,1766,1001,1766,716,1766,21001,0,0,-3,1105,1,1790,21208,-4,-1,-9,1206,-9,1786,21202,-8,1,-3,1105,1,1790,22101,0,-7,-3,1001,1733,1,1796,20102,1,0,-2,21208,-2,-1,-9,1206,-9,1812,21201,-8,0,-1,1106,0,1816,21201,-7,0,-1,21208,-5,1,-9,1205,-9,1837,21208,-5,2,-9,1205,-9,1844,21208,-3,0,-1,1106,0,1855,22202,-3,-1,-1,1106,0,1855,22201,-3,-1,-1,22107,0,-1,-1,1106,0,1855,21208,-2,-1,-9,1206,-9,1869,22102,1,-1,-8,1105,1,1873,21201,-1,0,-7,21201,-6,1,-6,1106,0,1708,22102,1,-8,-10,109,-11,2105,1,0,109,7,22207,-6,-5,-3,22207,-4,-6,-2,22201,-3,-2,-1,21208,-1,0,-6,109,-7,2105,1,0,0,109,5,1202,-2,1,1912,21207,-4,0,-1,1206,-1,1930,21101,0,0,-4,21202,-4,1,1,21202,-3,1,2,21102,1,1,3,21101,1949,0,0,1105,1,1954,109,-5,2106,0,0,109,6,21207,-4,1,-1,1206,-1,1977,22207,-5,-3,-1,1206,-1,1977,21202,-5,1,-5,1106,0,2045,22101,0,-5,1,21201,-4,-1,2,21202,-3,2,3,21101,1996,0,0,1105,1,1954,22102,1,1,-5,21102,1,1,-2,22207,-5,-3,-1,1206,-1,2015,21102,0,1,-2,22202,-3,-2,-3,22107,0,-4,-1,1206,-1,2037,22102,1,-2,1,21101,0,2037,0,106,0,1912,21202,-3,-1,-3,22201,-5,-3,-5,109,-6,2106,0,0};
int tmp, res = 0, place = 0;
long long where=0, base = 0;
map<long long, long long> list;
vector<int> parameter(4);
//vector<vector<char>> board(57, vector<char>(57));


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
    char disp;
    scanf("%1c", &disp);
    if(disp == 'n')
    {
      list[whatnum(parameter[1]+1, id+1)] = 10;
    }
    else
    {
      list[whatnum(parameter[1]+1, id+1)] = disp;
    }
    where += 2;
  }
  else if(parameter[0] == 4) //Skriver til skærmen
  {
    //std::cout << "d: " <<parameter[3]<<parameter[2]<<parameter[1]<<" "<<parameter[0]<< '\n';
    tmp = whatnum(parameter[1], id+1);
    char disp = tmp;
    std::cout << disp;
    if(tmp > 1000)
    {
      std::cout << "res: " <<tmp<< '\n';
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
  restart();
  while(list[where] != 99)
  {
    com(where);
  }
  return 0;
}

/*
Plan for 21.1: Hvis der er et hul inden for de næste 3 pladser, og den fjerde er god
NOT T T
AND A T
AND B T
AND C T
NOT T J
AND D J
WALK

Plan for 21.2: Hvis 5. og 8. er huller hopper den ikke, ellers 21.1

NOT E J
NOT H T
AND T J
AND J T
NOT J J
AND J T
NOT T T
AND A T
AND B T
AND C T
NOT T T
AND T J
AND D J
RUN

*/