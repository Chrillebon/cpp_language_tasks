#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> fridge;
vector<int> sorted;
vector<int> result;

bool myfunction(int a, int b)
{
  return (fridge[a]<fridge[b]);
}

int n,m,s,d; //new bottles , students , slots , space

int main()
{
  std::cin >> n >> m >> s >> d;
  fridge.resize(s);
  sorted.resize(s);
  result.resize(s);
  for(int i=0;i<s;i++) //indexer alle pladser
  {
    sorted[i] = i;
  }
  for(int i=0;i<s;i++)
  {
    std::cin >> fridge[i];
  }
  sort(sorted.begin(),sorted.end(), myfunction);//sorted giver id på mindste index af pladser
  int space=0, filled = 0;
  while(filled < n)
  {
    filled += d-fridge[sorted[space]];
    result[sorted[space]] = d-fridge[sorted[space]];
    space++;
  }
  result[sorted[space-1]] -= (filled - n); // trækker overindlæg fra
  int lucky=0; //how many students are lucky
  for(;space<s;space++)
  {
    lucky += fridge[sorted[space]];
  }
  if(lucky < m)
  {
    std::cout << "impossible" << '\n';
  }
  else
  {
    for(int i=0;i<s;i++)
    {
      std::cout << result[i] << '\n';
    }
  }
  return 0;
}
