#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;


int main()
{
  string What;
  string Who;
  int When, n,Day=0;
  map<string, float> Names;

  while(std::cin >> What)
  {
    if(What == "OPEN")
    {
      Day+=1;
      Names.erase ( Names.begin(), Names.end() );
    }
    if(What == "ENTER")
    {
      std::cin >> Who >> When;
      if(Names[Who]) Names[Who] -= When;
      else Names[Who] = -When;
    }
    if(What == "EXIT")
    {
      std::cin >> Who >> When;
      Names[Who] += When;
    }
    if(What == "CLOSE")
    {
      std::cout << "Day " <<Day<< '\n';
      for(map<string,float>::iterator itr = Names.begin();itr!=Names.end();itr++)
      {
        std::cout << itr->first <<" $"<< fixed << setprecision(2) << itr->second*0.1 << '\n';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
