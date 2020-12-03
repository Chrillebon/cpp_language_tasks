#include <iostream>
using namespace std;

template <class T>
const T& max (const T& a, const T& b)
{
  return (a<b)?b:a;
}

template <class T>
const T& abs (const T& a)
{
  return (a < -a)?-a:a;
}

int main()
{
  double returnval;
  std::cin >> returnval;
  returnval = abs(returnval);
  std::cout << "finaltest: " <<returnval<< '\n';
  printf("testing val 1: %d\n", abs(-3));
  printf("testing val 2: %f\n", abs(-3.4));
  return 0;
}
