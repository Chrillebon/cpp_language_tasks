#include "array.h"
#include <stdio.h>

int main()
{
  // Her laves en test så vi kan se, at det virker
  // Opretter 2x3 matrix
  double **matrix;
  matrix = make2Dspace(2,3);
  // Gauss anyone???
  // Gemmer værdi på øverste venstre plads
  matrix[0][0] = 1.234;
  // Printer for at vise, at den har gemt
  printf("%f\n",matrix[0][0]);

  // Husk at rydde op efter dig!
  free2Dspace(matrix);
  return 0;
}
