#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct polynomial {
  unsigned int n;
  double *coef;
};

double polyeval(struct polynomial *p, double x)
{
  if(p == NULL)
  {
    return NAN;
  }
  if(p->coef == NULL || p->n == 0)
  {
    return NAN;
  }
  double res = p->coef[p->n];
  for(int i=p->n-1;i>=0;i--)
  {
    res *= x;
    res += p->coef[i];
  }
  return res;
}

struct polynomial * poly_mul(
  const struct polynomial *p1,
  const struct polynomial *p2
){
  if(p1 == NULL || p2 == NULL)
  {
    return NULL;
  }
  if(p1->coef == NULL || p2->coef == NULL || p1->n <= 0 || p2->n <= 0)
  {
    return 0;
  }
  struct polynomial *newpoly = (struct polynomial *)malloc(sizeof(*newpoly));
  if(newpoly == NULL)
  {
    return NULL;
  }
  newpoly->n = p1->n + p2->n;
  // calloc since all needs to start at 0!
  newpoly->coef = (double *)calloc((newpoly->n)+1,sizeof(double));

  if(newpoly->coef == NULL)
  {
    free(newpoly);
    return NULL;
  }
  for(int i=0;i<=p1->n;i++)
  {
    for(int o=0;o<=p2->n;o++)
    {
      newpoly->coef[i+o] += p1->coef[i]*p2->coef[o];
    }
  }
  return newpoly;
}

int main()
{
  struct polynomial test;
  test.n = 2;
  test.coef = (double *)malloc(3*sizeof(double));
  test.coef[0] = -7;
  test.coef[1] = 3;
  test.coef[2] = 4;
  printf("f(x) = 4*x²+3*x-7 \nf(-1) = %lf\n", polyeval(&test, -1));

  struct polynomial test2;
  test2.n = 2;
  test2.coef = (double *)malloc(3*sizeof(double));
  test2.coef[0] = 9;
  test2.coef[1] = 8;
  test2.coef[2] = 7;
  printf("testing\n");
  struct polynomial *res = poly_mul(&test, &test2);

  printf("eval: 4*x²+3*x-7 * 7*x²+8*x+9 =\n");
  for(int i=0;i<=res->n;i++)
  {
    printf("%lf*x^%d\n", res->coef[i], i);
  }
  return 0;
}
