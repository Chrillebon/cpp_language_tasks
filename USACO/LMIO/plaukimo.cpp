#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> swim;
vector<int> dif;
int maxv = 1000000;
int N, A, B, temp;

void maxdif(int depth, int locmax)
{
  if(depth > swim.size()-A && depth != swim.size())
  {
    return;
  }
  else if(depth == swim.size())
  {
    maxv = min(locmax, maxv);
  }
  else
  {
    for(int i=A-1;i<B;i++)
    {
      maxdif(depth+i+1, max(swim[depth+i]-swim[depth],locmax));
    }
  }
}

int main()
{
  std::cin >> N >> A >> B;
  for(int i=0;i<N;i++)
  {
    std::cin >> temp;
    swim.push_back(temp);
  }
  sort(swim.begin(), swim.end());
  for(int i=0;i<N-1;i++)
  {
    dif.push_back(swim[i+1]-swim[i]);
  }
  maxdif(0,0);
  std::cout << maxv << '\n';

  return 0;
}
