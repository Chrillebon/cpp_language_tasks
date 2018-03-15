#include <iostream>
#include <stdlib.h>
#include <map>
#include <vector>
#include <time.h>
using namespace std;

char alf[] = {
  'a','b','c','d','e','f','g','h',
  'i','j','k','l','m','n','o','p',
  'q','r','s','t','u','v','w','x',
  'y','z',
  'A','B','C','D','E','F','G','H',
  'I','J','K','L','M','N','O','P',
  'Q','R','S','T','U','V','W','X',
  'Y','Z'
};

int vals[] = {
  2, 2, 1, 2, 1, 2, 3, 2,
  2, 2, 3, 1, 3, 2, 1, 2,
  2, 2, 1, 2, 2, 2, 4, 2,
  2, 3,
  3, 2, 1, 2, 4, 3, 1, 3,
  1, 1, 3, 2, 4, 3, 1, 2,
  1, 3, 1, 2, 1, 2, 4, 2,
  3, 3
};

int main()
{
  /* initialize random seed: */
  //srand (time(NULL));
  map<int, int> mapping;
  int alfkey, ran=rand()%42;
  for(int i=0;i<28*2;i++)
  {
    alfkey = alf[i];
    mapping[alf[i]] = alf[i]+vals[i]+ran;
  }
  std::vector<char> scentence;
  char letter;
  while(std::cin >> letter)
  {
    scentence.push_back(letter);
  }
  std::cout << ran << " ";
  char abchar;
  for(int i=0; i<scentence.size(); i++)
  {
    if(scentence[i] > 48 || scentence[i] < 90)
    {
      std::cout << scentence[i];
    }
    else
    {
      abchar = 48+(mapping[scentence[i]]%(90-48));
      std::cout << abchar;
    }
  }
  std::cout << '\n';
  return 0;
}
