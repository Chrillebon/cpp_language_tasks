#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct sparse_triplet {
  unsigned long m;    // number of rows
  unsigned long n;    // number of columns
  unsigned long nnz;  // number of nonzeros
  unsigned long * I;  // pointer to array with row indices
  unsigned long * J;  // pointer to array with column indices
  double * V;         // pointer to array with values
} sparse_triplet_t;

void trans_sparse_triplet(sparse_triplet_t * sp)
{
  if(sp == NULL)
  {
    return;
  }
  int swap1;
  // swapping rows and columns...
  swap1 = sp->m;
  sp->m = sp->n;
  sp->n = swap1;

  unsigned long *swap2;
  swap2 = sp->I;
  // swapping pointers...
  sp->I = sp->J;
  sp->J = swap2;

  return;
}

void print_triplet(sparse_triplet_t *A)
{
  for(size_t i=0;i<A->nnz;i++)
  {
    printf("(%zu, %zu, %.2lf)\n", A->I[i], A->J[i], A->V[i]);
  }
  return;
}

sparse_triplet_t * init_triplet(FILE * source)
{
  sparse_triplet_t * A;
  A = (sparse_triplet_t*)malloc(sizeof(*A));
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

int main()
{
  FILE *mysparse;
  mysparse = fopen("sparse_matrix_A.txt", "r");
  sparse_triplet_t *A = init_triplet(mysparse);
  print_triplet(A);
  trans_sparse_triplet(A);
  printf("now transposed:\n");
  print_triplet(A);
  return 0;
}
