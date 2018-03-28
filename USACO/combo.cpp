/*
ID: Christi69
PROB: combo
LANG: C++
*/

#include <iostream>
#include <fstream>
using namespace std;

ifstream fin ("combo.in");
ofstream fout ("combo.out");

int farmer[3], master[3], N;

int close(int a, int b, int c)
{
  int abc[3] = {a, b, c}, f=0, m=0;
  for(int i=0;i<3;i++)
  {
    if(abs(abc[i]-farmer[i]) <= 2 ||
    abs((abc[i]+N)-farmer[i]) <= 2 ||
    abs(abc[i]-(farmer[i]+N)) <= 2)
    {
      f++;
    }
    if(abs(abc[i]-master[i]) <= 2 ||
    abs((abc[i]+N)-master[i]) <= 2 ||
    abs(abc[i]-(master[i]+N)) <= 2)
    {
      m++;
    }
  }
  if(m==3 || f==3)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  int res = 0;
  fin >> N;
  fin >> farmer[0] >> farmer[1] >> farmer[2];
  fin >> master[0] >> master[1] >> master[2];
  for(int i=0;i<N;i++)
  {
    for(int o=0;o<N;o++)
    {
      for(int u=0;u<N;u++)
      {
        if(close(i,o,u))
        {
          res++;
        }
      }
    }
  }
  fout << res << '\n';
  return 0;
}
