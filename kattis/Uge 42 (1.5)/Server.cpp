#include <iostream>

int main()
{
  int N, T, Sum = 0, Result = 0;
  scanf("%d %d", &N, &T);
  for(;Result<N;Result++)
  {
    int Time;
    scanf("%d", &Time);
    Sum += Time;
    if(Sum==T)
    {
      std::cout << Result+1 << '\n';
      break;
    }
    else if(Sum>T)
    {
      std::cout << Result << '\n';
      break;
    }
  }
  if (Sum<T)
  {
    std::cout << N << '\n';
  }
  return 0;
}
