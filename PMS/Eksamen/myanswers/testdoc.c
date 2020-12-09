#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#define M_PI 3.14159265358979323846

double feval(double x);
double geval(double x);
double weighted_harmonic_mean(int n, double * x, double * w);
int darmv(int n, double * a, double * b, double * x);
int darsv(int n, double * a, double * b, double * x);


int main()
{
  double testvals15[] = {0.0001, M_PI+__DBL_EPSILON__/2,-M_PI+__DBL_EPSILON__*4, 2, 1, M_PI/2, M_PI-(1e-10), 0, __DBL_EPSILON__*2};
  printf("testing 15:\n");
  for(int i=0;i<9;i++)
  {
    printf("f(%lf) = %.20lf\n", testvals15[i], feval(testvals15[i]));
  }
  printf("\n\n");

  double t16[] = {0, 1e-5, 1, 5, -(1e-7),-0.5,100000000000};
  printf("testing 16:\n");
  for(int i=0;i<7;i++)
  {
    printf("f(%.10lf) = %.20lf\n", t16[i],geval(t16[i]));
  }
  printf("vs: %.20lf\n", pow(10000000000000000000002.0,1.0/3)-pow(10000000000000000000000.0,1.0/3));
  printf("\n\n");

  double x17[] = {17,3,106,1e-5,88};
  double w17[] = {3,5,7,9,11};
  printf("testing 17:\n");
  printf("%.15lf\n\n", weighted_harmonic_mean(5,x17,w17));

  double a18[] = {7,23,-3,0.075};
  double b18[] = {7,5,3};
  double x18[] = {5,6,7,8};
  int returnval = darmv(4,a18,b18,x18);
  printf("testing 18a: %d\n", returnval);
  for(int i=0;i<4;i++)
  {
    printf("%.10lf,\n", x18[i]);
  }

  double x18b[] = {5,6,7,8};
  returnval = darsv(4,a18,b18,x18b);
  printf("testing 18b: %d\n", returnval);
  for(int i=0;i<4;i++)
  {
    printf("%.10lf,\n", x18b[i]);
  }
  return 0;
}
