#include <stdio.h>
#include <math.h>

double stupid_implim(double x, double y)
{
  return sqrt(x*x+y*y);
}

double absolute(double value) {
  if (value < 0)
    return -value;

  return value;
}

double smart_implim(double x, double y)
{
  if(x >= y)
  {
    return absolute(x)*sqrt(1+pow(y/x,2));
  }
  else
  {
    return absolute(y)*sqrt(1+pow(x/y,2));
  }
}

int main()
{
  printf("Jeg tester med x = 10^200\n");
  double x = 10e200;
  double y = -10e200;
  printf("dumme loesning giver: %lf \n", stupid_implim(x,y));
  printf("smarte loesning giver: %lf \n", smart_implim(x,y));
  return 0;
}
