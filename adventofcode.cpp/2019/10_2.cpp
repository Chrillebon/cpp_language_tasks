#include <iostream>
#include <vector>
#include <utility>
#include <math.h>
#include <algorithm>
using namespace std;

int size = 23;

vector<vector<char>> field(size,vector<char>(size));
vector< pair<float,pair<int,int>> > spotted;

bool mysort (pair<float,pair<int,int>> a, pair<float,pair<int,int>> b)
{
  if(a.first == b.first) //Hvis deres vinkler er lige store
  {
    return sqrt(pow(1.0*a.second.first,2)+pow(1.0*a.second.second,2)) < sqrt(pow(1.0*b.second.first,2)+pow(1.0*b.second.second,2));
  }
  return a.first < b.first; //den mindre vinkel
}

int gcd(int a, int b)
{
  int r = b;
  if(b > a)
  {
    r = a;
    a = b;
    b = r;
  }
  if(b == 0)
  {
    return a;
  }
  while(a % b != 0)
  {
    r = a % b;
    return gcd(b,r);
  }
  return r;
}

void in_sight(int x, int y)
{
  for(int i=0;i<size;i++)
  {
    for(int o=0;o<size;o++)
    {
      if(!(i == y && o == x) && field[o][i] == '#')
      {
        int xdif = o - x;
        int ydif = i - y;
        float an = acos((-1.0*ydif)/( sqrt(pow((1.0*xdif),2)+pow(1.0*ydif,2)) )); //Så kunne mat1 noget alligevel
        if(xdif < 0)
        {
          an = 2*M_PI - an;
        }
        spotted.push_back({an,{xdif,ydif}});
      }
    }
  }
  return;
}

int main()
{
  int astnr = 1;

  for(int i=0;i<size;i++)
  {
    for(int o=0;o<size;o++)
    {
      std::cin >> field[o][i];
    }
  }
  in_sight(19,11);
  while(1)
  {

    if(astnr == 200)
    {
      std::cout << "200'th is at: " <<19+spotted[0].second.first<<", "<<11+spotted[0].second.second<< '\n';
      return 0;
    }
    sort(spotted.begin(), spotted.end(), mysort);
    std::cout << "number: " <<astnr<<" at "<<19+spotted[0].second.first<<", "<<11+spotted[0].second.second<<" - "<<spotted[0].first<<"deg"<< '\n';
    while(spotted[0].first == spotted[1].first)
    {
      spotted[1].first+=2*M_PI;
      sort(spotted.begin(), spotted.end(), mysort);
    }
    spotted.erase(spotted.begin()); //Evaporerer første element!
    astnr++;
  }
  return 0;
}
