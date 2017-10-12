#include <iostream>

int main()
{
  double A, B, D = 0;
  std::cout.precision(15);
  while(1)
  {
    char Input[33];
    fgets(Input, 33, stdin);
    if(sscanf(Input, "%lf %lf", &A, &B) != 2)
    {
      break;
    }
    D = A-B;
    if (D<0)
    {
      D = D* (-1);
    }
    std::cout << D << '\n';
  }
  return 0;
}
