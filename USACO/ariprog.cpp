/*
ID: Christi69
PROB: ariprog
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

ifstream fin ("ariprog.in");
ofstream fout ("ariprog.out");

int N, M, maxval;

/*
Math:

Tal: p,q: 1	2	3	4	5	6	7	8	9	10
(p,q)^2: 1 4 9 16 25 36 49 64 81 100
Diff: 1 3 5 7 9 11 13 15 17 19
MAGIX
*/

int onehigher(int val, int step)
{
  int res = 0, p = -1, q = -1;
  while(res < val+step && p/2 +1 <= M) //Math, se toppen:
  {
    p += 2;
    res += p;
  }
  if(res == val+step && p/2 +1 <= M)
  {
    return 1;
  }
  else
  {
    res -= p;
  }
  while(p>q)
  {
    p -= 2;
    while(res < val+step) //For andet tal
    {
      q += 2;
      res += q;
    }
    if(res == val+step)
    {
      return 1;
    }
    else
    {
      res -= p;
      res -= q;
      q -= 2;
    }
  }
  return 0;
}

int ariprog(int val, int step)
{
  int res = 0, i = -1;
  while(val+step*i < maxval)
  {
    if(onehigher(val+step*i, step))
    {
      res++;
    }
    else
    {
      res = 0;
    }
    if(res >= N)
    {
      cout << val+step*(i-res+2) << " " << step << '\n';
      res--;
    }
    i++;
  }
  /*for(int i=-1;i<N-1;i++)
  {
    if(!(onehigher(val+step*i, step)))
    {
      return 0;
    }
  }
  return 1;*/
  return 0;
}

int main()
{
  cin >> N >> M;
  int res = 0;
  maxval = 2*pow(M,2);
  for(int i=1;i<maxval-(i*N);i++)
  {
    for(int o=0;o<i;o++)
    {
      ariprog(o,i);
    }
  }
  /*int o=0;
  for(int i=1;i<maxval;i++)
  {
    for(int o=0;o<maxval;o++)
    {
      if(ariprog(o, i))
      {
        cout << o << " " << i << '\n';
        if(res == 0)
        {
          res = 1;
        }
      }
    }
  }
  if(res == 0)
  {
    cout << "NONE" << '\n';
  }*/
  return 0;
}
