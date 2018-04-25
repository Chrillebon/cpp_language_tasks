#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

struct comp
{
  bool operator() (pair<double, int> a, pair<double, int> b)
  {
    return a.first > b.first;
  }
};

priority_queue<pair<double, int>, vector<pair<double, int>>, comp> allaround;
int visited[500]{};
pair<int, int> frecles[500];
double result = 0;
int n;

double distance(long long a, long long b, long long x, long long y)
{
  double res;
  res = sqrt((a-x)*(a-x)+(b-y)*(b-y));
  return res;
}

void BFS(int i)
{
  double dist = allaround.top().first;
  allaround.pop();
  if(visited[i])
  {
    return;
  }
  result += dist;
  visited[i] = 1;
  for(int o=1;o<=n;o++)
  {
    if(!visited[o])
    {
      allaround.push(make_pair(distance(frecles[i].first, frecles[i].second, frecles[o].first, frecles[o].second), o)); //Indsætter i q
    }
  }
}

int main()
{
  //cout.precision(7);
  std::cin >> n;
  for(int i=1;i<=n;i++)
  {
    std::cin >> frecles[i].first >> frecles[i].second;
  }
  allaround.push(make_pair(0.0,1)); //nul afstand på 1. indeks
  while(!allaround.empty())
  {
    BFS(allaround.top().second);
  }
  std::cout << result << '\n';
  return 0;
}
/*
6
2 2
2 8
5 6
7 7
9 3
10 7
*/
