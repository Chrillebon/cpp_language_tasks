#include <stdio.h>
#include <string.h>

//void *memcpy(void *dest, const void *src, size_t n)

int main(void) {

  double arr1[4] = {1.0, 2.0, 3.0, 4.0};
  double arr2[4];

  memcpy(&arr2, &arr1, sizeof(arr1));

  /* Test: print out contents of arr2 */
  for (int i=0; i<sizeof(arr2)/sizeof(double); i++)
    printf("%.2f ", arr2[i]);

  return 0;
}
