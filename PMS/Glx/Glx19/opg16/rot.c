#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#define PI 3.14159265359

int rot(double c, double s, int n, double * x, double * y){
  // matrix-vector product

  if(n <= 0)
  {
    return -1;
  }
  if(hypot(c,s) - 1 > 1e-15)
  {
    // Hvis der ikke er blevet brugt samme vinkel til at regne dette ud...
    return -1;
  }

  double tmp;
  for(int i=0;i<n;i++)
  {
    tmp = c*x[i] - s*y[i];
    y[i] = s*x[i] + c*y[i];
    x[i] = tmp;
  }
  return 0;
}


int main()
{
  // roterer pi/6
  double angle = PI/6;
  double c = cos(angle), s = sin(angle);
  double x[1] = {1};
  double y[1] = {0};
  int returnval = rot(c,s,1,x,y);
  printf("med return %d, fåes: %lf, samt %lf\n", returnval, x[0], y[0]);

  return 0;
}
