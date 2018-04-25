#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

std::vector<int> edge[1000000];
int n, m, k;
int color[1000000];
int cyco=0,cyid=0;

void DFS(int i, int last)
{
  for(int o=0;o<edge[i].size();o++)
  {
    int next = edge[i][o];
    if(next == cyid && color[i] == cyco && next != last)
    {
      std::cout << "JA" <<'\n';
      exit(EXIT_SUCCESS);
    }
    if(color[next] == color[i] && next != last)
    {
      DFS(next, i);
    }
  }
}

int main()
{
  std::cin >> n >> m >> k;
  for(int i=1;i<=n;i++)
  {
    std::cin >> color[i];
  }
  int a,b;
  for(int i=1;i<=m;i++)
  {
    if(i<=m)
    {
      std::cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
  }
  int temp = 1;
  for(int i=1;i<n;i++)
  {
    cyid = i;
    cyco = color[i];
    DFS(i, 0);
  }
  std::cout << "NEJ" << '\n';
  return 0;
}
