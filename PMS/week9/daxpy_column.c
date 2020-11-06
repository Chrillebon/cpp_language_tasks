#include <stdio.h>
#include <stdlib.h>

/* DAXPY (double a x plus y)                          */
void daxpy_(
    const int * n,        /* length of arrays x and y */
    const double * a,     /* scalar a                 */
    const double * x,     /* array x                  */
    const int * incx,     /* array x, stride          */
    double * y,           /* array y                  */
    const int * incy      /* array y, stride          */
);

int add_column(double alpha, double **A, int m, int n, int i, int j)
{
  // A of size m x n
  // add alpha*a_i to alpha*a_j
  if(A == NULL || m <= 0 || n <= 0 || i >= n || j >= n || i < 0 || j < 0 || i == j)
  {
    return -1;
  }
  if(A[0] == NULL)
  {
    return -1;
  }
  // n between elements
  daxpy_(&m, &alpha, &A[0][i], &n, &A[0][j], &n);

  return 0;
}

int main()
{
  double **A;
  A = (double**)malloc(2*sizeof(double*));
  A[0] = (double*)malloc(2*3*sizeof(double));
  A[1] = A[0]+3;
  A[1][2] = 3;
  add_column(2,A,2,3,2,0);
  printf("test %lf\n", A[1][0]);
  return 0;
}
