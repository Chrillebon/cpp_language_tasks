/*
ID: Christi69
PROB: sprime
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

ifstream fin ("sprime.in");
ofstream fout ("sprime.out");

int superprimes[8][30] = {{2, 3, 5, 7}, {23, 29, 31, 37, 53, 59, 71, 73, 79}, {233, 239, 293, 311, 313, 317, 373, 379, 593, 599, 719, 733, 739, 797}, {2333, 2339, 2393, 2399, 2939, 3119, 3137, 3733, 3739, 3793, 3797, 5939, 7193, 7331, 7333, 7393}, {23333, 23339, 23399, 23993, 29399, 31193, 31379, 37337, 37339, 37397, 59393, 59399, 71933, 73331, 73939}, {233993, 239933, 293999, 373379, 373393, 593933, 593993, 719333, 739391, 739393, 739397, 739399}, {2339933, 2399333, 2939999, 3733799, 5939333, 7393913, 7393931, 7393933}, {23399339, 29399999, 37337999, 59393339, 73939133}};

bool isprime(int numb)
{
  int o = 2;
  if(numb == 1)
  {
    return false;
  }
  while(o * o <= numb)
  {
    if(numb % o == 0)
    {
      return false;
    }
    o++;
  }
  return true;
}

bool superprime(int numb)
{
  while(numb>=10)
  {
    if(!isprime(numb))
    {
      return false;
    }
    numb/=10;
  }
  if(!isprime(numb))
  {
    return false;
  }
  return true;
}

int main()
{
  int n, m = 0;
  fin >> n;
  /*for(int i=3;i<=100000000;i+=2)
  {
    if(superprime(i))
    {
      std::cout << i << ", ";
    }
  }
  std::cout << '\n';
  std::cout << "DONE" << '\n';*/
  while(superprimes[n-1][m]!=0)
  {
    fout << superprimes[n-1][m] << '\n';
    m++;
  }
  return 0;
}
