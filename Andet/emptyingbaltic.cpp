#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int h, w, minusleft=0;
long long water = 0;
vector<vector<vector<int>>> baltic;
priority_queue<vector<int>> around;

int addaround(int starty, int startx)
{
  std::cout << "kører nu: " <<around.top()[0]<<": ("<<around.top()[2]<<", "<<around.top()[1]<<")"<< '\n';
  around.pop();
  for(int i=0; i<3; i++)
  {
    std::cout << "i: " <<i<< '\n';
    if(!(starty-1+i < 0 || starty-1+i >= w))
    {
      for (int o=0; o<3; o++)
      {
        if(!(startx-1+o < 0 || startx-1+o >= h))
        {
          if(baltic[starty-1+i][startx-1+o][1] == 0 && baltic[starty-1+i][startx-1+o][0] < 0)
          {
            if(baltic[starty-1+i][startx-1+o][0] < baltic[starty][startx][0])
            {
              baltic[starty-1+i][startx-1+o][0] = baltic[starty][startx][0];
            }
            std::cout << "lægger til: " <<baltic[starty-1+i][startx-1+o][0]<< '\n';
            water -= baltic[starty-1+i][startx-1+o][0];
            minusleft--;
            baltic[starty-1+i][startx-1+o][1] = 1;
            around.push({baltic[starty-1+i][startx-1+o][0] * (-1), starty-1+i, startx-1+o});
          }
        }
      }
    }
  }
  return 0;
}

int main()
{
  int val, i, j;
  std::cin >> w >> h;
  baltic.resize(w);
  for(int i=0; i<w; i++)
  {
    for(int o=0; o<h; o++)
    {
      std::cin >> val;
      if(val<0)
      {
        minusleft++;
      }
      baltic[i].push_back({val,0});
    }
  }
  std::cin >> i >> j;
  around.push({baltic[i-1][j-1][0] * (-1),i-1,j-1});
  baltic[i-1][j-1][1] = 1;
  water -= baltic[i-1][j-1][0];
  while(around.size())
  {
    addaround(around.top()[1], around.top()[2]);
    for(int i=0; i<w; i++)
    {
      for(int o=0; o<h; o++)
      {
        std::cout << baltic[i][o][0] <<" ";
      }
      std::cout << '\n';
    }
    for(int i=0; i<w; i++)
    {
      for(int o=0; o<h; o++)
      {
        std::cout << baltic[i][o][1] <<" ";
      }
      std::cout << '\n';
    }
    std::cout << "sum: " <<water<< '\n';
  }
  std::cout << water << '\n';
  return 0;
}
