#include <iostream>
#include <string>
#include <string.h>

/*void pointer(char numb[][20])
{
  std::string name = "asdf";
  numb[0] = strdup(name.c_str());
}*/

int main()
{
  char *numb[20];
  //char *ptr[20] = &numb;
  //pointer(numb);
  //numb[0] = "asdf";
  std::string name = "asdf";
  numb[0] = strdup(name.c_str());
  std::cout << *numb << '\n';
  return 0;
}
