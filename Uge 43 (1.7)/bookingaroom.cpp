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
  std::vector<int> v;
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
  std::sort(v.begin(),v.begin()+n-1);
  for(int i=r;i>0;i--)
  {
    //std::cout << "update: " << n-1 <<" og "<< v[n-1] << " og " << &v[n-1] << '\n';
    if(v[n-1]!=i)
    {
      //std::cout << "jeg goer noget!!!" << '\n';
      std::cout << i << '\n';
      return 0;
    }
    n--;
    v.erase((v.begin()+n));
    //std::cout << "Dette er hvad der er tilbage: " << n-1 << " og " << v[n-1] << " og " << i << '\n';
  }
  return 0;
}
