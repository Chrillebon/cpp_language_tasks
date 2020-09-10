#include <stdio.h>
#include <math.h>

double absolute(double value) {
  if (value < 0)
    return -value;

  return value;
}

int main() {
  for(int i=0;i<=16; i++)
  {
    double x,base;
    base = 10;
    x = pow(base,-i);
    double cosval = cos(x);
    printf("%lf \n", cosval);
  }
  return 0;
}
