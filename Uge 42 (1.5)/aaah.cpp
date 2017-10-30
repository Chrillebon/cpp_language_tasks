#include <iostream>
#include <string>
using namespace std;

int main()
{
  string Today, Doctor;
  int LT, LD;
  cin >> Today >> Doctor;
  if(Today.find_first_of("h")>=Doctor.find_first_of("h"))
  {
    cout << "go" << endl;
  }
  else
  {
    cout << "no" << endl;
  }
}
