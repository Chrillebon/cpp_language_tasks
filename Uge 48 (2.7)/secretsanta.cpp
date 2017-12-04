#include <iostream>

float output(float n, float val)
{
  if(n==1) return val;
  val = 1/n*1+(1-1/n)*(1+output(n-1,val));
}

int main()
{
  float n;
  std::cin >> n;
  std::cout << output(n,1) << '\n';
  return 0;
}
