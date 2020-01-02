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
long long spent = 0;
int res = 0, minrest = 9999;

int made_of(string name)
{
  long long total = 0;
  if(react[name].second[0].first == "ORE") //End of line
  {
    //std::cout << react[name].second[0].second <<" from "<<name<< '\n';
    return react[name].second[0].second;
  }
  else
  {
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

int sumres()
{
  int s = 0;
  for(map<string,int>::iterator it=reserve.begin();it!=reserve.end();it++)
  {
    s += it -> second;
  }
  return s;
}

int main()
{
  input();
  spent += made_of("FUEL");
  res++;
  while(!(spent >= 1000000000000 || sumres() == 0))
  {
    spent += made_of("FUEL");
    res++;
    if(res % 100 == 0)
    {
      std::cout << res << " og "<<spent<<'\n';
    }
  }
  std::cout << "Den totale mængde brændstof er (maybe -1): " <<res<<" og der er brugt præcis: "<<spent<<" med rest = "<<sumres()<< '\n';
  return 0;
}


//Prøver pr. gennemsnit:
//Det er ikke:
//5.194.100 (er for lav...)
//5.194.110
//5.194.130
//5.194.172
//5.194.173

//Svaret var 5.194.174
