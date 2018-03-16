#include <iostream>

int count_to_ten()
{
  for(double i=0;i<=9;i++)
  {
    std::cout << "nr. " << i << " er hvad vi naaet til" << '\n';
  }
  double i = 10;
  std::cout << "og saa slutter vi af paa" << " " << i <<'\n';
  return 0;
}

bool true_or_false()
{
  std::cout << "er du sikker paa, at du vil afslutte?" << '\n';

  while (true)
  {
    char answer = 0;
    std::cin >> answer;
    switch (answer)
    {
      case 'y': return true;
      case 'n': return false;
      default:
      std::cout << "proev igen " << '\n';
    }
  }
}

double sum()
{
  double num[]{205,3812,489,321,843,890,100};
  double summ = 0;
  for(auto i:num)
    summ += i;
  std::cout << "dette er en tiendedel af summen: " << summ/10 << '\n';
  return summ;
}

double product()
{
  double num[7]{6,3,4,3,8,2,10};
  double pro = 1;
  double* f = &num[1];
  for(int i=0 ; i!= 7; i++)
    pro *= num[i];
  std::cout << "dette er produktet: " << pro << '\n';
  std::cout << "dette er en pointer: " << f << '\n';
}

int main()
{
  /*std::cout << "Hello World" << '\n';

  count_to_ten();*/

  sum();
  product();

  return 0;
}
