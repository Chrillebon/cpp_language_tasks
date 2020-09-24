#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  tager først i log-domæne, derefter tager jeg e^(logtallet)
*/

double poisson_pmf(unsigned long k, double lambda)
{
  if(lambda <= 0)
  {
    return NAN;
  }
  double logexpminlambda, res;
  // Lambda kan ikke være negativ
  // logexpminlambda = -lambda;
  double logtop = 0;
  double logbot = 0;
  for(int i=0;i<k;i++)
  {
    logtop += log(lambda);
    logbot += log(i+1);
  }
  res = logtop - logbot - lambda;

  return exp(res);
}

int main()
{
  printf("%.20lf\n", poisson_pmf(200,200));
  return 0;
}
