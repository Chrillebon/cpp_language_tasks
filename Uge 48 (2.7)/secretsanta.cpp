#include <iostream>

int fak(int n)
{
  return (n == 1 || n == 0) ? 1 : fak(n - 1) * n;
}

float output(long long int n, float val, int fakul)
{
  if(n==1) return 1;
  if(n>8)
  {
    return 0.63212;
  }
  for(int i=1;i<=n;i++)
  {
    val += (1.0/fak(i) * (i%2 ? 1 : -1));
  }
  return val;
}

int main()
{
  long long int n;
  std::cin >> n;
  std::cout << output(n,0,1) << '\n';
  return 0;
}
