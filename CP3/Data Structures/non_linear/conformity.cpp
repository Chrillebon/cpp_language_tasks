#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;

map<vector<int>, int> m;
vector<int> s(5, 0);

void insert()
{
  pair<map<vector<int>, int>::iterator, bool> tmp; //ved ikke hvad der sker her... Har ikke haft om iterators endnu :(
  tmp = m.insert( pair<vector<int>, int>(s, 1) );
  if(tmp.second == 0) //den findes allerede:
  {
    m[s]++;
  }
  return;
}

void input()
{
  for(int i=0;i<5;i++)
  {
    std::cin >> s[i];
  }
  sort(s.begin(), s.begin()+5);
  insert();
  return;
}

void biggest()
{
  int big = 0;
  int num = 0;
  for(map<vector<int>, int>::iterator it=m.begin(); it!=m.end(); it++)
  {
    big = max(big, it->second);
  }
  for(map<vector<int>, int>::iterator it=m.begin(); it!=m.end(); it++)
  {
    if(it->second == big)
    {
      num += it->second;
    }
  }
  std::cout << num << '\n';
  return;
}

int main()
{
  int n;
  std::cin >> n;
  while(n != 0)
  {
    for(int o=0;o<n;o++)
    {
      input();
    }
    biggest();
    m.clear();

    std::cin >> n;
  }
  return 0;
}
