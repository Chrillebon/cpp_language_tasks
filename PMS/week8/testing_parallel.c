#include <stdio.h>
#include <stdlib.h>
//#ifndef _OPENMP
#include <omp.h>
//#endif
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
void omp_dgemv_v2(
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

[20, 40, 80, 120, 180, 240, 300, 450, 600, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500, 2750, 3000]
[ 1,  1,  1,   2,   2,   2,   3,   3,   3,   4,    4,    4]
*/

int main()
{
  int dimsize[] = {20, 40, 80, 120, 180, 240, 300, 450, 600, 750, 1000, 1250, 1500, 1750, 2000, 2250, 2500, 2750, 3000};
  double *x, *y, **A, *ans;
  double alpha = 1;
  double beta = 0;
  double times1[19] = {0}, times2[19] = {0}, tstart, tend;
  //char description[100] = "test";
  for(int i=0;i<19;i++)
  {
    printf("testing for arraysize %dx%d\n", dimsize[i], dimsize[i]);
    x = (double *)malloc(dimsize[i]*sizeof(double));
    y = (double *)malloc(dimsize[i]*sizeof(double));
    A = malloc_2d(dimsize[i], dimsize[i]);
    ans = (double *)malloc(dimsize[i]*sizeof(double));

    // taking average of time
    for(int o=0;o<20;o++)
    {
      // Row-wise
      init_data(dimsize[i], dimsize[i], x, A, y, ans);
      tstart = omp_get_wtime();
      omp_dgemv_v1(dimsize[i],dimsize[i], 1, A, x, 0, y);
      tend = omp_get_wtime();
      check_results(dimsize[i], dimsize[i], dimsize[i], y, ans);

      times1[i] += tend-tstart;


      // Column-wise
      init_data(dimsize[i], dimsize[i], x, A, y, ans);
      tstart = omp_get_wtime();
      omp_dgemv_v2(dimsize[i],dimsize[i], 1, A, x, 0, y);
      tend = omp_get_wtime();
      check_results(dimsize[i], dimsize[i], dimsize[i], y, ans);

      times2[i] += tend-tstart;
    }
    times1[i] /= 20;
    times2[i] /= 20;

    free_2d(A);
    free(x);
    free(y);
    free(ans);
  }


  // Printing results
  printf("Printing data for the wanted cores run in parallel:\n");
  printf("Memory needed (KB): \n");
  for(int i=0;i<19;i++)
  {
    printf("%.3lf, ", 8.0*dimsize[i]*dimsize[i]/1000);
  }
  printf("\n\n");
  printf("Flops for row-wise:\n");
  double flo;
  for(int i=0;i<19;i++)
  {
    // assuming n*n + n flo
    flo = dimsize[i]*dimsize[i]+dimsize[i];
    printf("%.3lf, ", flo/times1[i]);
  }
  printf("\n\n");
  printf("Flops for column-wise:\n");
  for(int i=0;i<19;i++)
  {
    // assuming n*n + n flo
    flo = dimsize[i]*dimsize[i]+dimsize[i];
    printf("%.3lf, ", flo/times2[i]);
  }
  printf("\n");
}
