#include <stdio.h>
#include <math.h>

struct options{
  double small, big;
};

typedef struct options twosolutions;

twosolutions stupid_implim(double a, double b, double c)
{
  twosolutions x;
  x.small = (-b-sqrt(b*b-4*a*c))/(2*a);
  x.big = (-b+sqrt(b*b-4*a*c))/2*a;
  return x;
}

/*
den lille ganget den store giver c/a

Så hvis vi skal finde den store kan vi:

x_stor = c/(a*x_small)


Anden mulighed: forlænger den store med (-b-sqrt(b²-4ac))
*/
twosolutions smart_implim(double a, double b, double c)
{
  twosolutions x;
  x.small = (-b-sqrt(b*b-4*a*c))/(2*a);
  x.big = 2*c/(-b-sqrt(b*b-4*a*c));
  return x;
}

int main()
{
  double alpha, beta, gamma;
  alpha = 1;
  gamma = 1;
  beta = 100;
  twosolutions stupres,smartres;
  stupres = stupid_implim(alpha,beta,gamma);
  smartres = smart_implim(alpha,beta,gamma);
  printf("tester den dumme: %lf \n", stupres.big);
  printf("tester den smarte: %lf \n", smartres.big);

  return 0;
}
