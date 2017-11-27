#include <iostream>
#include <cmath>
#include <math.h>

int main()
{
  int H,Time,v;

  std::cin >> H,v;
  std::cout << "v er lig med: " <<v<< '\n';
  if(v<=180)
  {
    std::cout << "safe" << '\n';
  }
  else
  {
    Time=abs(H/cos((v/180)*M_PI));
    std::cout << Time << '\n';
  }
  return 0;
}
