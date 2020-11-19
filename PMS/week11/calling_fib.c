#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int total_fib = 0;
int max_depth = 0;

unsigned long fibonacci(unsigned long n, unsigned depth){
  total_fib ++;
  if(depth > max_depth)
  {
    max_depth = depth;
  }
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
    return fibonacci(n-1, depth+1) + fibonacci(n-2, depth+1);
  }
}

int main()
{
  printf("testing: %u\n", fibonacci(6,1));
  FILE * res = fopen("res3.txt", "w");
  for(int i=1;i<40;i++)
  {
    total_fib = 0;
    max_depth = 0;
    fibonacci(i, 1);
    fprintf(res, "[%d, %d], ", i,max_depth);//total_fib);
    printf("nu er vi ved: %d\n", i);
  }

  fclose(res);
  return 0;
}
