#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <map>
#include <math.h>
#include <utility>
using namespace std;

int width = 17, height = 9;
map<char,pair<int,int>> doors;
vector<vector<char>> board(width, vector<char>(height));
vector<vector<int>> visited(width, vector<int>(height));
deque<pair<int,pair<int,int>>> nxt; //steps,  x,y
pair<int,int> start;
vector<pair<char,int>> keys; //id and dist

void new_place() //Finder afstanden til alle nøgler
{
  int steps = nxt[0].first;
  int x = nxt[0].second.first;
  int y = nxt[0].second.second;
  nxt.erase(nxt.begin());
  if(visited[x][y])
  {
    return;
  }
  visited[x][y] = steps;
  int item = board[x][y];
  char p = item;

  //std::cout << "test " <<x<<", "<<y<<" efter "<<steps<<" med "<<p<< '\n';
  if((item >= 65 && item <= 90 && doors.count(p)) || item == 35) //Væg eller dør, der stadig er der
  {
    return;
  }
  if(item >= 97 && item <= 122) //En nøgle
  {
    keys.push_back({p,steps});
  }
  nxt.push_back({steps+1, {x-1,y}});
  nxt.push_back({steps+1, {x+1,y}});
  nxt.push_back({steps+1, {x,y-1}});
  nxt.push_back({steps+1, {x,y+1}});
  return;
}

void bfs(int x, int y)
{
  keys.clear();
  for(int i=0;i<height;i++)
  {
    for(int o=0;o<width;o++)
    {
      visited[o][i] = 0;
    }
  }
  nxt.push_back({0,{x,y}});
  while(!nxt.empty())
  {
    new_place();
  }
  return;
}

int move(vector<pair<char,int>> k, int s)
{
  if(k.size() == 0)
  {
    return s;
  }
  int res = 9999;
  for(int i=0;i<k.size();i++)
  {
    pair<char,int> tmp = k[0];
    k.erase(k.begin());
    res = min(res, move(k,s+tmp.second))
    k.push_back(tmp);
  }
  return res;
}

int main()
{
  for(int i=0;i<height;i++)
  {
    for(int o=0;o<width;o++)
    {
      std::cin >> board[o][i];
      if(board[o][i] >= 65 && board[o][i] <= 90)
      {
        doors[board[o][i]] = {o,i};
      }
      if(board[o][i] == 64)
      {
        start = {o,i};
      }
    }
  }
  bfs(start.first,start.second);
  std::cout << "Der er " <<keys.size()<<" nogler man kan naa"<< '\n';
  return 0;
}
