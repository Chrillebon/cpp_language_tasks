#include <stdio.h>
#include <math.h>

double softplus(double x) {
  if(x>1000)
  {
    return x;
  }
  else if(x < 1)
  {
    return log1pl(exp(x));
  }
  else
  {
    return log1pl(1.0+expm1l(x));
  }
}

int main()
{
  printf("%.25lf\n", softplus(-50));
  return 0;
}


/* Svaret:

double softplus(double x) {
    if (x > 0)
        return x + log1p(exp(-x));
    else
        return log1p(exp(x));
}

*/
