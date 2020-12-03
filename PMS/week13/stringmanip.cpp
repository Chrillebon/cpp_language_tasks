#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
  list<string> L;
  std::cout << "Please keep entering strings, and end with a number, which is how many characters that are allowed:" << '\n';
  string tmp;
  char tmp2[200];
  int maxchar;
  while(1)
  {
    std::cin >> tmp;
    if(tmp[0] >= 48 && tmp[0] <= 57)
    {
      maxchar = tmp[0] - 48;
      int index = 1;
      while(1)
      {
        if(tmp[index] >= 48 && tmp[index] <= 57)
        {
          maxchar *= 10;
          maxchar += tmp[index] - 48;
        }
        else
        {
          break;
        }
      }
      break;
    }
    else
    {
      L.push_back(tmp);
    }
  }

  for(int i=0;i<L.size();i++)
  {
    tmp = L.back();
    if(tmp.length() > maxchar)
    {
      std::cout << tmp << '\n';
    }
    L.pop_back();
  }
  return 0;
}
