#include <iostream>
#include <queue>
#include <string>
using namespace std;

int period[3000];

struct comp
{
    bool operator()(pair<int, int> lhs, pair<int,int> rhs)
    {
      if(lhs.second == rhs.second) //samme tid:
      {
        return lhs.first > rhs.first;
      }
      else //først til mølle
      {
        return lhs.second > rhs.second;
      }
    }
};

priority_queue<vector<pair<int,int>>, vector<pair<int,int>>, comp> q;


int main()
{
  while(1)
  {
    string tmp;
    std::cin >> tmp;
    if(tmp == "Register")
    {
      int id, p;
      std::cin >> id >> p;
      q.push(make_pair(id,p));
      period[id] = p;
    }
    else
    {
      break;
    }
  }
  int k;
  std::cin >> k;
  for(int i=0;i<k;i++)
  {
    std::cout << q.top().first << '\n';
    pair<int,int> tmpp;
    tmpp = make_pair(q.top().first,q.top().second);
    q.pop();
    q.push(make_pair(tmpp.first, tmpp.second+period[tmpp.first]));
  }
  return 0;
}
