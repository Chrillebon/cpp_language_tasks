#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include <math.h>
using namespace std;

map<string, pair<int, vector<pair<string,int>>> > react; //List of reaction materials to make, name, {amount, how_to}
string tmp;
map<string, int> reserve;
vector<int> ending{0,0,0};

int made_of(string name)
{
  if(react[name].second[0].first == "ORE") //End of line
  {
    //std::cout << react[name].second[0].second <<" from "<<name<< '\n';
    return react[name].second[0].second;
  }
  else
  {
    int total = 0;
    for(int i=0;i<react[name].second.size();i++)
    {
      //std::cout << "finder ud af: " <<react[name].second[i].first<< " med "<<react[name].second[i].second<<" / "<<react[react[name].second[i].first].first<<" = "<<ceil((1.0*react[name].second[i].second) / (1.0*react[react[name].second[i].first].first))<< " reaktioner"<<'\n';
      while(react[name].second[i].second > reserve[react[name].second[i].first]) //Der skal laves mere
      {
        //std::cout << "laver reaktion for: " <<react[name].second[i].first<< '\n';
        total += made_of(react[name].second[i].first); //Laver reaktionerne
        reserve[react[name].second[i].first] += react[react[name].second[i].first].first; //Der er lige blevet lavet så mange.
      }
      reserve[react[name].second[i].first] -= react[name].second[i].second; //Tilføjer den overskydende til reserver.
    }
    return total;
  }
}

void rmvc()
{
  if(tmp.at(tmp.size()-1) == ',')
  {
    tmp.erase(tmp.end()-1);
  }
  return;
}

int makeint()
{
  int res = 0;
  for(int i=0;i<tmp.size();i++)
  {
    res *= 10;
    res += tmp[i]-48;
  }
  return res;
}

void input()
{
  while(1)
  {
    vector<pair<string,int>> ingredients;
    int a;
    string b;
    std::cin >> tmp;
    rmvc();
    while(tmp != "=>")
    {
      rmvc();
      a = makeint();
      std::cin >> tmp;
      rmvc();
      b = tmp;
      ingredients.push_back({b,a});
      std::cin >> tmp;
    }
    std::cin >> a >> b;
    react[b] = {a, ingredients};
    if(b == "BHVR")
    {
      return;
    }
  }
}

int main()
{
  input();
  std::cout <<"Minimum er: "<< made_of("FUEL") << '\n';
  return 0;
}
