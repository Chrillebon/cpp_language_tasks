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
  double rowsum = 0;
  double *tmpx = (double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++){
    rowsum += x[i]*u[i];
    tmpx[i] = x[i];
  }
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
    tmpx[i] -= tmpk*rowsum;
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
  double rowsum = -2*x[0]*u[0]; // first has to be -1, so preparing for loop
  double *tmpx = (double*)malloc(n*sizeof(double));
  for(int i=0;i<n;i++){
    rowsum += x[i]*u[i];
    tmpx[i] = x[i];
  }  // J matrix on x:
  for(int i=1;i<n;i++)
  {
    tmpx[i] *= -1;
  }

  // subtracting second half:
  double tmpk = 0;
  for(int i=0;i<n;i++)        // row-wise
  {
    tmpk = 2*u[i]/uJu;
    if(i == 0)
    {
      tmpx[i] += tmpk*rowsum;
    }
    else
    {
      tmpx[i] -= tmpk*rowsum;
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


/*
-0.55555555
3.4444444
-0.66666667
*/
/*
2.851852
4.481481
-0.222222
*/
