#include <iostream>
#include <stdio.h>

void input(double T)
{

}

int subtract(int H, int M)
{
  int Minutes = M - 45;
  int Hours = H;
  if (Minutes < 0)
  {
    Hours = Hours - 1;
    if (Hours < 0)
    {
      Hours = 23;
    }
    Minutes = 60 + Minutes;
  }
  std::cout << Hours << " " << Minutes << '\n';
}

int main()
{
  int H, M;
  scanf("%d %d", &H, &M);
  subtract(H, M);
  return 0;
}
