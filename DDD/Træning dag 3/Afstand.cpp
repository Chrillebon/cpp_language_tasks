#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct comp{
  bool operator() (pair<int, int> a, pair<int, int> b)
  {
    return a.first > b.first;
  }
};

priority_queue< pair<int, int> , vector<pair<int, int>>, comp> q;
vector< pair<int, int> > roads[100000];
int dist[100000];
int n, m, u, v;

void memset(int arr[])
{
  for(int i=0;i<100000;i++)
  {
    arr[i] = -1;
  }
}

void Dijkstra(int i)
{
  if(dist[i] >= 0)
  {
    q.pop();
    return;
  }
  dist[i] = q.top().first;
  q.pop();
  for(int o=0;o<roads[i].size();o++)
  {
    if(dist[roads[i][o].second] < 0)
    {
      q.push(make_pair(dist[i]+roads[i][o].first, roads[i][o].second));
    }
  }
}

int main()
{
  memset(dist);
  int i, j, d;
  std::cin >> n >> m >> u >> v;
  for(int a=1;a<=m;a++)
  {
    std::cin >> i >> j >> d;
    roads[i].push_back(make_pair(d, j)); // (Vægt, ID)
  }
  q.push(make_pair(0,u));
  while(!q.empty())
  {
    Dijkstra(q.top().second);
  }
  std::cout << dist[v] << '\n';
  return 0;
}

/*
8 16 9 2
9 1 5
 9 3 8
 9 6 4
 1 3 4
 1 4 12
 1 2 15
 2 7 9
 3 4 7
 3 5 6
 4 2 3
 4 7 11
 5 4 1
 5 7 13
 6 3 5
 6 5 4
 6 7 20
*/
