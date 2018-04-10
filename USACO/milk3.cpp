/*
ID: Christi69
PROB: milk3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

ifstream fin ("milk3.in");
ofstream fout ("milk3.out");

int A,B,C;
vector<int> result;

int uniq(int numb)
{
  for(int i=0;i<result.size();i++)
  {
    if(numb == result[i])
    {
      return 0;
    }
  }
  return 1;
}

void rec(int depth, int X, int Y, int Z)
{
  if(depth == 15) //8 lag før jeg løber tør for tid
  {
    return;
  }
  if(X == 0)
  {
    if(uniq(Z))
    {
      result.push_back(Z);
    }
  }
  if(Z > 0) //Der er mere i Z og mere plads i X eller Y
  {
    if(X != A) //Der er mere plads i A
    {
      if(X+Z > A) //Hvis der ikke er plads til alt
      {
        rec(depth+1, A, Y, Z+X-A);
      }
      else
      {
        rec(depth+1, X+Z, Y, 0);
      }
    }
    if(Y != B)
    {
      if(Y+Z > B) //Hvis der ikke er plads
      {
        rec(depth+1, X, B, Z+Y-B);
      }
      else
      {
        rec(depth+1, X, Y+Z, 0);
      }
    }
  }
  if(Y > 0) //Der er mere i Y og mere plads i X eller Z
  {
    if(X != A) //Der er mere plads i A
    {
      if(X+Y > A) //Hvis der ikke er plads til alt
      {
        rec(depth+1, A, Y+X-A, Z);
      }
      else
      {
        rec(depth+1, X+Y, 0, Z);
      }
    }
    if(Z != C)
    {
      if(Z+Y > C) //Hvis der ikke er plads
      {
        rec(depth+1, X, Y+Z-C, C);
      }
      else
      {
        rec(depth+1, X, 0, Z+Y);
      }
    }
  }
  if(X > 0) //Der er mere i X og mere plads i Y eller Z
  {
    if(Y != B) //Der er mere plads i B
    {
      if(Y+X > B) //Hvis der ikke er plads til alt
      {
        rec(depth+1, X+Y-B, B, Z);
      }
      else
      {
        rec(depth+1, 0, X+Y, Z);
      }
    }
    if(Z != C)
    {
      if(Z+X > C) //Hvis der ikke er plads
      {
        rec(depth+1, X+Z-C, Y, C);
      }
      else
      {
        rec(depth+1, 0, Y, Z+X);
      }
    }
  }
}

int main()
{
  fin >> A >> B >> C;
  rec(0,0,0,C);
  sort(result.begin(),result.end());
  for(int i=0;i<result.size();i++)
  {
    fout << result[i];
    if(i != result.size()-1)
    {
      fout << " ";
    }
  }
  fout << '\n';
  return 0;
}
