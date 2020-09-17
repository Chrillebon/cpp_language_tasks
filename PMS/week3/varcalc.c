#include <stdio.h>
#include <math.h>


int main()
{
  float onepass=0, twopass=0, mean=0;
  float data[6] = {34124.75, 34124.48, 34124.90, 34125.31, 34125.05, 34124.98};

  for(int i=0;i<6;i++)
  {
    mean += data[i];
  }
  mean /= 6;

  printf("mean: %lf\n\n", mean);

  // twopass calculation
  for(int i=0;i<6;i++)
  {
    twopass += pow(data[i]-mean,2);
  }
  twopass /= 6-1;


  // Twopass calculation
  for(int i=0;i<6;i++)
  {
    onepass += pow(data[i],2);
  }
  onepass -= 6*pow(mean,2);
  onepass /= 6-1;


  // Printer og sammenligner:

  printf("Vores onepass giver en varians:\n%lf\n\nVores twopass giver varians:\n%lf\n", onepass, twopass);

  return 0;
}
