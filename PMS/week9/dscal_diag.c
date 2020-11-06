#include <stdio.h>
#include <stdlib.h>

/* DSCAL (scale double array)                      */
void dscal_(
    const int * n,          /* length of array     */
    const double * a,       /* scalar a            */
    double * x,             /* array x             */
    const int * incx        /* array x, stride     */
);

int scale_diag(double alpha, double **A, int n)
{
  // A of size m x n
  // scale row k, by alpha
  if(A == NULL || n <= 0)
  {
    return -1;
  }
  if(A[0] == NULL)
  {
    return -1;
  }
  // n+1 between elements, since we need next column and next row
  const int incx = n+1;
  dscal_(&n, &alpha, A[0], &incx);

  return 0;
}

int main()
{
  double **A;
  A = (double**)malloc(3*sizeof(double*));
  A[0] = (double*)malloc(3*3*sizeof(double));
  A[1] = A[0]+3;
  A[2] = A[0]+6;
  A[2][2] = 3;
  scale_diag(2,A,3);
  printf("test %lf\n", A[2][2]);
  return 0;
}
