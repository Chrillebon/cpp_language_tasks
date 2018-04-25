#include <iostream>

int res = 0, n;

void addpart(int lastwhite, int d)
{
  if(d == n)
  {
    res++;
    return;
  }
  if(!lastwhite)
  {
    addpart(1, d+1);
  }
  addpart(0, d+1);
  addpart(0, d+1);
}

int main()
{
  std::cin >> n;
  addpart(0, 0);
  std::cout << res << '\n';
  return 0;
}
