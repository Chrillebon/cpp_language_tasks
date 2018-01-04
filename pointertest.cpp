#include <iostream>
#include <string>
#include <string.h>

void pointer(char* numb[10])
{
  std::string name = "asdf";
  numb[0] = strdup(name.c_str());
}

int main()
{
  char* numb[10];
  pointer(numb);
  //numb[0] = "asdf";
  std::cout << numb[0] << '\n';
  return 0;
}
