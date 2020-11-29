#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int dcemv(int n, double * x) {
  // C = I - 1/n 1*1^T
  // altså diagonal 1, alle felter trukket 1/n fra

  if(n <= 0 || x == NULL)
  {
    return -1;
  }

  // Løber igennem alle rækker
  // Række i, skal element i ganget med 1-1/n

  // På en anden måde sagt, vi kan trække 1/n fra alle
  // elementer, da vi så har x-=1/n  =>  x= Cx

  double sum = 0;
  for(int i=0;i<n;i++)
  {
    sum += x[i];
  }
  sum /= -n;
  for(int i=0;i<n;i++)
  {
    x[i] += sum;
  }

  return 0;
}

int main()
{
  int n=3;
  double x[3] = {1,2,3};
  int returnval = dcemv(3,x);
  printf("returnval: %d \n[", returnval);
  for(int i=0;i<n-1;i++)
  {
    printf("%lf, ", x[i]);
  }
  printf("%lf]\n", x[n-1]);
  return 0;
}
