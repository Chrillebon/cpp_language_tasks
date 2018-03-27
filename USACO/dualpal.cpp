/*
ID: Christi69
PROB: dualpal
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin ("dualpal.in");
ofstream fout ("dualpal.out");

int basen [20] = {0}, psize = 0;
char bvalc[20] = {0};

int power(int val, int base)
{
  double dval = val;
  double result = ceil(pow(dval, base));
  return (int)(result);
}

char * itoc(int * value)
{
  int i = 19, rzero = 1;
  while(value[i] == 0 && i>=0)
  {
    i--;
  }
  psize = i+1;
  fill(bvalc, bvalc+19, 0);
  while(i>=0)
  {
    char temp = value[i];
    bvalc[psize-i-1] = temp;
    i--;
  }
  return bvalc;
}

int * con(int tenval, int base)
{
  int baseten[6], length = 0, index = 0;
  while((int)(tenval/power(10,length)))
  {
    baseten[length] = (int)(tenval/power(10,length)) % 10;
    length++;
  }
  int addval = 0;
  fill(basen, basen+19,0);
  for(int i=0;i<length;i++)
  {
    index = 0;
    addval = baseten[i]*power(10,i);
    while(addval)
    {
      basen[index] += addval;
      addval = basen[index] / base;
      basen[index] %= base;
      index++;
      if(index >= 20)
      {
        return basen;
      }
    }
  }
  return basen;
}

bool sq(int tenval, int base)
{
  char * arr = itoc(con(tenval, base));
  for(int i=0;i<psize/2;i++)
  {
    if(arr[i] != arr[psize-1-i])
    {
      return 0;
    }
  }
  return 1;
}

int main()
{
  int N, S;
  fin >> N >> S;
  while(N)
  {
    int a = 0;
    S++;
    for(int i=2;i<=10;i++)
    {
      if(sq(S, i) && a < 2)
      {
        a++;
      }
    }
    if(a >= 2)
    {
      fout << S << '\n';
      N--;
    }
  }
  return 0;
}
