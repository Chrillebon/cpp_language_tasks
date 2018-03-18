/*
ID: Christi69
PROB: transform
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

int N;

int test90(vector< vector<int> > Start, vector< vector<int> > Goal)
{
  /*
  0 0 -> 3 0
  0 3 -> 0 0
  1 0 -> 3 1
  2 2 -> 1 2

  x y -> N-y x
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[N-i-1][o])
      {
        return 0;
      }
    }
  }
  return 1;
}

int test180(vector< vector<int> > Start, vector< vector<int> > Goal)
{
  /*
  0 0 -> 3 3
  0 3 -> 3 0
  1 0 -> 2 3
  2 2 -> 1 2

  x y -> N-x N-y
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[N-o-1][N-i-1])
      {
        return 0;
      }
    }
  }
  return 2;
}

int test270(vector< vector<int> > Start, vector< vector<int> > Goal)
{
  /*
  0 0 -> 0 3
  0 3 -> 0 0
  1 0 -> 0 2
  2 2 -> 2 1

  x y -> y N-x
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[i][N-o-1])
      {
        return 0;
      }
    }
  }
  return 3;
}

int testequal(vector< vector<int> > Start, vector< vector<int> > Goal)
{
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[o][i])
      {
        return 0;
      }
    }
  }
  return 6;
}

int main()
{
  ifstream fin ("transform.in");
  ofstream fout ("transform.out");
  fin >> N;
  vector< vector<int> > Board1(N, vector<int> (N) );
  vector< vector<int> > Board2(N, vector<int> (N) );
  //Første mønster
  char as;
  int df;
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      fin >> as;
      df=as;
      Board1[o][i] = df;
    }
  }
  //Andet mønster
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      fin >> as;
      df=as;
      Board2[o][i] = df;
    }
  }
  //begynder test:
  if(test90(Board1, Board2))
  {
    fout << 1 << '\n';
    return 0;
  }
  if(test180(Board1, Board2))
  {
    fout << 2 << '\n';
    return 0;
  }
  if(test270(Board1, Board2))
  {
    fout << 3 << '\n';
    return 0;
  }
  if(testequal(Board1, Board2))
  {
    fout << 6 << '\n';
    return 0;
  }
  //Hvis ikke, så er der måske spejlet:
  //Laver ny plade der er spejlet:
  vector< vector<int> > Board3(N, vector<int> (N) );
  //Første mønster
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      Board3[o][i] = Board1[N-o-1][i];
    }
  }
  //Så tester jeg videre
  if(testequal(Board3, Board2))
  {
    fout << 4 << '\n';
    return 0;
  }
  if(test90(Board3, Board2))
  {
    fout << 5 << '\n';
    return 0;
  }
  if(test180(Board3, Board2))
  {
    fout << 5 << '\n';
    return 0;
  }
  if(test270(Board3, Board2))
  {
    fout << 5 << '\n';
    return 0;
  }
  //Hvis ikke, så har det været en ulovlig transformation!
  fout << 7 << '\n';
  return 0;
}
