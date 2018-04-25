#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

std::vector<int> friends[1000000];
std::queue<int> peeps;
bool visited[1000000]{};
int parent[1000000];
int depth[1000000];
int infected[1000000]{};
int maxres = 0, maxday = -1;

void BFS(int i)
{
  peeps.pop();
  int locres = 0;
  for(int o=0;o<friends[i].size();o++)
  {
    if(visited[friends[i][o]] == false)
    {
      parent[friends[i][o]] = i;
      visited[friends[i][o]] = true;
      depth[friends[i][o]] = depth[i]+1;
      peeps.push(friends[i][o]);
      locres++;
    }
  }
  infected[depth[i]+1] += locres;
}


int main()
{
  int n, m, p, o, j;
  std::cin >> n >> m >> p;
  peeps.push(p);
  visited[p] = true;
  depth[p] = 0;
  infected[p] = 1;
  for(int i=0;i<m;i++)
  {
    std::cin >> o >> j;
    friends[o].push_back(j);
    friends[j].push_back(o);
  }
  while(!peeps.empty())
  {
    BFS(peeps.front());
  }
  int i = 1;
  while(infected[i])
  {
    if(infected[i] > maxres)
    {
      maxres = infected[i];
      maxday = i;
    }
    i++;
  }
  std::cout << maxres <<" "<<maxday<< '\n';
  return 0;
}
