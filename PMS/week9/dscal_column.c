#include <stdio.h>
#include <stdlib.h>

/* DSCAL (scale double array)                      */
void dscal_(
    const int * n,          /* length of array     */
    const double * a,       /* scalar a            */
    double * x,             /* array x             */
    const int * incx        /* array x, stride     */
);

int scale_column(double alpha, double **A, int m, int n, int k)
{
  // A of size m x n
  // scale row k, by alpha
  if(A == NULL || m<=0 || n <= 0 || k<0 || k>= n)
  {
    return -1;
  }
  if(A[0] == NULL)
  {
    return -1;
  }
  // n between elements, since C is row-major
  // m elements total
  dscal_(&m, &alpha, &A[0][k], &n);

  return 0;
}

int main()
{
  double **A;
  // A er 2x3
  A = (double**)malloc(2*sizeof(double*));
  A[0] = (double*)malloc(2*3*sizeof(double));
  A[1] = A[0]+3;
  A[1][2] = 3;
  scale_column(2,A,2,3,2);
  printf("test %lf\n", A[1][2]);
  return 0;
}
