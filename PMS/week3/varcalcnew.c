#include <stdio.h>
#include <math.h>

float kahansum(float *x)
{
  double sum = 0.0, c = 0.0, t, y;
  int n = 6;
  for(size_t i=0;i<n;i++) {
    y = x[i] - c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  return sum;
}



int main()
{
  float onepass=0, twopass=0, mean=0;
  float data[6] = {34124.75, 34124.48, 34124.90, 34125.31, 34125.05, 34124.98};
  float tp[6], op[6];

  for(int i=0;i<6;i++)
  {
    mean += data[i];
  }
  mean /= 6;

  printf("mean: %lf\n\n", mean);

  // twopass calculation

  for(int i=0;i<6;i++)
  {
    tp[i] = pow(data[i] - mean,2);
  }
  twopass = kahansum(&tp);
  twopass /= 6-1;


  // onepass calculation
  for(int i=0;i<6;i++)
  {
    op[i] = pow(data[i],2);
  }
  onepass = kahansum(&op);
  onepass -= 6*pow(mean,2);
  onepass /= 6-1;


  // Printer og sammenligner:

  printf("Vores onepass giver en varians:\n%lf\n\nVores twopass giver varians:\n%lf\n", onepass, twopass);

  return 0;
}
