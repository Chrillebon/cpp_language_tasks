#include <stdlib.h>
#include <stdio.h>

extern double *arr;   // Pointer to first element of array
extern int n;             // Number of elements

int main(void) {

    if (arr == NULL) return EXIT_FAILURE;

    for(int i=0;i<n;i++)
    {
      if(arr[i] < 0)
      {
        arr[i] = 0;
      }
    }

    /* Test: print elements of arr */
    for (int j=0; j<n; j++)
    	printf("%.2f ", arr[j]);

    return 0;
}
