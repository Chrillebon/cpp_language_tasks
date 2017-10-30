#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int main()
{
  int r,n,b;
  std::cin >> r >> n;
  if(r == n)
  {
    std::cout << "too late" << '\n';
    return 0;
  }
  std::vector<int> v(r+1);
  /*std::priority_queue<int, std::vector<int>, std::greater<int> > q;
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
  }*/
  for(int i=0;i<n;i++)
  {
    std::cin >> b;
    v.push_back(b);
  }
  std::sort(v.begin(),v.begin()+n);
  for(int i=r-1;i>=0;i--)
  {
    if(v[i]-1!=i)
    {
      std::cout << i+1 << '\n';
      return 0;
    }
    v.erase(v.begin()+i);
  }
  return 0;
}
