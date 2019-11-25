#include <iostream>

double a,b,c;

bool test(double e,double f)
{
  if(e+f==c)
  {
    return true;
  }
  if(e-f==c)
  {
    return true;
  }
  if(e*f==c)
  {
    return true;
  }
  if(e/f==c)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  int N;
  std::cin >> N;
  for(int i=0;i<N;i++)
  {
    std::cin >> a>>b>>c;
    if(test(a,b)||test(b,a))
    {
      std::cout << "Possible" << '\n';
    }
    else
    {
      std::cout << "Impossible" << '\n';
    }
  }
}
