#include <iostream>
#include <queue>
#include <vector>

int main()
{
  int r,n,b;
  std::cin >> r >> n;
  if(r == n)
  {
    std::cout << "too late" << '\n';
    return 0;
  }
  std::priority_queue<int, std::vector<int>, std::greater<int> > q;
  for(int i=0;i<n;i++)
  {
    std::cin >> b;
    q.push(b);
  }
  for(int i=1;i<=r;i++)
  {
    if(q.top()!=i)
    {
      std::cout << i << '\n';
      return 0;
    }
    q.pop();
  }
  return 0;
}
