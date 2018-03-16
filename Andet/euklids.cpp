#include <iostream>
#include <cmath>
/*
int mingcd(int a,int b)
{
  while(1)
  {
    c=a%b;
    if(c==0)
    {
      return b;
      break;
    }
    else
    {
      a=b;
      b=c;
    }
  }
}*/

int gcd(int a, int b)
{
  int r = a % b;
  if(r == 0) return b;
  return gcd(b, r);
}

int main()
{
  //int a,b,c,Result;
  //std::cin >>a>>b;
  //---------------------------------
  std::cout << "Start!" << '\n';
  std::cout << gcd(a,b) << '\n';
  std::cout << big << '\n';
}

/*
497=1*322+175
a=tal*b+c
322=1*175+147
b=tal*c+a
175=1*147+28
c=tal*a+b
47=5*28+7
*/
