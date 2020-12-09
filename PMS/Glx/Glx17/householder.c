#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int householder(const double *v, double *x, unsigned int n){
  // T = I - 2 (v.v^T) / norm(v,2)²
  // altså skal vi trække 2 gange vv^T/norm(v,2)² fra x

  // for x[0] skal alle elementer der trækkes fra ganges med v[0]
  // samt alle værdierne:

  if(v == NULL || x == NULL || n <= 0)
  {
    return 0;
  }
  double norm2 = 0, tmp = 0;
  for(int i=0;i<n;i++)
  {
    tmp = norm2 + v[i]*v[i];
    if(tmp < norm2)
    {
      return -1;          // overflow
    }
    else
    {
      norm2 = tmp;
    }
  }

  if(norm2 == 0)          // only checking not div by 0, close should give error
  {
    return -1;
  }

  double *tmpx = (double *)malloc(n*sizeof(double));
  if(tmpx == NULL)
  {
    return -1;
  }
  double rowsum = 0;
  for(int i=0;i<n;i++)
  {
    rowsum += v[i]*x[i];
    tmpx[i] = x[i];
  }

  double loopk = 0;       // value used a lot in the loop
  for(int i=0;i<n;i++)
  {
    loopk = 2*v[i]/norm2;
    tmpx[i] -= loopk*rowsum;
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
  double testv[] = {-2,7,3};
  int retval = householder(testv, testx, 3);
  printf("testing: %d\n", retval);
  for(int i=0;i<3;i++)
  {
    printf("%lf,\n", testx[i]);
  }
  return 0;
}
/*
[2.354839, -2741935, 0.967742]
*/
