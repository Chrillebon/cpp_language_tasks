#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

int n,m,tmp;
int ln[10000];
map<int, int> num1; //id, number
map<int, int> num2;

int main()
{
  std::cin >> n;
  vector<int> first(n,0);
  for(int i=0;i<n;i++)
  {
    std::cin >> tmp;
    if(num1.count(tmp)) //Hvis den eksisterer:
    {
      num1.at(tmp)++;
    }
    else
    {
      num1.insert(pair<int, int>(tmp,1));
    }
  }
  std::cin >> m;
  for(int i=0;i<m;i++)
  {
    std::cin >> tmp;
    if(num2.count(tmp)) //Hvis den eksisterer:
    {
      num2.at(tmp)++;
    }
    else
    {
      num2.insert(pair<int, int>(tmp,1));
    }
  }

  //------------------------------
  vector<int> res;
  for(map<int,int>::iterator it=num2.begin();it!=num2.end();it++)
  {
    if(num1.count(it->first)) //If if exists in the num2 map
    {
      if(num1.at(it->first) < it->second) //If it has less elements
      {
        res.push_back(it->first); //add it to the list
      }
    }
    else //it does not exist here...
    {
      res.push_back(it->first); //add it.
    }
  }
  //That was all the elements

  std::sort(res.begin(),res.end());
  for(int i=0;i<res.size();i++)
  {
    std::cout << res[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}

/*
10
203 204 205 206 207 208 203 204 205 206
13
203 204 204 205 206 207 205 208 203 206 205 206 204
*/
