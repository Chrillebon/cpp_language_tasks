#include <iostream>

int gohigh(int tal)
{
  int m=1,res=1;
  for(int i=0;i<=15;i++)
  {
    if(m > tal)
    {
      return i-1;
    }
    m*=2;
    res+=m;
  }
}

int bisum(int tal)
{
  int val = 32768, res = 0;
  while(tal > 0)
  {
    if(val <= tal)
    {
      tal -= val;
      res++;
    }
    else
    {
      val /= 2;
    }
  }
  return res;
}

int bipower(int tal, int base)
{
  int res = 1;
    for(int i=0;i<base;i++)
    {
      res *= tal;
    }
    return res-1;
}

int main()
{
  int n;
  std::cin >> n;
  std::cout << gohigh(n)+bisum(n-bipower(2,gohigh(n))) << '\n';
  return 0;
}
