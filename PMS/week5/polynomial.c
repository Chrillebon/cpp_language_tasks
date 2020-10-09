#include "polynomial.h"

/* Allocates a new polynomial structure */
poly_t * poly_new(unsigned int n) {
    poly_t * q = malloc(sizeof(*q));
    if (q==NULL) return NULL;
    q->n = n;
    q->coef = calloc(n+1,sizeof(*(q->coef)));
    if (q->coef==NULL) {
        free(q);
        return NULL;
    }
    return q;
}

/* Frees a polynomial structure */
void poly_del(poly_t * p) {
    free(p->coef);
    free(p);
}

/* Prints a polynomial structure */
void poly_print(poly_t * p) {
    unsigned int i;
    if (p==NULL)
        fprintf(stderr,"poly_print: invalid pointer\n");
    else {
        for (i=p->n;i>0;i--)
            printf("%+g*x^%d ", p->coef[i], i);
        printf("%+g\n", p->coef[0]);
    }
}

double poly_eval(poly_t *p, double x) {
    if(p == NULL)
    {
      return NAN;
    }
    else if(p->coef == NULL)
    {
      return NAN;
    }
    int n = p->n;
    double fx = 0;
    // Kører n+1 gange
    for(int i=n;i>=0;i--)
    {
      fx *= x;
      fx += p->coef[i];
    }
    return fx;
}

poly_t * poly_mul(const poly_t * p1, const poly_t * p2) {
    if(p1 == NULL || p2 == NULL)
    {
      return NULL;
    }
    if(p1->coef == NULL || p2->coef == NULL)
    {
      return NULL;
    }

    // Her begynder logikken
    int n1 = p1->n, n2 = p2->n;
    poly_t *newpol = poly_new(n1+n2);
    for(int i=n1;i>=0;i--)
    {
      for(int o=n2;o>=0;o--)
      {
        newpol->coef[i+o] += p1->coef[i] * p2->coef[o];
      }
    }
    return newpol;
}

int main()
{
  int x = 1;
  double koefficienter[5] = {1,2,3,4,5};
  poly_t *mypol = poly_new(4);
  for(int i=0;i<5;i++)
  {
    mypol->coef[i] = koefficienter[i];
  }
  poly_print(mypol);
  //poly_del(mypol);
  return 0;
}
