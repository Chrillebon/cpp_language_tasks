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
    v[b]=b;
  }
  for(int i=r;i>0;i--)
  {
    //std::cout << "update: " << i <<" og "<< v[i] << " og " << &v[i] << '\n';
    if(v[i]!=i)
    {
      //std::cout << "jeg goer noget!!!" << '\n';
      std::cout << i << '\n';
      return 0;
    }
    v.erase((v.begin()+i));
    //std::cout << "Dette er hvad der er tilbage: " << n-1 << " og " << v[n-1] << " og " << i << '\n';
  }
  return 0;
}
