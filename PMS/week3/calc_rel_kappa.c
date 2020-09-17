#include <stdio.h>
#include <math.h>

double absolute(double value) {
  if (value < 0)
    return -value;

  return value;
}

int main(){
  float data[6] = {34124.75, 34124.48, 34124.90, 34125.31, 34125.05, 34124.98};

  float s1 = 0.0, s2 = 0.0, s3 = 0.0;
  float K_s1 = 0.0, K_s2 = 0.0, K_s3 = 0.0;

  // S1 = sum(x_i)
  float abssum = 0.0;
  float sumabs = 0.0;
  for(int i=0;i<6;i++)
  {
    abssum += absolute(data[i]);
    s1 += data[i];
  }
  sumabs = absolute(s1);
  K_s1 = abssum/sumabs;


  // S2 = sum(x_i²)
  abssum = 0.0;
  sumabs = 0.0;
  for(int i=0;i<6;i++)
  {
    abssum += absolute(pow(data[i],2));
    s2 += pow(data[i],2);
  }
  sumabs = absolute(s2);
  K_s2 = abssum/sumabs;


  // S3 = S2-1/n S1²
  abssum = absolute(s2)+absolute(-pow(s1,2)/2);
  sumabs = s2-pow(s1,2)/2;
  sumabs = absolute(sumabs);
  printf("%f vs %f\n", -pow(s1,2)/2,absolute(-pow(s1,2)/2));
  printf("%f vs %f\n", -1/2*pow(s1,2), absolute(-1/2*pow(s1,2)));
  K_s3 = abssum/sumabs;

  printf("Størrelsen af Kappa for de 3 værdier er:\n%f\n%f\n%f", K_s1,K_s2,K_s3);

  return 0;
}
