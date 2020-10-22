#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void my_dgemv_v1(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
);
void my_dgemv_v2(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
);

int main()
{
  clock_t t1, t2;
  int n[] = {100,200,300,400,500,600,700,800,900,1000};
  int m[] = {100,200,300,400,500,600,700,800,900,1000};
  double times1[10] = {0};
  double times2[10] = {0};
  double alpha = 2;
  double beta = 3;
  double * x, *y, **A;
  for(int i=0;i<10;i++)
  {
    x = (double *)malloc(n[i]*sizeof(double));
    y = (double *)malloc(n[i]*sizeof(double));
    A = (double **)malloc(m[i]*sizeof(double*));
    A[0] = (double *)malloc(m[i]*n[i]*sizeof(double));
    for(int o=1;o<m[i];o++)
    {
      A[o] = A[0]+o*n[i];
    }

    for(int o=0;o<m[i];o++)
    {
      x[o] = 2;
      y[o] = 3;
      for(int u=0;u<n[i];u++)
      {
        A[o][u] = 4;
      }
    }
    t1 = clock();
    my_dgemv_v1(m[i], n[i], alpha, A, x, beta, y);
    t2 = clock();
    times1[i] = ((double)(t2-t1)) / (CLOCKS_PER_SEC);

    t1 = clock();
    my_dgemv_v2(m[i], n[i], alpha, A, x, beta, y);
    t2 = clock();
    times2[i] = ((double)(t2-t1)) / (CLOCKS_PER_SEC);
    free(x);
    free(y);
    free(A[0]);
    free(A);
  }

  for(int i=0;i<10;i++)
  {
    printf("%lf, ", times1[i]);
  }
  printf("\n");
  for(int i=0;i<10;i++)
  {
    printf("%lf, ", times2[i]);
  }
  printf("\n");

  return 0;
}
