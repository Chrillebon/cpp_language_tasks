#include "matrix_io.h"

/* dot
Purpose:
  Computes the inner product of two vectors.

Arguments:
  px         a pointer to a vector_t
  py         a pointer to a vector_t
  xy         a pointer to a double

Return value:
  An int with one of the following values:
   - MATRIX_IO_SUCCESS if no error occured
   - MATRIX_IO_ILLEGAL_INPUT if an input is NULL
   - MATRIX_IO_DIMENSION_MISMATCH if the vectors have diff. len.
*/
int dot(const vector_t * px, const vector_t * py, double * xy) {

  if(px == NULL || py == NULL || xy == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(px->v == NULL || py->v == NULL)
  {
    return MATRIX_IO_ILLEGAL_INPUT;
  }
  if(px->n <= 0 || py->n <= 0 || px->n != py->n)
  {
    return MATRIX_IO_DIMENSION_MISMATCH;
  }
  *xy = 0;
  for(int i=0;i<px->n;i++)
  {
    *xy += px->v[i]*py->v[i];
  }
  return MATRIX_IO_SUCCESS;
}
