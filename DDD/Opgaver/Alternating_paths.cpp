#include <iostream>
#include <queue>
#include <cstdlib>

dequeue<int> id;
bool visited[1000000]{};
bool board[1000000]{};

void BFS(int i, int d)
{
  if(visited[i])
  {
    return;
  }
  visited[i] = true; //Nu har den været der
  if(i == n*n-1)
  {
    std::cout << d << '\n'; //Udskriv resultatet
    exit(EXIT_SUCCESS);
  }
  //Gå i alle retninger:
  if(!(i < n) && !visited[i-n]) //op
  {
    BFS(i-n, d+1);
  }
  if(!(i%n == n-1) && !visited[i+1]) //højre
  {
    BFS(i+1, d+1);
  }
  if(!(i>= n*(n-1)) && !visited[i+n]) //ned
  {
    BFS(i+n, d+1);
  }
  if(!(i%n == 0) && !visited[i-1]) //venstre
  {
    BFS(i-1, d+1);
  }
}

int main()
{
  
}
