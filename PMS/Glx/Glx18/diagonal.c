#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define DBL_EPSILON 2.2204460492503131e-16

int dhhmv(int n, const double * u, double * x){
  if(n <= 2 || u == NULL || x == NULL){
    return -1;
  }
  double uJu = u[0]*u[0];
  for(int i=1;i<n;i++)
  {
    uJu -= u[i]*u[i];
  }
  if(fabs(uJu) <= 1.06*n*DBL_EPSILON/2)
  {
    return -1;
  }
  double *tmpx = (double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++){ tmpx[i] = x[i]; }
  // J matrix on x:
  for(int i=1;i<n;i++)
  {
    tmpx[i] *= -1;
  }

  // subtracting second half:
  double tmpk = 0;
  for(int i=0;i<n;i++)        // row-wise
  {
    tmpk = 2*u[i]/uJu;
    for(int o=0;o<n;o++)
    {
      tmpx[i] -= tmpk*x[o]*u[o];
    }
  }

  for(int i=0;i<n;i++)
  {
    x[i] = tmpx[i];
  }
  free(tmpx);

  return 0;
}

int dhhsv(int n, const double * u, double * x)
{
  if(n <= 2 || u == NULL || x == NULL){
    return -1;
  }
  double uJu = u[0]*u[0];
  for(int i=1;i<n;i++)
  {
    uJu -= u[i]*u[i];
  }
  if(fabs(uJu) <= 1.06*n*DBL_EPSILON/2)
  {
    return -1;
  }
  double *tmpx = (double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++){ tmpx[i] = x[i]; }
  // J matrix on x:
  for(int i=1;i<n;i++)
  {
    tmpx[i] *= -1;
  }

  // subtracting second half:
  double tmpk = 0;
  for(int i=0;i<n;i++)        // row-wise
  {
    tmpk = 2*u[i]/uJu;
    for(int o=0;o<n;o++)
    {
      if((i == 0 && o != 0) || (i != 0 && o == 0))
      {
        tmpx[i] += tmpk*x[o]*u[o];
      }
      else
      {
        tmpx[i] -= tmpk*x[o]*u[o];
      }
    }
  }

  for(int i=0;i<n;i++)
  {
    x[i] = tmpx[i];
  }
  free(tmpx);

  return 0;
}

int main()
{
  double testx[] = {1,2,3};
  double testu[] = {-2,7,3};
  int retval = dhhmv(3,testu, testx);
  printf("testing: %d\n", retval);
  for(int i=0;i<3;i++)
  {
    printf("%lf,\n", testx[i]);
  }

  testx[0] = 1;
  testx[1] = 2;
  testx[2] = 3;
  retval = dhhsv(3,testu, testx);
  printf("testing inverse: %d\n", retval);
  for(int i=0;i<3;i++)
  {
    printf("%lf,\n", testx[i]);
  }
  return 0;
}
