#include <iostream>
#include <string>
using namespace std;
#include "7.h"

int main()
{
  Towers test;
  std::cout << "Test af klasser giver: " << test.name() << " og " << test.weight() << " og "  << test.relation(0) << " og "  << test.relation(1) << " og "  << test.relation(2) << " og "  << test.relation(3) << " og "  << test.relation(4) << " og "  << test.relation(5) << " og "  << test.relation(6)<< " og til sidst: "<< test.relations()<< '\n';

  return 0;
}
