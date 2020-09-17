#include <stdio.h>
#include <string.h>
#define N 3

int main()
{
  double arr1[N], arr2[N];

  printf("Please enter %d numbers: \n", N);

  for(int i=0;i<N;i++)
  {
    scanf("%lf", &arr1[i]);
  }
  // Time to cpy memory:

  memcpy(&arr2, &arr1, sizeof(arr1));

  // Printer værdier:
  printf("\n");
  for(int i=0;i<N;i++)
  {
    printf("%lf " , *(arr2+i));
  }

  return 0;
}
