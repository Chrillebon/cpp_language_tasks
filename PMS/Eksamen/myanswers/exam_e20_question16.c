#include <math.h>

double geval(double x) {
    // can be rewritten!
    // a-b = (a³-b³)/(a²+ab+b²) = 2/(a²+ab+b²)
    // no subtractions!

    double a = pow(x*x+2, 1.0/3), b = pow(x*x, 1.0/3);
    double denom = a*a + a*b + b*b;
    return 2.0/denom;
}
