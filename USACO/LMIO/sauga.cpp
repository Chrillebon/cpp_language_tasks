#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(vector<int> a, vector<int> b)
{
  return a[0]>b[0];
}

int main()
{
  int T, N, S, temp1, temp2;
  std::cin >> T >> N >> S;
  vector< vector<int> > results;
  for(int i=0;i<N;i++)
  {
    std::cin >> temp1;
    vector<int> tarr;
    tarr.push_back(temp1);
    tarr.push_back(i);
    for(int j=2;j<temp1+2;j++)
    {
      std::cin >> temp2;
      tarr.push_back(temp2);
    }
    results.push_back(tarr);
  }
  sort(results.begin(), results.end(), comp);
  int idx = results.size()-1;
  while(results[idx][0] == 0)
  {
    std::cout << results[idx][1]+1 << '\n';
    idx--;
  }
  idx = 0;
  while(results[idx][0] > 1 && idx < results.size())
  {
    std::cout << results[idx][1]+1 << '\n';
    results[idx][0] = 0;
    idx++;
  }
  int start = idx;
  vector<int> oneleft;
  int aleft = 0;
  while(results[idx][0] != 0)
  {
    oneleft.push_back(results[idx][1]);
    aleft++;
    idx++;
  }
  int end = idx - 1;
  int done1run = 0;
  while(aleft)
  {
    idx = start;
    done1run = 0;
    if(!(idx > end))
    {
      for(int i=0;i<results[idx][0];i++) //for alle den peger på
      {
        for(int o=0;o<oneleft.size();o++) //for alle i oneleft
        {
          if(results[idx][i+2] == oneleft[o]) //Hvis de er ens
          {
            std::cout << results[idx][1]+1 << '\n';
            results[idx][0] = 0;
            oneleft[o] = -1;
            aleft--;
            done1run++;
            break;
          }
        }
      }
    }
    if(done1run == 0)
    {
      std::cout << results[idx][1]+1 << '\n';
      for(int o=0;o<oneleft.size();o++) //for alle i oneleft
      {
        if(results[idx][1] == oneleft[o]) //Hvis de er ens
        {
          oneleft[o] = -1;
          aleft--;
          done1run++;
          break;
        }
      }
      start++;
    }
  }
  return 0;
}
