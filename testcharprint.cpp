#include <iostream>

int main()
{
  char number[3];
  std::cin >> number;
  int tal=number[0] - '0';
  std::cout << number[0] <<" = "<<tal<< '\n';
  return 0;
}
