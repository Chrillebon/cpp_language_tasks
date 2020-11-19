#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

unsigned long fibonacci(unsigned long n){
  if(n == 0)
  {
    return 0;
  }
  else if(n == 1)
  {
    return 1;
  }
  else
  {
    return fibonacci(n-1) + fibonacci(n-2);
  }
}

unsigned long my_fib(unsigned long n)
{
  unsigned long m0 = 1;
  unsigned long m1 = 1, m2 = 0;

  for(int i=1;i<n;i++)
  {
    m0 = m1 + m2;
    // preparing for next:
    m2 = m1;
    m1 = m0;
  }
  return m0;
}

int main()
{
  FILE * rec = fopen("res5a.txt","w");
  FILE * loop = fopen("res5b.txt","w");
  clock_t t1, t2;
  for(int i=0;i<40;i++)
  {
    t1 = clock();
    fibonacci(i);
    t2 = clock();
    fprintf(rec, "[%d, %lf], ", i, ((double)(t2-t1)) / (CLOCKS_PER_SEC));
  }
  for(int i=2; i<1e7;i*=2)
  {
    t1 = clock();
    my_fib(i);
    t2 = clock();
    fprintf(loop, "[%d, %lf], ", i, ((double)(t2-t1)) / (CLOCKS_PER_SEC));
  }
  fclose(rec);
  fclose(loop);
  printf("DONE!\n");
  return 0;
}
