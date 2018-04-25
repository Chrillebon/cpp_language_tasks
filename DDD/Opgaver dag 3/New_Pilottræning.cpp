#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct comp
{
  bool operator() (pair<long long, long long> a, pair<long long, long long> b)
  {
    return a.first > b.first;
  }
};

priority_queue<pair<long long,long long>, vector<pair<long long, long long>>, comp> minimum;
priority_queue<pair<long long, long long>> maximum;
long long input[3000000], t, result = 0, b = -1;
int n;

void gothrough(int s)
{
  while(s < n)
  {
    minimum.push(make_pair(input[s],s));
    maximum.push(make_pair(input[s],s));
    while(!(maximum.empty() || minimum.empty()) && maximum.top().first-minimum.top().first > t)
    {
      if(maximum.top().second > minimum.top().second)
      {
        b = max(b, minimum.top().second);
        minimum.pop();
      }
      else
      {
        b = max(b, maximum.top().second);
        maximum.pop();
      }
    }
    result = std::max(result, s-b);
    s++;
  }
  return;
}

int main()
{
  std::cin >> t >> n;
  visited = n;
  for(int i=0;i<n;i++)
  {
    std::cin >> input[i];
  }
  gothrough(0);
  std::cout << result << '\n';
  return 0;
}
/*
3 9
5 1 3 5 8 6 6 9 10

3 16
7 4 13 1 2 5 14 11 9 8 12 13 0 3 5 2
*/
