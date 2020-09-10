#include <stdio.h>
#include <math.h>

// Vi har f(x) = sqrt(x²+1) - 1
/*
når x er tæt på 0:

forlænger med (sqrt(x²+1)+1)

(x²+1-1)/(sqrt(x²+1)+1)
giver:

x²/(sqrt(x²+1)+1)

som er:

x²/(hypot(x,1)+1)


Når x er stor:

f(x) = hypot(x,1) - 1


*/

double absolute(double value) {
  if (value < 0)
    return -value;

  return value;
}

double feval(double x) {
    if(absolute(x) < 1)
    {
      return x*x/(hypot(x,1)+1);
    }
    else
    {
      return hypot(x,1) - 1;
    }
}

int main()
{
  printf("testing 1e-7 for: %.25f\n",feval(1e-7));
  return 0;
}
