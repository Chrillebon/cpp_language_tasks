#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int rect[100000][2];
vector<long long> sols;

void rec(int i, long long a, long long b)
{
  i++;
  if(i == n)
  {
    sols.push_back(min(a,b));
    return;
  }
  if(a == rect[i][1] && b == rect[i][0])
  {
    rec(i, a+rect[i][1], b);
    rec(i, a, b+rect[i][0]);
  }
  else if(a == rect[i][0] && b == rect[i][1])
  {
    rec(i, a+rect[i][0], b);
    rec(i, a, b+rect[i][1]);
    return;
  }
  else if(a == rect[i][1])//kort mod kort
  {
    b+=rect[i][0];
  }
  else if(a == rect[i][0])//kort mod lang
  {
    b+=rect[i][1];
  }
  else if(b == rect[i][0])//lang mod kort
  {
    a+=rect[i][1];
  }
  else if(b == rect[i][1])//lang mod kort
  {
    a+=rect[i][0];
  }
  else
  {
    return;

  }
  rec(i, a, b);
}

int main()
{
  std::cin >> n;
  for(int i = 0; i < n; i++)
  {
    cin>>rect[i][0]>>rect[i][1];
  }
  rec(0, rect[0][1], rect[0][0]);
  sort(sols.begin(), sols.end());
  int last = -1;
  vector<int> uniq;
/*
for(int i = 0; i < sols.size(); i++)
{
  if(i != 0 && sols[i] == sols[i - 1])
  {
    continue;
  }
  std::cout << sols[i];
}
  */
  for(int i=0;i<sols.size();i++)
  {
    if(last != sols[i])
    {
      uniq.push_back(sols[i]);
      last = sols[i];
    }
  }
  std::cout << uniq.size() << '\n';
  for(int i=0;i<uniq.size();i++)
  {
    std::cout << uniq[i] << '\n';
  }
  return 0;
}
