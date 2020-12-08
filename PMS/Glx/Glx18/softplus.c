#include <stdio.h>
#include <math.h>

double softplus_deriv(double x)
{
  // testing if inf... Virker ikke helt godt...
  /*if(!isnormal(x) && x != 0)
  {
    return -99;
  }*/
  // after x >= 37, exp(37)+1 == exp(37)
  // exp(x)/(1 + exp(x))
  if(x>=37)
  {
    return 1;
  }
  // tager log af dette udtryk:
  else{
    double tmp = log1p(exp(x));
    return exp(x-tmp);
  }
}

int main()
{
  double tryvals[] = {0,200,16,-7,2,32,2e308};
  for(int i=0;i<7;i++)
  {
    printf("testing %lf: %.20lf\n", tryvals[i], softplus_deriv(tryvals[i]));
  }
  return 0;
}
