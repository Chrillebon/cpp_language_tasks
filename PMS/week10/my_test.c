#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  double num[6] = {1,2,3,4,5,6};
  double res = 0;
  for(int i=0;i<6;i++)
  {
    res = hypot(res, num[i]);
  }
  printf("%lf\n", res);
  return 0;
}
