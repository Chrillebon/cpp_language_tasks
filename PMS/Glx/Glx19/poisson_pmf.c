#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double poisson_pmf(unsigned long k, double lambda) {
  if(lambda <= 0)
  {
    return NAN;
  }
  double res = k*log(lambda);
  for(unsigned long i=1;i<=k;i++)
  {
    res -= log(i);
  }
  res -= lambda;

  return exp(res);
}

int main()
{
  printf("Tester Pois(3, 3): %lf, \nsamt Pois(100,95): %lf\n", poisson_pmf(3,3),poisson_pmf(100,95));

  return 0;
}
