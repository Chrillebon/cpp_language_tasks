#include <iostream>

bool isprime(int numb)
{
  int o = 2;
  while(o * o <= numb)
  {
    if(numb % o == 0)
    {
      return false;
    }
    o++;
  }
  return true;
}

bool ispal(int numb)
{
  char a[8];
  int n = 0, m = 0;
  for(int i=10;i<=100000000;i*=10)
  {
    a[n] = numb % i / (i/10);
    n++;
  }
  n = 7;
  while(a[n] == 0)
  {
    n--;
  }
  n++; //index to length
  while(m<n/2)
  {
    if(a[m] != a[n-m-1])
    {
      return false;
    }
    m++;
  }
  return true;
}

int main()
{
  std::cout << "2, ";
  for(int i=3;i<=100000000;i+=2)
  {
    if(ispal(i))
    {
      if(isprime(i))
      {
        std::cout << i << ", ";
      }
    }
  }
  std::cout << '\n';
  std::cout << "DONE!!!" << '\n';
  return 0;
}
