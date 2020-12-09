#include <stdlib.h>
#include <math.h>

double weighted_harmonic_mean(int n, double * x, double * w) {
    if(n <= 0 || x == NULL || w == NULL)
    {
      return NAN;
    }

    double top = 0, bot = 0;
    for(int i=0; i<n; i++)
    {
      if(x[i] <= 0 || w[i] <= 0)          // only positive elements allowed
      {
        return NAN;
      }
      bot += w[i]/x[i];
      top += w[i];
    }

    return top/bot;
}
