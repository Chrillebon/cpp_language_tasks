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

ifstream dict ("dict.txt");
ifstream fin ("namenum.in");
ofstream fout ("namenum.out");

struct Node
{
  vector<string> posname;
  Node *children[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};

void insert(Node * Parent, string name, int depth)
{
  int qcorrect = name[depth];
  if(qcorrect >= 81)
  {
    qcorrect--;
  }
  if(qcorrect >= 89)
  {
    //Skal ikke indsætte Z
    return;
  }
  int whereto = (qcorrect - 65) / 3;

  if(depth == name.size()-1)
  {
    if(Parent -> children[whereto] == NULL)
    {
      Parent -> children[whereto] = new Node;
    }
    Parent -> children[whereto] -> posname.push_back(name);
    return;
  }
  if(Parent -> children[whereto] == NULL)
  {
    Parent -> children[whereto] = new Node;
  }
  return insert(Parent -> children[whereto], name, depth + 1);
}

void printval(Node * Parent, int * name, int depth, int length)
{
  if(depth == length)
  {
    //Skriv alle navne
    if(Parent -> posname.size())
    {
      for(int i=0;i<Parent -> posname.size();i++)
      {
        fout << Parent -> posname[i] << '\n';
      }
    }
    else
    {
      fout << "NONE" << '\n';
    }
    return;
  }
  if(Parent -> children[name[depth]] == NULL)
  {
    fout << "NONE" << '\n';
    return;
  }
  //Eller bevæg dig ned ad næste
  return printval(Parent -> children[name[depth]], name, depth + 1, length);
}

int main()
{
  Node *root = new Node;
  string temp;
  while(dict >> temp)
  {
    insert(root, temp, 0);
  }
  dict.close();
  long long N, length = 0;
  fin >> N;
  while(1.0*(N / pow(10, length)) >= 1)
  {
    length++;
  }
  int number[length]{};
  for(int i=0;i<length;i++)
  {
    long long power = pow(10,(int)(length-1-i));
    if(power % 10 == 9)
    {
      power++;
    }
    number[i] = (N/power % 10)-2;
  }
  printval(root, number, 0, length);
  return 0;
}
