#include <stdio.h>
#include <stdlib.h>

/** DTRSV
 *  BLAS level 2 routine for forward/back substitution
 *  Documentation: http://www.netlib.org/blas/#_level_2
 */
void dtrsv_(
  const char * uplo,  /* upper 'U' or lower 'L'               */
  const char * trans, /* not trans. 'N' or trans. 'T'         */
  const char * diag,  /* not unit diag. 'N' or unit diag. 'U' */
  const int * n,      /* dimension                            */
  const double * A,   /* column-major matrix of order n       */
  const int * lda,    /* leading dimension of A               */
  double * x,         /* right-hand side                      */
  const int * incx    /* stride for array x                   */
);

/** Solves system of equations L*U*x = b where
 *  L is unit lower triangular and U is upper triangular.
 *  The matrices L and U must be stored in a single array M
 *  of size n-by-n. On exit, the array b is overwritten by
 *  the solution x.
 *
 *  If successful, the function returns zero, and in case
 *  of an error, the return value is -1.
 *
 *  Inputs:
 *    n       the size of the array M
 *    M       dynamically allocated two-dimensional array of size n-by-n
 *    b       one-dimensional array of length n
 */
int lu_solve(int n, double ** M, double * b) {

  if(M == NULL || b == NULL || n < 0)
  {
    return -1;
  }
  if(M[0] == NULL)
  {
    return -1;
  }

  // løser først Ly=b
  // derefter Ux=y
  // transponerer og tager derfor U for at finde L
  for(int i=0;i<n;i++)
  {
    if(M[i][i] == 0)
    {
      return -1;
    }
  }

  char UPLO = 'U';
  char TRANS = 'T';
  char DIAG = 'U';

  const int incx = 1;
  dtrsv_(&UPLO,&TRANS,&DIAG, &n, M[0], &n, b, &incx);
  UPLO = 'L'; DIAG = 'N';
  dtrsv_(&UPLO,&TRANS,&DIAG, &n, M[0], &n, b, &incx);

  return 0;
}

int main()
{
  double **A, *b;
  // A er 2x2
  A = (double**)malloc(2*sizeof(double*));
  A[0] = (double*)malloc(2*2*sizeof(double));
  A[1] = A[0]+2;
  A[0][0] = 1;
  A[0][1] = 2;
  A[1][0] = 3;
  A[1][1] = 4;
  b = (double*)malloc(2*sizeof(double));
  b[0] = 5;
  b[1] = 6;

  lu_solve(2, A, b);
  printf("test %lf og %lf\n", b[0], b[1]);
}


/*

LU x = b

y = Ux
Dermed
Ly = b
Derefter
Ux = y

*/
