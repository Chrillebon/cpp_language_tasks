/*
ID: Christi69
PROB: palsquare
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

ifstream fin ("palsquare.in");
ofstream fout ("palsquare.out");

int basen [20] = {0}, psize = 0;
char bvalc[20] = {0};

int power(int val, int base)
{
  double dval = val;
  double result = ceil(pow(dval, base));
  return (int)(result);
}

struct base
{
  //int converter(int);
  int squarer(int);
  int tenval;
  int baseval; //skal være chararray pga A, B...
  int square;
};

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

char * sqcon(int tenval, int base)
{
  int sqtenval = power(tenval, 2);
  fill(basen, basen+19, 0);
  int * bvali = con(sqtenval, base);
  return itoc(bvali);
}

bool sq(int tenval, int base)
{
  char * arr = sqcon(tenval, base);
  for(int i=0;i<psize/2;i++)
  {
    if(arr[i] != arr[psize-1-i])
    {
      return 0;
    }
  }
  return 1;
}

void print(char * arr)
{
  for(int i=0;i<psize;i++)
  {
    if(arr[i] > 9)
    {
        fout << (char)(arr[i]+55);
    }
    else
    {
      fout << (char)(arr[i]+48);
    }
  }
}

int btoten(int bbval[], int b)
{
  int endval = 0;
  psize = 0;
  for(int i=0;i<10;i++)
  {
    if(bbval[9-i] && !psize)
    {
      psize = i+1;
    }
    endval += bbval[9-i]*power(b,9-i);
  }
  return endval;
}

int main()
{
  int B, numb = 1;
  fin >> B;
  while(numb <= 300)
  {
    if(sq(numb, B) == 1)
    {
      print(itoc(con(numb, B)));
      fout << " ";
      print(sqcon(numb, B));
      fout << '\n';
    }
    numb++;
  }
  return 0;
}
