#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

string rhyme;
vector<string> names;
vector<vector<string>> teams(2, vector<string>());

int words()
{
  int i=0,res=1;
  while(i<rhyme.length())
  {
    if(rhyme[i] == ' ')
    {
      res++;
    }
    i++;
  }
  return res;
}

int main()
{
  int res = 1, pick, children;
  getline(cin, rhyme);
  string tmp;
  pick = words();
  std::cin >> children;
  for(int i=0;i<children;i++)
  {
    std::cin >> tmp;
    names.push_back(tmp);
  }
  int where = 0, what = 0;
  for(int i=0;i<children;i++)
  {
    where += pick-1;
    where %= names.size();
    teams[what].push_back(names[where]);
    names.erase(names.begin()+where);
    what++;what%=2;
  }
  //output
  std::cout << teams[0].size() << '\n';
  for(int i=0;i<teams[0].size();i++)
  {
    std::cout << teams[0][i] << '\n';
  }
  std::cout << teams[1].size() << '\n';
  for(int i=0;i<teams[1].size();i++)
  {
    std::cout << teams[1][i] << '\n';
  }
  return 0;
}
