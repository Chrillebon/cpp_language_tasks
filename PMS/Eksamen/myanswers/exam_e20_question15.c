#include <math.h>
#define M_PI 3.14159265358979323846
#define DBL_EPSILON 2.2204460492503131e-16

double feval(double x) {
    // if x close to {0, pi, 2pi, 3pi,...}, we have problem...
    int close_pi = round(x / M_PI);
    // |x - close_pi*pi| is difference from closest k*pi, k in integers
    if(fabs(x-close_pi*M_PI) <= DBL_EPSILON)
    {
      return NAN;
    }
    else
    {
      // 1-cos(x) = 2*sin(x/2)²
      return 2*sin(x/2)*sin(x/2)/sin(x);//(1-cos(x))/sin(x);
    }
}
