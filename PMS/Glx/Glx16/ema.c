#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ema(
  const double * x,
  double * y,
  unsigned long n,
  double alpha
){
  if(x == NULL || y == NULL || n <= 0 || alpha <= 0 || alpha >= 1)
  {
    return;
  }
  double res = x[0], alpham1 = 1-alpha;
  y[0] = x[0];
  for(unsigned long i=1;i<n;i++)
  {
    y[i] = alpha*x[i] + alpham1*y[i-1];
  }
  return;
}

int main()
{
  double testvals[10] = {1,2,4,8,16,32,64,128,256,512};
  double testres[10];
  ema(testvals,testres,10,0.5);
  printf("Her kommer de:\n");
  for(int i=0;i<10;i++)
  {
    printf("%lf,\n", testres[i]);
  }
  // Kan vel godt være rigtigt. Kommer mindre og mindre vægt fra de andre
  // jo længere man kommer...
  return 0;
}
