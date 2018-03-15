#include <iostream>
using namespace std;

class Tree
{
public:
  void add(char*, int, int);
  int search();
  int bestval;
  Tree *minus;
  Tree *zero;
  Tree *plus;
};

void Tree::add(char* slide, int index, int val)
{
  if(slide[index] == '\0')
  {
    return;
  }
  bestval = val;
  Tree child;
  if(slide[index] == '-')
  {
    if(minus.bestval != NULL)
    {
      minus = child;
    }
    else
    {
      child = minus;
    }
  }
  if(slide[index] == '0')
  {
    if(zero.bestval != NULL)
    {
      zero = child;
    }
    else
    {
      child = zero;
    }
  }
  if(slide[index] == '+')
  {
    if(plus.bestval != NULL)
    {
      plus = child;
    }
    else
    {
      child = plus;
    }
  }
  child.add(slide, index+1, val);
}

int main()
{
  return 0;
}
