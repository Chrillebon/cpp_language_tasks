#include <iostream>

int main()
{
  int b,k,g,days=0;
  std::cin >> b>>k>>g;
  while(b>1)
  {
    days +=1;
    b-=k/g;
  }
  std::cout << days << '\n';
  return 0;
}
