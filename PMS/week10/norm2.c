#include "matrix_io.h"

/* norm2
Purpose:
  Computes the Euclidean norm of a vector.

Arguments:
  px         a pointer to a vector_t
  nrm        a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if the vector has length 0
*/
int norm2(const vector_t *px, double *nrm) {
  if(px == NULL || nrm == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(px->n <= 0)
  {
    return MATRIX_IO_DIMENSION_MISMATCH;
  }
  // resetting before updating
  *nrm = 0;
  // Using hypot for each iteration
  for(int i=0;i<px->n;i++)
  {
    *nrm = hypot(*nrm, px->v[i]);
  }
  return MATRIX_IO_SUCCESS;
}
