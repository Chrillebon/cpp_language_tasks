#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> edge[1000000];
int n,m;
int notvisited[1000000];
int largest = 0, locsize = 0;

void DFS(int i)
{
  notvisited[i] = 0;
  for(int o=0;o<edge[i].size();o++)
  {
    int next = edge[i][o];
    if(notvisited[next])
    {
      locsize++;
      DFS(next);
    }
  }
  largest = std::max(largest, locsize);
}

int stillunvisited()
{
  for(int i=1;i<=n;i++)
  {
    if(notvisited[i])
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  std::cin >> n >> m;
  int a, b;
  for(int i=1;i<=n;i++)
  {
    if(i<=m)
    {
      std::cin >> a >> b;
      edge[a].push_back(b);
      edge[b].push_back(a);
    }
    notvisited[i] = 1;
  }

  int temp = 1, res = 0;
  while(temp != -1)
  {
    res++;
    locsize = 1;
    DFS(stillunvisited());
    temp = stillunvisited();
  }
  std::cout << res <<" "<<largest<< '\n';
  return 0;
}
