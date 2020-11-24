#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double angle(double *x, double *y, int n)
{
  if(x == NULL || y == NULL)
  {
    return -361;
  }
  if(n <= 0)
  {
    return -361;
  }

  double norm_x = 0.0, norm_y = 0.0, dot = 0.0;
  int i;
  for (i=0;i<n;i++) {
    norm_x = hypot(norm_x, x[i]);
    norm_y = hypot(norm_y, y[i]);

    dot += x[i]*y[i];
  }

  return acos(dot/(norm_x*norm_y));
}

int main()
{
  double xvals[3] = {1,2,3};
  double yvals[3] = {-3,0,1};
  printf("angle found to: %lf\n", angle(xvals,yvals,3));
  double xvals2[3] = {1,1,1};
  double yvals2[3] = {-2,-2,-2};
  printf("angle found to: %lf\n", angle(xvals2,yvals2,3));

  return 0;
}
