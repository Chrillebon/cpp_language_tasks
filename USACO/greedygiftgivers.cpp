/*
ID: Christi69
PROB: gift1
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  ofstream fout ("gift1.out");
  ifstream fin ("gift1.in");
  int NP;
  fin >> NP;
  vector<string> startpos;
  map<string, int> GGG;
  map<string, int> START;
  string name;
  for(int i=0; i<NP; i++)
  {
    fin >> name;
    GGG[name] = 0;
    startpos.push_back(name);
  }
  int money, GT;
  for(int o=0; o<NP; o++)
  {
    fin >> name;
    fin >> money >> GT;
    START[name] = money;
    if(GT)
    {
      GGG[name] += money % GT;
      for(int i=0; i<GT; i++)
      {
        fin >> name;
        GGG[name] += money/GT;
      }
    }
    else
    {
      GGG[name] += money;
    }
  }
  for(int i=0; i<NP; i++)
  {
    fout << startpos[i] <<" "<<GGG[startpos[i]]-START[startpos[i]]<< '\n';
  }
  return 0;
}
