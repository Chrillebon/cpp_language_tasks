// parallel programming with "OpenMP"
#ifndef _OPENMP
#include <omp.h>
#endif

void omp_dgemv_v1(
    int m,         /* number of rows                   */
    int n,         /* number of columns                */
    double alpha,  /* scalar                           */
    double ** A,   /* two-dim. array A of size m-by-n  */
    double * x,    /* one-dim. array x of length n     */
    double beta,   /* scalar                           */
    double * y     /* one-dim. array x of length m     */
){
  int i,j;
  #pragma omp parallel for shared(m,n,alpha,beta,A,x,y) private(i,j)
  for (i=0;i<m;i++) {
    y[i] *= beta;
    for (j=0;j<n;j++) {
      y[i] += alpha*A[i][j]*x[j];
    }
  }
  return;
}
