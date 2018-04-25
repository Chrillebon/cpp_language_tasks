#include <iostream>
#include <queue>

struct comp1
{
  bool operator()(int a, int b) { return a < b; }
};

struct comp2
{
  bool operator()(int a, int b) { return a > b; }
};

std::priority_queue<int, std::vector<int>, comp1> left;
std::priority_queue<int, std::vector<int>, comp2> right;
int n;


int main()
{
  std::cout.precision(100);
  std::cin >> n;
  int temp;
  for(int i=0;i<n;i++)
  {
    std::cin >> temp;
    //Indsætter i venstre:
    left.push(temp);
    if(left.size() == right.size()+2 || (right.empty() && left.size() == 2))
    {
      right.push(left.top());
      left.pop();
      std::cout << (left.top()+right.top())/2.0<< '\n';
    }
    else
    {
      if(!right.empty() && left.top() > right.top())
      {
        temp = right.top();
        right.pop();
        right.push(left.top());
        left.pop();
        left.push(temp);
      }
      std::cout << left.top() << '\n';
    }
  }
  return 0;
}
