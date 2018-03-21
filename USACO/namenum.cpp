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

//ifstream dict ("dict.txt");
ifstream fin ("namenum.in");
ofstream fout ("namenum.out");


struct Node
{
  vector<string> posname;
  Node *children[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};



void insert(Node * Parent, string name, int depth)
{
  if(depth == name.size()-1)
  {
    Parent -> posname.push_back(name);
    return;
  }
  int qcorrect = name[depth];
  if(qcorrect >= 81)
  {
    qcorrect--;
  }
  int whereto = (qcorrect - 65) / 3;
  if(Parent -> children[whereto] == NULL)
  {
    Parent -> children[whereto] = new Node;
  }
  return insert(Parent -> children[whereto], name, depth + 1);
}

void printval(Node * Parent, int * name, int depth, int length)
{
  if(depth == length - 1)
  {
    //Skriv alle navne
    for(int i=0;i<Parent -> posname.size()-1;i++)
    {
      fout << Parent -> posname[i] << " ";
    }
    fout << Parent -> posname[Parent -> posname.size() - 1];
    return;
  }
  //Eller bevæg dig ned ad næste
  return printval(Parent -> children[name[depth]], name, depth + 1, length);
}

int main()
{
  Node *root = new Node;
  insert(root, "GREG", 0);
  int asdf[] = {4, 7, 3, 1};
  printval(root, asdf, 0, 4);
  /*

  string temp;
  while(fin >> temp)
  {
    insert(root, temp, 0);
  }
  int N, length = 0;
  fin >> N;
  while(1.0*(N / pow(10, length)) >= 1)
  {
    length++;
  }
  int number[length]{};
  for(int i=0;i<length;i++)
  {
    int power = pow(10,length-1-i);
    number[i] = (N/power % 10)-2;
  }
  printval(root, number, 0, length);*/
  return 0;
}
