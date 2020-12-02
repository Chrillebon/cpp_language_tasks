#include <stdio.h>
#include <stdlib.h>

void printmatrix(double matrix[][3])
{
  for(int i=0;i<9;i++)
  {
    printf("%lf\n", *(matrix[0]+i));
  }
  return;
}

void printmatrix_fail(double ** matrix)
{
  for(int i=0;i<9;i++)
  {
    printf("%lf\n", *(matrix[0]+i));
  }
  return;
}


int main()
{
  double **pR;
  pR = (double**)malloc(3*sizeof(double*));
  // test om alloc failer
  pR[0] = (double*)malloc(3*sizeof(double));
  // test om alloc failer igen
  for(int i=1;i<3;i++)
  {
    pR[i] = pR[0] + 3*i;
  }

  double otherR[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
  for(int i=0;i<3*3;i++){
    *(pR[0]+i) = *(otherR[0]+i);
  }
  printf("size: %lf\n", sizeof(pR));

  printmatrix(&otherR);         // klarer det fint
  printmatrix_fail(pR);         // klarer det fint
  printmatrix_fail(&otherR);    // fejler katastrofalt...
  return 0;
}
