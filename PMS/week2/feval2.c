#include <stdio.h>
#include <math.h>

// Vi har f(x) = e^x-e^(-x)
/*

prøver med expm1(x)-expm1(-x)

tager log af det hele

log(e^x)+log(1+e^(-x)/e^x)
=x+log()

*/

double feval(double x) {
    return expm1(x)-expm1(-x);
}

int main()
{
  printf("testing 1e-7 for: %.25f\n",feval(1e-7));
  return 0;
}
