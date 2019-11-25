#include <iostream>

int main()
{
  double A, B, D = 0;
  std::cout.precision(25);
  while(std::cin >> A >> B)
  {
    D = A-B;
    if (D<0)
    {
      D = D* (-1);
    }
    std::cout << D << '\n';
  }
  return 0;
}

/*int main()
{
  double D = 0;
  std::cout.precision(15);
  double A, B;
  while(scanf("%lf %lf", &A,&B) != EOF);
  {
    D = A-B;
    if (D<0)
    {
      D = D* (-1);
    }
    std::cout << D << '\n';
  }
  return 0;
}*/
