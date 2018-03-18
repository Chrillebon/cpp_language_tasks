/*
ID: Christi69
PROB: milk2
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
using namespace std;

struct PointerComparator {
  bool operator() (vector<int> arg1, vector<int> arg2) {
    return arg1[0] > arg2[0]; //calls your operator
  }
};

int longest(priority_queue<vector<int>, vector< vector<int> >, PointerComparator> farmers)
{
  int start = farmers.top()[0];
  int end = farmers.top()[1];
  int longest = 0;
  farmers.pop();
  while(farmers.size())
  {
    if(farmers.top()[0] <= end)
    {
      if(farmers.top()[1] > end)
      {
        end = farmers.top()[1];
      }
      farmers.pop();
    }
    else
    {
      if(end-start > longest)
      {
        longest = end-start;
      }
      start = farmers.top()[0];
      end = farmers.top()[1];
      farmers.pop();
    }
  }
  if(end-start > longest)
  {
    return end-start;
  }
  else
  {
    return longest;
  }
  return longest;
}

int draught(priority_queue<vector<int>, vector< vector<int> >, PointerComparator> farmers)
{
  int end = farmers.top()[1];
  int largest = 0;
  farmers.pop();
  while(farmers.size())
  {
    if(farmers.top()[0] <= end)
    {
      if(farmers.top()[1] > end)
      {
        end = farmers.top()[1];
      }
      farmers.pop();
    }
    else
    {
      if(farmers.top()[0]-end > largest)
      {
        largest = farmers.top()[0]-end;
      }
      end = farmers.top()[1];
      farmers.pop();
    }
  }
  return largest;
}

int main()
{
  ifstream fin ("milk2.in");
  ofstream fout ("milk2.out");
  int n;
  fin >> n;
  priority_queue<vector<int>, vector< vector<int> >, PointerComparator> farmersfeast;
  priority_queue<vector<int>, vector< vector<int> >, PointerComparator> farmersdraught;
  vector<int> temp(2);
  for(int i=0;i<n;i++)
  {
    fin >> temp[0] >> temp[1];
    farmersfeast.push(temp);
    farmersdraught.push(temp);
  }
  fout << longest(farmersfeast) << " " << draught(farmersdraught) << '\n';
  return 0;
}
