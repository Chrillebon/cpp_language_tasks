/*
ID: Christi69
PROB: numtri
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

//ifstream fin ("numtri.in");
//ofstream fout ("numtri.out");

int n, i, d, maxval, result, numb[500500], sum[500500]{};

void move()
{
  //std::cerr << "@ " <<numb[i]<<" med "<<sum[i]<< '\n';
  if(d==n)
  {
    return;
  }
  if(sum[i]+numb[i+d]>sum[i+d])
  {
    sum[i+d]=sum[i]+numb[i+d];
  }
  if(sum[i]+numb[i+d+1]>sum[i+d+1])
  {
    sum[i+d+1]=sum[i]+numb[i+d+1];
  }
  result = max(result, max(sum[i+d+1],sum[i+d]));
  if(i>=maxval-2)
  {
    d+=1; //Vi skal et lag dybere
    i++;
    maxval = ceil((d+1)*(1.0*d/2));
    move();
  }
  else
  {
    i++;
    move();
  }
}

int main()
{
  cin >> n;
  maxval = ceil((n+1)*(1.0*n/2));
  for(int o=0;o<maxval;o++)
  {
    cin >> numb[o];
  }
  maxval=0;
  result=numb[0]; //Hvis den kun er 1 dyb
  sum[0]=numb[0]; //Starter på 0
  d=1;
  move();
  std::cout << result << '\n';
}

/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5
*/
