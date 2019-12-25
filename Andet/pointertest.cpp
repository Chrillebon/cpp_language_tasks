#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <utility>
using namespace std;

/*void pointer(char numb[][20])
{
  std::string name = "asdf";
  numb[0] = strdup(name.c_str());
}*/

map<char,int> gamma(map<char,int> &alpha)
{
  alpha['a'] = 0;
  return alpha;
}

int main()
{
  map<char,int> alpha;
  map<char,int> beta;
  beta = gamma(alpha);
  std::cout << "så: " <<alpha.size()<<" samt "<<beta['a']<< '\n';
  /*char *numb[20];
  //char *ptr[20] = &numb;
  //pointer(numb);
  //numb[0] = "asdf";
  std::string name = "asdf";
  numb[0] = strdup(name.c_str());
  std::cout << *numb << '\n';*/
  /*int a = 7;
  int *b = &a;
  int *c = b;
  int *d = c;
  *d -= 5;
  std::cout << a << '\n';*/ //Giver 2
  return 0;
}
