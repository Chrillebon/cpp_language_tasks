#include <stdio.h>
#include <math.h>
#ifndef op
#define op +
#endif
// Ændre operator^^

int main()
{

  float x[] = {-INFINITY,-1.0,-0.0,0.0,1.0,INFINITY,NAN};
  float y[] = {-INFINITY,-1.0,-0.0,0.0,1.0,INFINITY,NAN};
  for(int i=0;i<7;i++)
  {
    for(int o=0;o<7;o++)
    {
      printf("%.1f  ", (x[i] op y[o]));
    }
    printf("\n");
  }
  return 0;
}

// ret sej tabel!
