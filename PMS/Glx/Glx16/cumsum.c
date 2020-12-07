#include <stdio.h>
#include <math.h>

void cumsum(
  const double * x,
  double * y,
  unsigned long n
){
  if(x == NULL || y == NULL)
  {
    return;
  }
  double res = 0;
  for(unsigned long i=0;i<n;i++)
  {
    res += x[i];
    y[i] = res;
  }
}

int main()
{
  double x[] = {1,1,1,1,1,1,1};
  double y[7];
  cumsum(x,y,7);
  for(int i=0;i<7;i++)
  {
    printf("%lf,\n", y[i]);
  }
  return 0;
}
