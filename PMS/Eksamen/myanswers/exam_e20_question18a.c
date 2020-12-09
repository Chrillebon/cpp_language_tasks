#include <stdlib.h>
#include <math.h>

int darmv(int n, double * a, double * b, double * x) {
    if(n <= 0 || a == NULL || b == NULL || x == NULL)
    {
      return -1;
    }

    // x[k] is updated to a[k+1]*x[k]  (update only after adding contribution to last row)
    // last row, x[n-1] is updated by x[n-1][b1, b2, ..., b(n-1), an]*x

    double lastres = 0;
    for(int i=0;i<n-1;i++)
    {
      lastres += b[i]*x[i];
      x[i] *= a[i];
    }
    lastres += a[n-1]*x[n-1];
    x[n-1] = lastres;

    return 0;
}
