#include <iostream>
#include <vector>
#include <stdio.h>
#include <fstream>
#include <deque>

int m, n;
std::deque<int> useless;
int send[100000];
int res[100000];
int mborn[50000]{};
int left = 0;

int usel()
{
  left = 0;
  for(int i=0;i<m;i++)
  {
    if(mborn[i] == 0/* && res[i] == 0*/)
    {
      left++;
      useless.push_back(i);
    }
  }
  return 0;
}

int main()
{
  std::cin >> m >> n;
  for(int i=0;i<m+n;i++)
  {
    std::cin >> send[i];
    send[i]-=1;
    if(i<m)
    {
      res[i] = 0;
      send[i] += m;
    }
    else
    {
      res[i] = 1;
      mborn[send[i]]++;
    }
  }
  usel();
  while(!useless.empty())
  {
    int temp = useless.front();
    useless.pop_front();
    if(res[temp] == 1)
    {
      continue;
    }
    res[temp] = 1;
    if(res[send[temp]])
    {
      res[send[temp]] = 0;
      mborn[send[send[temp]]]--; //Trækker én fra den der bliver peget på
      if(mborn[send[send[temp]]] < 1 && res[send[send[temp]]] == 0)
      {
        useless.push_back(send[send[temp]]);
      }
    }
  }
  for(int i=0;i<m+n;i++)
  {
    std::cout << res[i];
    if(i==m-1)
    {
      std::cout << '\n';
          }
  }
  std::cout << '\n';

  return 0;
}
