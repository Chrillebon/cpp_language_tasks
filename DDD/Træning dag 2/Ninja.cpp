#include <iostream>
#include <queue>

std::queue<int> where;
bool visited[250000];
int dist[250000];
bool spike[250000];
int n, h;


void BFS(int i)
{
  where.pop();
  if(i%h == 0 && !spike[i])
  {
    std::cout << dist[i] << '\n';
    exit(EXIT_SUCCESS);
  }
  //Try up
  if(i%h != 0 && !visited[i+1] && !spike[i+1])
  {
    visited[i+1] = true;
    dist[i+1] = dist[i]+1;
    where.push(i+1);
  }
  //Try down
  if(i%h != 1 && !visited[i-1] && !spike[i-1])
  {
    visited[i-1] = true;
    dist[i-1] = dist[i]+1;
    where.push(i-1);
  }
  //Try left
  if((!(i<=h)&& i%h != 1) && !visited[i-h-1] && !spike[i-h-1])
  {
    visited[i-h-1] = true;
    dist[i-h-1] = dist[i]+1;
    where.push(i-h-1);
  }
  //Try right
  if((!(i>h*(n-1)) && i%h != 1) && !visited[i+h-1] && !spike[i+h-1])
  {
    visited[i+h-1] = true;
    dist[i+h-1] = dist[i]+1;
    where.push(i+h-1);
  }
}

int main()
{
  std::cin >> n >> h;
  int t, a;
  for(int i=0;i<n;i++)
  {
    std::cin >> t;
    for(int o=0;o<t;o++)
    {
      std::cin >> a;
      spike[i*h+a] = true;
    }
  }
  dist[1] = 0;
  where.push(1);
  visited[1] = 1;
  while(!where.empty())
  {
    BFS(where.front());
  }
  std::cout << "umuligt" << '\n';
  return 0;
}
