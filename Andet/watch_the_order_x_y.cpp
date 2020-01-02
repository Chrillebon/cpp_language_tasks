#include <iostream>
#include <vector>
#include <utility>
using namespace std;

vector<pair<char,int>> keys; //id and dist
vector<vector<char>> board(24, vector<char>(5));
vector<vector<int>> visited(24, vector<int>(5));

int main()
{
  for(int i=0;i<24;i++)
  {
    for(int o=0;o<5;o++)
    {
      visited[o][i] = 0;
    }
  }
  keys.push_back({'a',0});
  std::cout << "1" << '\n';
  keys.push_back({'a',0});
  std::cout << "2" << '\n';
  keys.push_back({'a',0});
  std::cout << "3" << '\n';
  return 0;
}
