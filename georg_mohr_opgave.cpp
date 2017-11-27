#include <iostream>
//#include <cmath>

int main()
{
  double sum=(1.0+1.0/2.0)*(1.0+1.0/2.0);
  std::cout << "Den starter på: " <<sum<< '\n';
  for(int i=3.0;i<1000.0;i++)
  {
    sum *= (1.0+(1.0/i))*(1.0+(1.0/i));
  }
  std::cout << sum << '\n';
  return 0;
}
