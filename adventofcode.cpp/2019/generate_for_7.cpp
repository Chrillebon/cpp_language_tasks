#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
using namespace std;

vector<vector<int>> total;

void create(int a, int b, int c, int d, int e)
{
  vector<int> rem{5,6,7,8,9}; //pladser:
  vector<int> n;
  n.push_back(rem[a]);
  rem.erase(rem.begin()+a);
  n.push_back(rem[b]);
  rem.erase(rem.begin()+b);
  n.push_back(rem[c]);
  rem.erase(rem.begin()+c);
  n.push_back(rem[d]);
  rem.erase(rem.begin()+d);
  n.push_back(rem[e]);
  rem.erase(rem.begin()+e);

  total.push_back(n);
  return;
}

int main()
{
  for(int a=0;a<5;a++)
  {
    for(int b=0;b<4;b++)
    {
      for(int c=0;c<3;c++)
      {
        for(int d=0;d<2;d++)
        {
          create(a,b,c,d,0);
        }
      }
    }
  }
  for(int i=0;i<120;i++)
  {
    std::cout << "{";
    for(int o=0;o<5;o++)
    {
      std::cout << total[i][o];
      if(o != 4)
      {
        std::cout << ",";
      }
    }
    std::cout << "}, ";
  }
  return 0;
}
