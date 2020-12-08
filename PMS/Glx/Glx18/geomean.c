#include <stdio.h>
#include <math.h>

double geo_mean(unsigned int n, const double * x)
{
  if(x == NULL || n <= 0)
  {
    return NAN;
  }
  double res = 0;
  for(unsigned int i=0;i<n;i++)
  {
    if(x[i] <= 0)        // nonnegative!
    {
      return NAN;
    }
    res += log(x[i]);
  }
  res /= n;
  return exp(res);
}

int main()
{
  double testvals[] = {7,8,4,2,18,5,0.4};
  printf("maple siger: 3.991011054\ntesting: %lf\n", geo_mean(7,testvals));
  return 0;
}
