#include <iostream>
#include <queue>
using namespace std;

struct comp
{
  bool operator()(long long a, long long b)
  {
    return a>b;
  }
};
long long n, k, tmp, steps=0;
priority_queue<long long, vector<long long>, comp> sweet;


int main()
{
  std::cin >> n >> k;
  for(int i=0;i<n;i++)
  {
    std::cin >> tmp;
    sweet.push(tmp);
  }
  while(sweet.size() >= 2)
  {
    if(sweet.top() >= k)
    {
      std::cout << steps << '\n';
      return 0;
    }
    tmp = sweet.top();
    sweet.pop();
    tmp += 2*sweet.top();
    sweet.pop();
    sweet.push(tmp);
    steps++;
  }
  if(sweet.top() >= k) //last chance
  {
    std::cout << steps << '\n';
    return 0;
  }
  //else
  std::cout << "-1" << '\n';
  return 0;
}


/*
6 7
1 2 3 9 10 12

*/
