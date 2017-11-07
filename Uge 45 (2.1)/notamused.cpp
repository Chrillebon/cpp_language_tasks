#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Names;
vector<int> Arrival(20);

int sortname(string name)
{
  for(int i=0;i<20;i++)
  if(Names[i].compare(name))
  {
    return i;
  }
}



int main()
{
  string What;

  while(std::cin >> What)
  {
    if(What == "OPEN")
    {

    }
    if(What == "ENTER")
    {

    }
    if(What == "EXIT")
    {}
    if(What == "CLOSE")
    {}
  }
  return 0;
}
