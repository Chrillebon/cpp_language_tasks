#include "sparse_triplet.h"
#include <stdio.h>

void sparse_triplet_mv_trans(
    const struct sparse_triplet *A,
    const double *x,
    double *y) {
    // Opgaven siger, at alle inputs er valid!
    // Antager dermed også, at størrelserne passer!

    /*
                        x0
                        x1
                        x2
                        x3
      [A00  A01  A02]^T     y0
      [A10  A11  A12]    =  y1
      [A20  A21  A22]       y2
      [A30  A31  A32]
    */
    for(int i=0;i<A->nnz;i++)
    {
      // Trækker 1 fra, da 1 vs 0-indexeret!
      // Bytter om på I og J, da transponeret
      y[A->J[i]-1] += A->V[i] * x[A->I[i]-1];
    }
    return;
}

struct sparse_triplet * init_triplet(FILE * source)
{
  struct sparse_triplet * A;
  A = (struct sparse_triplet*)malloc(sizeof(*A));
  //size_t m,n,nnz;
  fscanf(source, "%zu %zu %zu", &A->m, &A->n, &A->nnz);
  // allocating memory for arrays
  A->I = (size_t *)malloc(A->nnz*sizeof(A->I[0]));
  A->J = (size_t *)malloc(A->nnz*sizeof(A->J[0]));
  A->V = (double *)malloc(A->nnz*sizeof(A->V[0]));


  // saving values
  for(size_t i=0;i<A->nnz;i++)
  {
    fscanf(source, "%zu", &A->I[i]);
    fscanf(source, "%zu", &A->J[i]);
    fscanf(source, "%lf", &A->V[i]);
  }
  return A;
}

void clean_triplet(struct sparse_triplet * A)
{
  free(A->I);
  A->I = NULL;
  free(A->J);
  A->J = NULL;
  free(A->V);
  A->V = NULL;
  free(A);
  A = NULL;
  return;
}

void print_vector(double * y, int n)
{
  printf("Vector = [");
  for(int i=0;i<n-1;i++)
  {
    printf("%lf, ", y[i]);
  }
  printf("%lf]\n", y[n-1]);
  return;
}

void print_triplet(struct sparse_triplet *A)
{
  printf("A:\n");
  for(size_t i=0;i<A->nnz;i++)
  {
    printf("(%zu, %zu, %.2lf)\n", A->I[i], A->J[i], A->V[i]);
  }
  return;
}

int main()
{
  FILE * matrix;
  matrix = fopen("sparse_matrix_A.txt", "r");
  struct sparse_triplet *A = init_triplet(matrix);
  // A er her 3x4
  double x[3] = {1,2,3};
  double y[4] = {10,10,10,10};

  print_vector(x,3);
  print_vector(y,4);
  print_triplet(A);
  printf("svar:\n");

  sparse_triplet_mv_trans(A,x,y);
  print_vector(y,4);

  clean_triplet(A);

  fclose(matrix);
  matrix = NULL;
  return 0;
}
