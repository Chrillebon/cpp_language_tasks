#include <iostream>
#include <vector>
using namespace std;

vector<int> contenders;
int result = 0;

struct Node
{
  int bestval;
  Node *left = NULL;
  Node *right = NULL;
  int insert(int);
};

int insert(int val, Node *parent)
{
  for(int i=0;i<contenders.size();i++)
  {
    if(val + contenders[i] == 0)
    {
      result = val;
      return 1;
    }
  }
  if(parent -> bestval < val)
  {
    if(parent -> right == NULL)
    {
      parent -> right = new Node;
      parent -> right -> bestval = val;
      contenders.push_back(val);
      return 0;
    }
    else
    {
      return insert(val, parent -> right);
    }
  }
  else
  {
    if(parent -> left == NULL)
    {
      parent -> left = new Node;
      parent -> left -> bestval = val;
      contenders.push_back(val);
      return 0;
    }
    else
    {
      return insert(val, parent -> left);
    }
  }
}

int main()
{
  int n;
  std::cin >> n;
  int val, res;
  Node *root;
  root = new Node;
  std::cin >> val;
  root->bestval=val;

  for(int i=0;i<n-1;i++)
  {
    std::cin >> val;
    if(insert(val, root))
    {
      std::cout << abs(result)*(-1) <<" "<<abs(result)<< '\n';
      return 0;
    }
  }
  std::cout << "NO" << '\n';
  return 0;
}
