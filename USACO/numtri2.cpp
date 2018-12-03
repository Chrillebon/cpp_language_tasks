/*
ID: Christi69
PROB: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

ifstream fin ("numtri.in");
ofstream fout ("numtri.out");

int numb[500500];
int sum[500500]{};
int depth, maxval;

void move(int x, int y, int val)
{
  int id=ceil(y*(1.0*(y-1)/2))+x;
  if(x!=0)
  {
    if(val+numb[id-y]>sum[id-y])
    {
      sum[id-y] = val+numb[id-y];
    }
  }
  if(x!=y-1)
  {
    if(val+numb[id-y+1]>sum[id-y+1])
    {
      sum[id-y+1] = val+numb[id-y+1];
    }
  }
  return;
}

int main()
{
  //input
  fin >> depth;
  maxval = ceil((depth+1)*(1.0*depth/2));
  for(int i=0;i<maxval;i++)
  {
    fin >> numb[i];
    sum[i]=numb[i];
  }
  for(;depth>0;depth--)
  {
    for(int o=0;o<depth;o++)
    {
      move(o, depth, sum[maxval-depth+o]);
    }
    maxval -= depth;
  }
  fout << sum[0] << '\n';
  return 0;
}
