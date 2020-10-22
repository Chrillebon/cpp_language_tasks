#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>

#define MAX_SIZE 16777216
extern int datasize1(int);
double arr[MAX_SIZE];           // gloval array of length MAX_SIZE


int main()
{
  clock_t t1, t2;
  float times[12] = {0};
  double arraysize[12] = {0};
  double flops[12] = {0};
  long int sizes[] = {128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 167772};
  long int totalsize = 0;
  for(int i=0;i<12;i++)
  {
    for(int o=0;o<10;o++)
    {
      totalsize = (double)sizes[i]*100;
      t1 = clock();
      datasize1(totalsize);
      t2 = clock();
      times[i] += ((double)(t2-t1)) / (CLOCKS_PER_SEC);
    }
    times[i] /= 10;
    arraysize[i] = totalsize*sizeof(double);
    flops[i] = arraysize[i]/times[i];
    printf("%.12lf, ", arraysize[i]);
  }

  return 0;
}
