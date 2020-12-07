#include <stdio.h>
#include <stdlib.h>

double * diff(double *x, int n)
{
  if(x == NULL)
  {
    return NULL;
  }
  // no difference if 1 element or less
  if(n <= 1)
  {
    return NULL;
  }
  double * y = (double *)malloc((n-1)*sizeof(double));
  if(y == NULL)
  {
    return NULL;
  }
  for(int i=0;i<(n-1);i++)
  {
    y[i] = x[i+1] - x[i];
  }
  return y;
}

int main()
{
  if(diff(NULL,7) == NULL)
  {
    printf("first test failed\n");
  }
  int n = 3;
  double * x = (double *)malloc(n*sizeof(double));
  if(diff(x,1) == NULL)
  {
    printf("second test failed\n");
  }
  x[0] = 1;
  x[1] = -7;
  x[2] = 99;
  double *res = diff(x,n);
  if(res != NULL)
  {
    printf("third test success!\n");
  }
  for(int i=0;i<n-1;i++)
  {
    printf("%lf, ", res[i]);
  }printf("\n");
  return 0;
}
