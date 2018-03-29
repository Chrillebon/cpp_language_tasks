/*
ID: Christi69
PROB: skidesign
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <math.h>
using namespace std;

ifstream fin ("skidesign.in");
ofstream fout ("skidesign.out");

int N;

int power(int v, int b)
{
  double r;
  r = ceil(pow(v,b));
  return (int)(r);
}

int alter(int arr[], int s, int e)
{
  int res = 0;
  for(int i=0;i<N;i++)
  {
    if(arr[i] > e)
    {
      res+=power(arr[i]-e,2);
    }
    else if(arr[i] < s)
    {
      res+=power(s-arr[i],2);
    }
  }
  return res;
}

int main()
{
  int res = 1000000000;
  fin >> N;
  int hills[N];
  for(int i=0;i<N;i++)
  {
    fin >> hills[i];
  }
  for(int i=0;i<84;i++)
  {
    res = min(res, alter(hills, i, i+17));
  }
  fout << res << '\n';
  return 0;
}
