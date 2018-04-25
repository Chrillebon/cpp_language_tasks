#include <iostream>
#include <math.h>
#include <algorithm>

void memset(int arr[])
{
  for(int i=0;i<500500;i++)
  {
    arr[i] = -1;
  }
}

int n;
int sum[500500];
int numb[500500];
int result = 0;

void move(int i, int d)
{
  if(d == n)
  {
    result = std::max(result, sum[i]);
    return;
  }
  if(sum[i+d] < sum[i]+numb[i+d])
  {
    sum[i+d] = sum[i]+numb[i+d];
    move(i+d,d+1);
  }
  if(sum[i+d+1] < sum[i]+numb[i+d+1])
  {
    sum[i+d+1] = sum[i]+numb[i+d+1];
    move(i+d+1,d+1);
  }
}

int main()
{
  memset(sum);
  std::cin >> n;
  int maxsize = ceil((n+1)*(1.0*n/2));
  for(int i=0;i<maxsize;i++)
  {
    std::cin >> numb[i];
  }
  sum[0] = numb[0];
  move(0,1);
  std::cout << result << '\n';
  return 0;
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
