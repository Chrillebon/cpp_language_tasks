#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g(3, vector<int>(3, 0));

void input()
{
  for(int j=0;j<3;j++)
  {
    scanf("%1d %1d %1d", &g[j][0], &g[j][1], &g[j][2]);
  }
  return;
}

/*void test()
{
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
      std::cout << g[j][i];
    }
    std::cout << '\n';
  }
  return;
}*/

bool end()
{
  for(int j=0;j<3;j++)
  {
    for(int i=0;i<3;i++)
    {
      if(g[j][i] != 0)
      {
        return 0;
      }
    }
  }
  return 1; //end it...
}

void transform()
{
  vector<vector<int>> tmp(3, vector<int>(3, 0));
  tmp[0][0] = (g[0][1] + g[1][0]) % 2;
  tmp[0][1] = (g[0][0] + g[0][2] + g[1][1]) % 2;
  tmp[0][2] = (g[0][1] + g[1][2]) % 2;

  tmp[1][0] = (g[0][0] + g[1][1] + g[2][0]) % 2;
  tmp[1][1] = (g[0][1] + g[1][0] + g[1][2] + g[2][1]) % 2;
  tmp[1][2] = (g[0][2] + g[1][1] + g[2][2]) % 2;

  tmp[2][0] = (g[2][1] + g[1][0]) % 2;
  tmp[2][1] = (g[2][0] + g[1][1] + g[2][2]) % 2;
  tmp[2][2] = (g[1][2] + g[2][1]) % 2;

  g = tmp;

  return;
}

int main()
{
  std::cin >> n;
  for(int tc=0;tc<n;tc++)
  {
    int index = -1;
    input();
    while(1)
    {
      if(end())
      {
        std::cout << index << '\n';
        break;
      }
      else
      {
        index++;
      }
      transform();
    }
  }
  return 0;
}
