#include <stdio.h>
#include <math.h>

double linear_max(
  const double x,
  const double *a, /* array with a coefficients */
  const double *b, /* array with b coefficients */
  unsigned int n
){
  if(a == NULL || b == NULL || n < 0)
  {
    return NAN;
  }
  if(n == 0)
  {
    return 0;
  }
  double maxval = a[0]*x+b[0];
  for(int i=1;i<n;i++)
  {
    maxval = fmax(maxval, a[i]*x+b[i]);
  }
  return maxval;
}

int main()
{
  double avals[] = {1,2,3};
  double bvals[] = {-1,-2,-3};
  printf("testing: %lf\n", linear_max(3, avals, bvals, 3));
  return 0;
}
