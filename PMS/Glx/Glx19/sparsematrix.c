#include <stdio.h>
#include <stdlib.h>

// structure:
typedef struct sparse_triplet{
  size_t m; // number of rows
  size_t n; // number of columns
  size_t nnz; // number of non-zero elements
  size_t * I; // pointer to array with row indices
  size_t * J; // pointer to array with column indices
  double * V; // pointer to array with values
} sparse_triplet;

sparse_triplet * init_triplet(FILE * source)
{
  sparse_triplet * A;
  A = (sparse_triplet*)malloc(sizeof(*A));
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

void clean_triplet(sparse_triplet * A)
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

void print_triplet(sparse_triplet *A)
{
  for(size_t i=0;i<A->nnz;i++)
  {
    printf("(%zu, %zu, %.2lf)\n", A->I[i], A->J[i], A->V[i]);
  }
  return;
}

void write_triplet(const char *filename, sparse_triplet *A)
{
  remove(filename);
  FILE * newfile;
  newfile = fopen(filename, "w");
  fprintf(newfile, "%zu %zu %zu\n", A->m, A->n, A->nnz);
  for(int i=0;i<A->nnz;i++)
  {
    fprintf(newfile, "%zu %zu %.1lf\n", A->I[i], A->J[i], A->V[i]);
  }
  return;
}

int main()
{
  FILE * matrix;
  matrix = fopen("sparse_matrix_A.txt", "r");
  sparse_triplet *A = init_triplet(matrix);
  //print_triplet(A);
  write_triplet("resultatet_er.txt", A);
  clean_triplet(A);

  fclose(matrix);
  matrix = NULL;
  return 0;
}
