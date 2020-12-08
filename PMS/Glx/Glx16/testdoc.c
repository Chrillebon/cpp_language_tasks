#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define N 50

double * quad_eval(double a, double b, double c, double x) {
  double *pv;
  double val = b;
  pv = &val;
  val += a*x;
  val *= x;
  val += c;
  return pv;
}

double * init_array(size_t n, double h) {
  double * p = malloc(n*sizeof(*p));
  printf("Adresse før funktion: %p\n", p);
  if (p != NULL) {
  for (size_t i=0;i<n;i++)
    *(p++) = i*h;
  }
  return p;
}


int main()
{
  int testval = 2147483647;
  printf("%d\n", (testval-testval)-7);
  printf("%d\n", testval+(-testval-7));

  // big problem with function:
  double *dontfail = quad_eval(1,2,3,4);
  double *dontfail2 = quad_eval(5,6,7,8);
  // Har nu overskrevet gamle... giver samme resultat...
  printf("%lf @ %p vs %lf @ %p\n", *dontfail, dontfail, *dontfail2, dontfail2);
  printf("Skulle gerne have været forskellige^^\n");

  printf("tester q. 12)\n");
  double *p = init_array(N, 1);
  if (p == NULL) return EXIT_FAILURE;
  //for (size_t k=0;k<N;k++) printf("%3d %6g\n",k,p[k]);
  // ingen grund til at teste^^
  printf("Adresse efter funktion (no good): %p\n", p);

  double data[4] = {5.0,-2.0,2.0,0.0};
  data[1] *= 2.0;
  --data[1];
  printf("proving 0-index: %lf\n", data[0]);

  return 0;
}
