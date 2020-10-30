/* datatools.c - support functions for the matrix times vector example
 *
 * DTU Course 02635 - Fall 2015
 *
 * Author:  Bernd Dammann, DTU Compute
 * Version: $Revision: 1.2 $ $Date: 2015/11/10 11:03:12 $
 */
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <math.h>

#include "datatools.h"

void
init_data (int m, int n, double *x, double **A, double *y, double *ans) {

   int i, j;

   for (j=0; j<n; j++)
      x[j] = 1.0;

   #pragma omp parallel for private(i,j)
   for (i=0; i<m; i++)
   {
      ans[i] = n*i;
      y[i]   = -2005.0;
      for (j=0; j<n; j++)
         A[i][j] = i;
   }

}

int
check_results(int vnum, int m, int n, double *y, double *ans) {

   double relerr;
   int    i, errors = 0;
   char   *marker;
   double TOL   = 100.0 * DBL_EPSILON;
   double SMALL = 100.0 * DBL_MIN;

   if ( (marker=(char *)malloc(m*sizeof(char))) == NULL ) {
        perror("array marker");
        exit(-1);
   }

   for (i=0; i<m; i++)
   {
       if ( fabs(ans[i]) > SMALL )
       {
          relerr = fabs((y[i]-ans[i])/ans[i]);
       }
       else
       {
          relerr = fabs((y[i]-ans[i]));
       }
       if ( relerr <= TOL )
       {
          marker[i] = ' ';
       }
       else
       {
          errors++;
          marker[i] = '*';
       }
   }
   if ( errors > 0 )
   {
     printf("Routine with array size: %dx%d\n",vnum, vnum);
     printf("Found %d differences in results for m=%d n=%d:\n",
             errors,m,n);
     for (i=0; i<m; i++)
         printf("\t%c x[%d]=%f ans[%d]=%f\n",marker[i],i,y[i],i,ans[i]);
   }
   return(errors);
}

/* Routine for allocating two-dimensional array */
double **
malloc_2d(int m, int n)
{
    int i;

    if (m <= 0 || n <= 0)
	return NULL;

    double **A = (double **)malloc(m * sizeof(double *));
    if (A == NULL)
    {
      return NULL;
    }

    A[0] = (double *)malloc(m*n*sizeof(double));
    if (A[0] == NULL) {
    	free(A);
    	return NULL;
    }
    for (i = 1; i < m; i++)
	     A[i] = A[0] + i * n;
    return A;
}

void
free_2d(double **A) {
    free(A[0]);
    free(A);
}
