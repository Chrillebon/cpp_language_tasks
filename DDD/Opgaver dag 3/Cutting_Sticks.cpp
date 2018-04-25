#include <iostream>



double best;

double power(int base)
{
  double res = 1;
  for(int i=0;i<base;i++)
  {
    res *= 2;
  }
}

double theory(int a, int left, int right, int stick)
{
  int lstick = a, rstick = stick-a;
  double res;
  if(left+right == 0)
  {
    return stick;
  }
  else if(left == 0)
  {
    res = stick+rstick * 1.0/power(right-1);
  }
  else if(left == 1)
  {
    if(right == 0)
    {
      res = stick+lstick;
    }
    else
    {
      res = stick + lstick*1.0/power(left-1) + rstick*1.0/power(right-1);
    }
  }
  //Ellers er left >= 2
  else if(right == 0)
  {
    res = stick+lstick * 1.0/power(left-1);
  }
  else
  {
    res = stick + rstick*1.0/power(right-1) + lstick*1.0/power(left-1);
  }
  return res;
}



int main()
{
  std::cout << theory(4, 0, 3, 10) << '\n';
  return 0;
}
