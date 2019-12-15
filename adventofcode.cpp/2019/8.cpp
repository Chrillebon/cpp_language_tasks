#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int w = 25, h = 6, tmp, l = 0; //width, height, layer
pair<int,int> info;
vector<vector<int>> res(99, vector<int>(10)); //For every layer, save digit amount

int main()
{
  info = {w,h};
  while(scanf("%1d", &tmp))
  {
    res[l][tmp]++;
    info.first--;
    if(info.first == 0)
    {
      info.first = w;
      info.second--;
      if(info.second == 0)
      {
        l++;
        info.second = h;
      }
    }
  }
  vector<int> m {99, 0, 0};
  for(int i=0;i<99;i++)
  {
    if(res[i][0] != 0)
    {
      if(res[i][0] < m[0])
      {
        m[0] = res[i][0];
        m[1] = res[i][1];
        m[2] = res[i][2];
      }
    }
  }
  std::cout << "res: " <<m[1]*m[2]<< '\n';
  return 0;
}
