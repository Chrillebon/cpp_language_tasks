#include <stdio.h>
#include <math.h>

double logfactorial(unsigned int n)
{
  // No need to check negative, since unsigned
  double logres = 0;
  for(int i = 1; i <= n; i++)
  {
    logres += log(i);
  }
  return logres;
}

int main()
{
  unsigned int testvals[] = {0,1,2,5,50,100,1000};
  for(int i=0;i<7;i++)
  {
    printf("testing for log(%d!) = %lf\n", testvals[i], logfactorial(testvals[i]));
  }
  return 0;
}
