#include <math.h>
#include <stdio.h>
#define DBL_EPSILON 2.2204460492503131e-16

int orthogonal(
  const double * x,
  const double * y,
  unsigned long n
){
  if(x == NULL || y == NULL || n <= 0)
  {
    return 0;
  }
  // benytter absolute error:
  double nu = DBL_EPSILON*n*0.5, theta;
  if(nu < 0.1)
  {
    theta = 1.06*nu;
  }
  else if(nu < 1)
  {
    theta = nu/(1-nu);
  }
  else
  {
    return 0;
  }
  double res = 0, absres = 0;
  for(unsigned long i=0;i<n;i++)
  {
    res += x[i]*y[i];
    absres += fabs(x[i]*y[i]);
  }
  if(fabs(res) <= theta*absres)     // testing absolute error
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int main()
{
  double x1[] = {0.1,0.3};
  double y1[] = {3,-1};
  printf("tester med det opgivne: %d\n", orthogonal(x1,y1,2));
  // prøver med en smule anden:
  double x2[] = {0.1000000000000001,0.3};
  double y2[] = {3,-1};
  printf("tester med en smule anden: %d\n", orthogonal(x2,y2,2));
  // Den mindste forskel jeg kunne finde, før den runder ned og
  // de bliver ortogonale^^
  return 0;
}
