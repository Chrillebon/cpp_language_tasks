#include <iostream>
#include <algorithm>
using namespace std;

int n;

long long get_max(long long tree[], int i)
{
  long long m = 0;
  while(i > 0)
  {
    m = max(tree[i], m);
    i -= (i & -i);
  }
  return m;
}

long long update(long long tree[], int i, long long val)
{
  while(i <= 200000)
  {
    tree[i] = max(tree[i], val);
    i += (i & -i);
  }
}

int main()
{
  std::cin >> n;
  long long tree[200000]{};
  long long r,t;
  for(int i=0; i<n; i++)
  {
    std::cin >> r >> t;
    update(tree,r,get_max(tree,r)+t);
  }
  std::cout<<get_max(tree,200000);

  return 0;
}
