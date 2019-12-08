#include <iostream>
using namespace std;

int p,d,m,s, res=0;

int main()
{
  std::cin >> p >> d >> m >> s; //start $, drop/item, minimum, money
  while(s >= p && p > m)
  {
    s-=p; //costs moneyli
    res++; //one more game
    p-=d; //lowering cost of next
  }
  while(s >= m)
  {
    s -= m;
    res++;
  }
  std::cout << res << '\n';
  return 0;
}
