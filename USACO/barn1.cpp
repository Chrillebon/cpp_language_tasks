/*
ID: Christi69
PROB: barn1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("barn1.in");
ofstream fout ("barn1.out");

int findlargest(int * arr, int size)
{
  int li = 0, l = 0;
  for(int i=0;i<size;i++)
  {
    if(arr[i] > l)
    {
      l = arr[i];
      li = i;
    }
  }
  return li;
}

int sum(int * arr, int size)
{
  int sum = 0;
  for(int i=0;i<size;i++)
  {
    sum+=arr[i];
  }
  return sum;
}

int main()
{
  int M, S, C;
  fin >> M >> S >> C;
  int cows[C], holes[C-1];
  for(int i=0;i<C;i++)
  {
    fin >> cows[i];
  }
  sort(cows, cows + C);
  for(int i=0;i<C-1;i++)
  {
    holes[i] = cows[i+1]-cows[i]-1;
  }
  for(int i=0;i<M-1;i++)
  {
    holes[findlargest(holes, C-1)] = 0;
  }
  fout << sum(holes, C-1)+C << '\n';
}
