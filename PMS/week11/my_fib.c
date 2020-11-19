#include <stdio.h>
#include <stdlib.h>

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
  printf("result: %u\n", my_fib(10));

  // how big??
  unsigned long biggestres = 0;
  long int i = 2;
  while(biggestres < my_fib(i))
  {
    biggestres = my_fib(i);
    i++;
  }
  printf("Biggest came from fib(%u) = %u\n", i, biggestres);
  return 0;
}

/*

f(5) -> f(4) + f(3)
= f(3) + f(2) + f(3)


f(1) = f(0) = 1
f(2) = f(0) + f(1)
f(3) = f(2) + f(1)
f(4) = f(3) + f(2)

*/
