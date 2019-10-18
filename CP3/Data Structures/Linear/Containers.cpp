#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<stack<int>> s(30, stack<int>());
int tc=0;

void result()
{
  int r=0;
  for(int i=0;i<30;i++)
  {
    if(!s[i].empty())
    {
      r++;
    }
  }
  std::cout << "Case " <<tc<<": "<<r<< '\n';
  return;
}

void reset()
{
  for(int i=0;i<30;i++)
  {
    while(!s[i].empty())
    {
      s[i].pop();
    }
  }
  return;
}

void place(int a)
{
  int i=0;
  while(!s[i].empty() && s[i].top() < a)
  {
    i++;
  }
  s[i].push(a);
  return;
}

int main()
{
  char tmp;
  while(scanf("%1c", &tmp))
  {
    if(tmp == 10)
    {
      tc++;
      result();
      reset();
    }
    else if(tmp == 'e')
    {
      break;
    }
    else
    {
      place(tmp);
    }
  }
  return 0;
}
