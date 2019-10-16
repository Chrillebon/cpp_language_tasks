#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
int c,n,t,m,arr;
int res[10002];
std::string side;
std::queue<std::pair<int,int>> left;
std::queue<std::pair<int,int>> right;

int main()
{
  std::cin >> c;
  for(int tc=0; tc<c;tc++)
  {
    if(tc!=0)
    {
      std::cout << '\n';
    }
    std::cin >> n >> t >> m;
    for(int car=0;car<m;car++)
    {
      std::cin >> arr >> side;
      if(side=="left")
      {
        left.push(std::make_pair(arr, car));
      }
      if(side=="right")
      {
        right.push(std::make_pair(arr, car));
      }
      //std::cout << "test: "<< left.front().second << '\n';
    }
    //Nu skal vi arbejde med de to køer:
    int time=0;
    bool ferry=0; //0=left, 1=right;
    int load=0;
    int car = 0;
    while(car<m)
    {
      if((time < left.front().first or left.empty()) and (time < right.front().first or right.empty()))
      {
        if(left.empty())
        {
          time = right.front().first;
        }
        else if(right.empty())
        {
          time = left.front().first;
        }
        else
        {
          time = std::min(left.front().first, right.front().first);
        }
      }
      if(!ferry)      //venstre side
      {
        load = 0;
        while(left.front().first <= time && load < n && !left.empty()) //hvis de er kommet og der er plads
        {
          load++;
          res[left.front().second] = time + t;
          left.pop();
          car++;
        }
        time += t;
        ferry ^= 1;
      }
      else      //højre side
      {
        load = 0;
        while(right.front().first <= time && load < n && !right.empty())
        {
          load++;
          res[right.front().second] = time + t;
          right.pop();
          car++;
        }
        time += t;
        ferry ^= 1;
      }
    }
    //skriv resultaterne:
    for(int car=0;car<m;car++)
    {
      std::cout << res[car] << '\n';
    }
  }
  return 0;
}
