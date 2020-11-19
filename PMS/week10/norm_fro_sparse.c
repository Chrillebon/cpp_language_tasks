#include "matrix_io.h"

/* norm_fro_sparse
Purpose:
  Computes the Frobenius norm of a sparse matrix in triplet form.

Arguments:
  pA         a pointer to a matrix_t
  nrm        a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if one of the matrix dim. is 0
*/
int norm_fro_sparse(const sparse_triplet_t * pA, double * nrm) {

  if(pA == NULL || nrm == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(pA->I == NULL || pA->J == NULL || pA->V == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(pA->n <= 0 || pA->m <= 0 || pA->nnz < 0)
  {
    return MATRIX_IO_DIMENSION_MISMATCH;
  }
  // resetting before updating
  *nrm = 0;
  // Using hypot for each iteration
  for(int i=0;i<(pA->nnz);i++)
  {
    *nrm = hypot(*nrm, pA->V[i]);
  }
  return MATRIX_IO_SUCCESS;

}
