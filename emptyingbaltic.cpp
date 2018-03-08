#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int h, w;
long long water = 0;

int addaround(int startx, int starty, int** baltic[2], priority_queue<vector<int>> around)
{
  for(int i=0; i<3; i++)
  {
    if(!(startx-h+i < 0 || startx-h+i > h))
    {
      for (int o=0; o<3; o++)
      {
        if(!(starty-h+o < 0 || starty-h+o > w))
        {
          if(baltic[startx-1+i][starty-1+o][1] == 0)
          {
            if(baltic[startx-1+i][starty-1+o][0] > baltic[startx][starty][0])
            {
              baltic[startx-1+i][starty-1+o][0] = baltic[startx][starty][0];
            }
            water += baltic[startx-1+i][starty-1+o][0];
            around.push({baltic[startx-1+i][starty-1+o][0] * (-1), startx-1+i, starty-1+o});
            baltic[startx-1+i][starty-1+o][1] = 1;
          }
        }
      }
    }
  }
}

int main()
{
  int val, i, j;
  std::cin >> h >> w;
  int baltic[h][w][2]{};
  for(int i=0; i<h; i++)
  {
    for(int o=0; o<w; o++)
    {
      std::cin >> val;
      baltic[i][o][0] = val;
      baltic[i][o][1] = 0;
    }
  }
  std::cin >> i >> j;
  priority_queue<vector<int>> around;
  addaround(i-1, j-1, baltic, around);
  while(around.top()[0] > 0)
  {
    addaround(around.top()[1], around.top()[1], &&baltic, around);
  }
  std::cout << water << '\n';
  return 0;
}
