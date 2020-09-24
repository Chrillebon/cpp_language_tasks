#include <stdio.h>
#include <math.h>


int main()
{
  int total = 0;
  float num;
  float *listen = (double *)malloc(sizeof(double));
  printf("Please enter numbers to have the average calculated!\n");
  while(scanf("%f", &num) == 1) // Slut med "Ctrl+D"
  {
    total++;
    listen = realloc(listen,total*sizeof(double));
    *(listen+total-1) = num;
  }
  printf("test\n");
  double sum = 0;
  for(int i=0;i<total;i++)
  {
    sum += *(listen+i);
  }
  sum /= total;

  printf("Resultatet er: %f", sum);
  return 0;
}
