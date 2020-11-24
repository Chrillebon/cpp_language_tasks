#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Since positive, transforming to log domain
*/
long binomial_v1(long n, long k)
{
  if(k < 0 || k > n)
  {
    return 0;
  }
  long res = 1, dif = n-k;
  double res2 = 0;
  for(int i=fmax(k,dif)+1;i<=n;i++)
  {
    // overflow
    /*if(res * i < res)
    {
      return -1;
    }
    res *= i;*/

    res2 += log(i);
  }
  for(int i=fmin(k,dif);i>0;i--)
  {
    res /= i;

    res2 -= log(i);
  }

  // rounding to avoid small numerical errors
  return (long)round(exp(res2));
}

long binomial_v2(long n, long k)
{
  if((n>k && k == 0) || (n == k && k>= 0))
  {
    return 1;
  }
  else if(n > k && k > 0)
  {
    return binomial_v2(n-1, k-1) + binomial_v2(n-1,k);
  }
  else
  {
    return 0;
  }
}

int main()
{
  // 100 choose 6 crashes longs...
  printf("testing v1: %ld\n", binomial_v1(100,6));
  //printf("testing v2: %ld\n", binomial_v2(100,6));

  // v1 er vandvittigt langsom, til gengæld får den stort svar...
  return 0;
}
