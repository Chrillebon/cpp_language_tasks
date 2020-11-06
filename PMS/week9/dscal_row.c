#include <stdio.h>
#include <stdlib.h>

/* DSCAL (scale double array)                      */
void dscal_(
    const int * n,          /* length of array     */
    const double * a,       /* scalar a            */
    double * x,             /* array x             */
    const int * incx        /* array x, stride     */
);

int scale_row(double alpha, double **A, int m, int n, int k)
{
  // A of size m x n
  // scale row k, by alpha
  if(A == NULL || m<=0 || n <= 0 || k<0 || k>= m)
  {
    return -1;
  }
  if(A[0] == NULL)
  {
    return -1;
  }
  // 1 between elements, since C is row-major
  const int incx = 1;
  dscal_(&n, &alpha, A[k], &incx);

  return 0;
}

int main()
{
  double **A;
  A = (double**)malloc(2*sizeof(double*));
  A[0] = (double*)malloc(2*3*sizeof(double));
  A[1] = A[0]+3;
  A[0][2] = 3;
  scale_row(2,A,2,3,0);
  printf("test %lf\n", A[0][2]);
  return 0;
}
