#include <stdio.h>
#include <stdlib.h>
#ifndef _OPENMP
#include <omp.h>
#endif
#include "datatools.h"

void omp_dgemv_v1(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
);
void my_dgemv_v1(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
);

/*
Datasize for optimal plots:
cache 1: 64 KB
cache 2: 512 KB
cache 3: 3072 KB

sizeof(double) = 8 bytes

Første grænse størrelse
sqrt(64000/8) = 90x90 double

Anden grænse størrelse:
sqrt(512000/8) = 253x253 double

Sidste grænse størrelse
sqrt(3072000/8) = 620x620 double

[20, 40, 80, 120, 180, 240, 300, 450, 600, 750, 1000, 1200]
[ 1,  1,  1,   2,   2,   2,   3,   3,   3,   4,    4,    4]
*/

int main()
{
  int dimsize[] = {20, 40, 80, 120, 180, 240, 300, 450, 600, 750, 1000, 1200};
  double *x, *y, **A, *ans;
  double alpha = 1;
  double beta = 0;
  double times1[12] = {0};
  //char description[100] = "test";
  for(int i=0;i<12;i++)
  {
    printf("testing for arraysize %dx%d\n", dimsize[i], dimsize[i]);
    x = (double *)malloc(dimsize[i]*sizeof(double));
    y = (double *)malloc(dimsize[i]*sizeof(double));
    A = malloc_2d(dimsize[i], dimsize[i]);
    ans = (double *)malloc(dimsize[i]*sizeof(double));

    init_data(dimsize[i], dimsize[i], x, A, y, ans);
    omp_dgemv_v1(dimsize[i],dimsize[i], 1, A, x, 0, y);
    check_results(dimsize[i], dimsize[i], dimsize[i], y, ans);

    free_2d(A);
    free(x);
    free(y);
    free(ans);
  }
}
