/*
ID: Christi69
PROB: milk
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <queue>
#include <algorithm>
using namespace std;

ifstream fin ("milk.in");
ofstream fout ("milk.out");

struct comp
{
  bool operator()(pair<int, int> a, pair<int, int> b)
  {
    return a.first > b.first;
  }
};

int main()
{
  int N, M, result = 0, a, b;
  fin >> N >> M;
  priority_queue< pair<int, int>, vector< pair<int,int> >, comp> farm;
  for(int i=0;i<M;i++)
  {
    fin >> a >> b;
    farm.push(make_pair(a, b));
  }
  int i=0;
  while(N)
  {
    if(farm.top().second > N)
    {
      result += farm.top().first * N;
      N = 0;
    }
    else
    {
      result += farm.top().second * farm.top().first;
      N -= farm.top().second;
    }
    farm.pop();
  }
  fout << result << '\n';
  return 0;
}
