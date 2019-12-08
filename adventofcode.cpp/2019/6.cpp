#include <iostream>
#include <string>
#include <stdio.h>
#include <map>
#include <vector>
#include <utility>
using namespace std;

char tmp [20];

class OFDS //Orbit Find Disjoint Set
{
public:
  map<string, pair<int, vector<string> > > planets; //name, depth, orbitting this

  void update_depth(string a)
  {
    //std::cout << "again: " <<a<< '\n';
    for(int i=0;i<planets[a].second.size();i++) //go through all elements
    {
      planets[planets[a].second[i]].first = planets[a].first+1; //one more orbit deep
      update_depth(planets[a].second[i]); //recursion
    }
    return;
  }

  int new_planet(string a)
  {
    if(planets.count(a)) //Hvis den eksisterer
    {
      return 0;
    }
    else
    {
      planets[a] = pair<int, vector<string>> (0, vector<string>());
      return 1;
    }
  }

  void orbit(string a, string b)
  {
    new_planet(a);
    new_planet(b);
    planets[a].second.push_back(b);
    //std::cout <<"test"<< a <<'\n';
    update_depth(a);
  }

  int total(string a)
  {
    int t = planets[a].first;
    for(int i=0;i<planets[a].second.size();i++)
    {
      t += total(planets[a].second[i]);
    }
    return t;
  }
};

int main()
{
  char a[20], b[20];
  //scanf("%[^)] %*[)] %s", &a, &b); //totalt kodesprog, tager XXX)YYY
  OFDS solar_system;
  solar_system.new_planet("COM");
  while(cin >> tmp)
  {
    sscanf(tmp, "%[^)] %*[)] %s", &a, &b);
    string c = a,d=b;
    //std::cout << c << " og "<< d << '\n';
    solar_system.orbit(a,b);
  }
  std::cout << solar_system.total("COM") << '\n';
  return 0;
}
