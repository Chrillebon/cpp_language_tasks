/*
ID: Christi69
PROB: crypt1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <vector>
using namespace std;

ifstream fin ("crypt1.in");
ofstream fout ("crypt1.out");

vector<int> digits;

int power(int val, int p)
{
  double r = 0;
  r = ceil(pow(val, p));
  return (int)(r);
}

int containes(int val)
{
  int i = 0, r=1, z = 0;
  while(val / power(10,i) > 0 || val == 0)
  {
    if(val / power(10,i) % 10 == 0)
    {
      return 0;
    }
    i++;
  }
  i=0;
  while(val / power(10,i))
  {
    r=0;
    for(int o=0;o<digits.size();o++)
    {
      if(val / power(10,i) % 10 != 0 && val / power(10,i) % 10 == digits[o])
      {
        r=1;
        i++;
        continue;
      }
    }
    if(!r)
    {
      return 0;
    }
  }
  return 1;
}

int length(int val)
{
  int l=1, i=1;
  while(val / power(10,i) > 0)
  {
    l++;
    i++;
  }
  return l;
}

int main()
{
  int N, temp, result = 0;
  fin >> N;
  for(int i=0;i<N;i++)
  {
    fin >> temp;
    digits.push_back(temp);
  }
  for(int a=111;a<1000;a++)
  {
    if(containes(a))
    {
      for(int b=11;b<100;b++)
      {
        if(containes(b))
        {
          if(containes(a*b))
          {
            if(containes(a*(b % 10)) && length(a*(b % 10)) == 3)
            {
              if(containes(a*(b / 10)) && length(a*(b / 10)) == 3)
              {
                result++;
              }
            }
          }
        }
      }
    }
  }
  fout << result << '\n';
  return 0;
}
