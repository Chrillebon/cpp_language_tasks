/*
ID: Christi69
PROB: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <math.h>
#include <vector>
using namespace std;

char Phone [8][3] = { {'A', 'B', 'C'}, {'D', 'E', 'F'},
                 {'G', 'H', 'I'}, {'J', 'K', 'L'},
                 {'M', 'N', 'O'}, {'P', 'R', 'S'},
                 {'T', 'U', 'V'}, {'W', 'X', 'Y'}};

int main()
{
  ifstream dict;
  dict.open("dict.txt");
  int N, length = 0;
  std::cin >> N;
  while(1.0*(N / pow(10, length)) >= 1)
  {
    length++;
  }
  int all[length]{}, where = 0, dec;
  char test[length];
  for(int i=0;i<length;i++)
  {
    int power = pow(10,length-i-1);
    test[i] = Phone[(N/power % 10)-2][0];
  }
  while(all[length-1] < 3)
  {
    where = 0;
    dec = N / pow(10, where);
    test[where] = Phone[dec][all[where]];

    all[where]++;
    //Try all options
    while(all[where] > 3)
    {
      all[where] = 0;
      where++;
      all[where]++;
    }
    //Find in file:
    /*std::cout << getline(dict, "GREG") << '\n';
    if(getline(dict, test) != -1)
    {
      std::cout << test << '\n';
    }*/
  }
  string tst;
  getline(dict, tst);
  std::cout << tst.find("GREG",0) << '\n';
  return 0;
}
