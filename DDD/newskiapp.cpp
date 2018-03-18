#include <iostream>
using namespace std;

struct node
{
  int bestval;
  node *minus;
  node *zero;
  node *plus;
};

class Tree
{
public:
  Tree();
  void insert(char*, int, int);
private:
  node *child;
};

Tree::Tree()
{
  child = NULL;
}

void Tree::insert(char* slope, int index, int val)
{
  if(slope[index] == '\0')
  {
    return;
  }
  if(slope[index] == '-')
  {
    if(Parent -> minus == NULL)
    {
      Parent -> minus = new node;
      child = Parent -> minus;
    }
    else
    {
      child = Parent -> minus;
    }
  }
  if(slope[index] == '0')
  {
    if(Parent -> zero == NULL)
    {
      Parent -> zero = new node;
      child = Parent -> zero;
    }
    else
    {
      child = Parent -> zero;
    }
  }
  if(slope[index] == '+')
  {
    std::cout << Parent -> plus << '\n';
    if(Parent -> plus == NULL)
    {
      std::cout << "test1" << '\n';
      Parent -> plus = new node;
      child = Parent -> plus;
    }
    else
    {
      std::cout << "test2" << '\n';
      child = Parent -> plus;
    }
  }
  child -> bestval = val;
  insert(slope, index+1, val);
}

int main()
{
  char test[] = {'+', '-', '-', '+', '+'};
  struct Tree asdf;
  asdf.insert(test, 0, 2);
  std::cout << "test" << '\n';
  return 0;
}
