#include <stdio.h>
#include <stdlib.h>

struct polynomial{
  int n;
  double * coef;
};

struct polynomial derivative(struct polynomial poly)
{
  struct polynomial newpoly;
  if(poly.n < 0)
  {
    return newpoly;
  }
  newpoly.n = poly.n-1;
  if(poly.coef == NULL)
  {
    return newpoly;
  }
  newpoly.coef = (double *)malloc(poly.n*sizeof(double));
  if(newpoly.coef == NULL)
  {
    return newpoly;
  }
  for(int i=1;i<=poly.n;i++)
  {
    newpoly.coef[i-1] = poly.coef[i]*i;
  }

  return newpoly;
}


int main()
{
  struct polynomial poly, d_poly;
  poly.n = 3;
  poly.coef = (double *)malloc(4*sizeof(double));
  poly.coef[0] = 3;
  poly.coef[1] = 3;
  poly.coef[2] = 3;
  poly.coef[3] = 10;

  d_poly = derivative(poly);
  for(int i=0;i<poly.n;i++)
  {
    printf("%lf, ", d_poly.coef[i]);
  }
  return 0;
}
