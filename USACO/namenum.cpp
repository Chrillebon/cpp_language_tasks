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

struct Node
{
  vector<string> posname;
  Node *children[8] = {NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL};
};

void insert(Node * Parent, string name, int depth)
{
  if(depth == name.size())
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
  std::cout << "how goes: " <<name[depth]<< '\n';
  if(depth == length - 1)
  {
    std::cout << "the end" << '\n';
    //Skriv alle navne
    for(int i=0;i<Parent -> posname.size()-1;i++)
    {
      cout << Parent -> posname[i] << " ";
    }
    cout << Parent -> posname[Parent -> posname.size() - 1];
    return;
  }
  //Eller bevæg dig ned ad næste
  return printval(Parent -> children[name[depth]], name, depth + 1, length);
}

int main()
{
  ifstream dict ("dict.in");
  ifstream fin ("namenum.in");
  ofstream fout ("namenum.out");
  Node *root = new Node;
  string temp;
  while(dict >> temp)
  {
    std::cout << temp << '\n';
    insert(root, temp, 0);
  }
  int N, length = 0;
  cin >> N;
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
  printval(root, number, 0, length);
  return 0;
}
