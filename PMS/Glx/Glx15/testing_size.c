#include <stdio.h>

int main()
{
  double a = 0.5, b = a, c = 1.0e-16;
  a += c;
  a -= c;
  b -= c;
  b += c;

  if(a == 0.5 && b == 0.5)
  {
    printf("A.\n");
  }
  if(a == 0.5 && b < 0.5)
  {
    printf("B.\n");
  }
  if(a < 0.5 && b == 0.5)
  {
    printf("C.\n");
  }
  if(a < 0.5 && b < 0.5)
  {
    printf("D.\n");
  }
  return 0;
}
