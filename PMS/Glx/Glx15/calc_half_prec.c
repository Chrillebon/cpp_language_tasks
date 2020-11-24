#include <stdio.h>
#include <math.h>

int main()
{
  // max exponent: 15
  double E = 15, sum = 0;
  for(int i=0;i<=10;i++)
  {
    sum += pow(2,E-i);
  }
  printf("sum: %lf\n", sum);
  return 0;
}
