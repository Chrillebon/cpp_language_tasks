#include <iostream>
#include <math.h>

int main()
{
  int Time;
  float H, v, factor;

  std::cin >> H >> v;
  if(v<=180)
  {
    std::cout << "safe" << '\n';
  }
  else
  {
    factor = H / sin( (v / 180) *
    M_PI);
    Time = abs(factor);
    std::cout << Time << '\n';
  }
  return 0;
}
