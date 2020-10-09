#include <stdio.h>
#include <stdlib.h>

// Gøre klar til plads for matrix
double** make2Dspace(int m, int n)
{
  // liste af lister (pointer til pointers)
  double **matrix;
  // Laver plads til "m" lister (pointers) af type double
  matrix = (double **)malloc(m*sizeof(double*));
  // Hvis der er allokeringsfejl
  if(matrix == NULL)
  {
    return NULL;
  }
  // Allokerer alt pladsen til alle elementer
  // Dette gøres på første plads (smarte hop
  // til andre steder i matricen kommer lige
  // om lidt)
  matrix[0] = (double *)malloc(m*n*sizeof(double));
  // igen, hvis der er problemer med allokering
  if(matrix[0] == NULL)
  {
    free(matrix);
    return NULL;
  }
  // Her laver vi alle de smarte hop som gør
  // at vi hurtigt kan komme til den række i
  // matricen som vi vil.
  // Hvis man altså hopper til matrix[2][4]
  // hopper man 2*n+4 ind i matricen
  // Får "første-koordinaten" til at virke
  for(int i=0;i<m;i++)
  {
    // "res[0] + i*n" betyder at vi skal have
    // en pointer til det sted i memory som
    // ligger i*n "længere henne" end dér hvor
    // matrix[0] peger hen.
    matrix[i] = matrix[0] + i*n;
  }

  return matrix;
}


void free2Dspace(double** matrix)
{
  // Rydder op efter os
  // Starter med at fjerne alle m*n værdier
  // som er "gemt på matrix[0]"
  free(matrix[0]);
  // Fjerner vores hop til forskellige steder
  // i vores m*n matrix
  free(matrix);
  return;
}
