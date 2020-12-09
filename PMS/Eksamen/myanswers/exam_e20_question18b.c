#include <stdlib.h>
#include <math.h>
#define DBL_EPSILON 2.2204460492503131e-16

int darsv(int n, double * a, double * b, double * x) {
  if(n <= 0 || a == NULL || b == NULL || x == NULL)
  {
    return -1;
  }

  // Almost same as other
  // diagonal elements are 1/a[k]
  // last row is -b[k]/(a[k]*a[n-1])
  // if any a[k] == 0, then matrix singular...

  double lastres = 0;
  if(fabs(a[n-1]) <= DBL_EPSILON)
  {
    return -1;                              // Singular matrix...
  }
  for(int i=0;i<n-1;i++)
  {
    if(fabs(a[i]) <= DBL_EPSILON)
    {
      return -1;                            // Singular matrix...
    }
    lastres -= b[i]*x[i]/(a[i]*a[n-1]);
    x[i] /= a[i];
  }
  lastres += x[n-1]/a[n-1];
  x[n-1] = lastres;

  return 0;
}
