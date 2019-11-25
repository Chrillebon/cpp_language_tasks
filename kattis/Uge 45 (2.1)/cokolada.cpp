#include <iostream>

int t=0,K,o=1;

int run(int i)
{
  for(o=i;o>i-K;o/=2)
  {
    t++;
  }
  if(o<(i-K))
  {
    K=i-K-o;
    i=o;
    run(o);
  }
  else std::cout << t << '\n';
}

int main()
{
  int N,i;
  std::cin >> K;
  for(i=1;i<K;i*=2)
  {}
  N=i;
  std::cout << i <<" ";
  if(i==K)
  {
    std::cout << 0 << '\n';
    return 0;
  }
  run(i);
  return 0;
}
