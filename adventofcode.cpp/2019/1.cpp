#include <iostream>
using namespace std;

long long result=0, ekstra=0, tmp;

int main()
{
  while(std::cin >> tmp)
  {
    while(tmp > 0)
    {
      tmp/=3;
      tmp-=2;
      result+=tmp;
    }
    result -= tmp;
  }
  std::cout << result << '\n';
  return 0;
}
