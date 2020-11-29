#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void rotg(double a, double b, double * c, double * s){
  // En rotationsmatrice for a og b
  // Roterer, så vektoren ligger langs x-aksen

  // skal opfylde: <a,b> = r <c, -s>

  double r = hypot(a,b);
  if(r == 0)
  {
    return;
  }
  *c = a/r;
  *s = -b/r;

  return;
}


int main()
{
  double a, b, c, d;
  a = sqrt(2)/2;
  b = -a;
  rotg(a,b,&c,&d);
  // Skal rotere med pi/4 radianer
  // cos(pi/4) = sqrt(2)/2 = 0.7071067810
  // sin(pi/4) = sqrt(2)/2 = 0.7071067810

  printf("Res1: %lf, og %lf\n", c,d);

  rotg(0,1, &c,&d);

  // Skal rotere med -pi/2 radianer
  // cos(-pi/2) = 0
  // sin(-pi/2) = -1
  printf("Res2: %lf, og %lf\n", c,d);

  return 0;
}
