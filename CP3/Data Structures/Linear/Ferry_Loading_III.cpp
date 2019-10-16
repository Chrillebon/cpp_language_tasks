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
    for(int car=0;car<m;car++)
    {
      if(time < left.front().first or time < right.front().first)
      {
        time = std::min(left.front().first, right.front().first);
      }
      //venstre side
      if(left.front().first < right.front().first or (right.empty() and !left.empty()) or (ferry == 0 && left.front().first == right.front().first))
      {
        load=0;
        time += t*ferry; //tager t tid, hvis færgen er højre
        while(left.front().first <= time && load < n) //hvis de er kommet og der er plads
        {
            load++;
            res[left.front().second] = time + t;
            left.pop();
        }
        time += t;
      }
      if(right.front().first < left.front().first or (left.empty() and !right.empty()) or (ferry == 1 && left.front().first == right.front().first))
      {
        load=0;
        time += t; time -= t*ferry; //tager t tid, hvis færgen er venstre
        while(right.front().first <= time && load < n)
        {
          load++;
          res[right.front().second] = time + t;
          right.pop();
        }
        time += t;
      }
    }
    //skriv resultaterne:
    for(int car=0;car<m;car++)
    {
      std::cout << res[car] << '\n';
    }
    std::cout << '\n';
  }
  return 0;
}
