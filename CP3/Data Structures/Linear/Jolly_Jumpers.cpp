#include <iostream>
#include <math.h>

bool jol[3001];
int num[3001];
int n = 0;

int difference(int a, int b)
{
  return abs(a-b);
}

bool jolly()
{
  for(int i=1;i<n;i++)
  {
    if(jol[i] != 1)
    {
      return 0;
    }
  }
  return 1;
}

int reset()
{
  for(int i=0;i<=n;i++)
  {
    jol[i] = 0;
    num[i] = 0;
  }
  return 0;
}

int main()
{
  while(std::cin >> n)
  {
    for(int i=0;i<n;i++)
    {
      std::cin >> num[i];
    }
    //Klar nu:
    int dif = 0;
    for(int i=0;i<n-1;i++)
    {
      dif = difference(num[i], num[i+1]);
      jol[dif] = 1;
    }
    if(jolly() || n == 1)
    {
      std::cout << "Jolly" << '\n';
    }
    else
    {
      std::cout << "Not jolly" << '\n';
    }
    reset();
  }
  return 0;
}
