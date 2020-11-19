#include "matrix_io.h"

/* norm_fro
Purpose:
  Computes the Frobenius norm of a matrix.

Arguments:
  pA         a pointer to a matrix_t
  nrm        a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if one of the matrix dim. is 0
*/
int norm_fro(const matrix_t * pA, double * nrm) {

  if(pA == NULL || nrm == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(pA->A == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(pA->A[0] == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(pA->n <= 0 || pA->m <= 0)
  {
    return MATRIX_IO_DIMENSION_MISMATCH;
  }
  // resetting before updating
  *nrm = 0;
  // Using hypot for each iteration
  for(int i=0;i<(pA->n * pA->m);i++)
  {
    *nrm = hypot(*nrm, pA->A[0][i]);
  }
  return MATRIX_IO_SUCCESS;

}
