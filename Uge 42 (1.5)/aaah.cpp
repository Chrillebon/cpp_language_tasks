#include <iostream>
#include <string>
using namespace std;

int main()
{
  string Today, Doctor;
  int LT, LD;
  scanf("%s \n %s", &Today, &Doctor);
  if(Today.length()>=Doctor.length())
  {
    std::cout << "go" << '\n';
  }
  else
  {
    std::cout << "no" << '\n';
  }
}
