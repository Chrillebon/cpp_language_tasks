#include <iostream>
#include <string.h>
using namespace std;

class person{
private:
  int age;
  string name;

public:
  person(){
    std::cout << "Please enter your name: " << '\n';
    getline(cin, name);
    std::cout << "And how old are you?" << '\n';
    std::cin >> age;
  }

  greet(){
    std::cout << "Hello "<< name << " aged "<<age<<" year(s) old!" << '\n';
  }
};

int main()
{
  person you;
  you.greet();
  return 0;
}
