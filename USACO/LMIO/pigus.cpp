#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool comp(int a, int b)
{
  return a > b;
}

int main()
{
  int n,m;
  cin>>n>>m;
  int profits[n][n];
  int cities[n];

  vector<vector<int> > routes;
  //init list;
  for(int i = 0; i < n; i++)
  {
    routes.push_back({});
  }
  int a,b,v;
  for(int i = 0; i < m; i++)
  {
    cin>>a>>b>>v;
    cities[a] += v;
    routes[a].push_back(b);
    profits[a][b] = v;
    cities[b] += v;
    routes[b].push_back(a);
    profits[b][a] = v;
  }

  cout<<"a";
  sort(cities, cities + n, comp);
  int maxv = cities[0];
  cout<<"b";
  for(int i = 0; i < n; i++) //for alle elementer
  {
    cout<<"x";
    for(int j = 0; j < routes[i].size(); j++) //for alle dens router
    {
      cout<<"d";
      for(int h = 0; h < routes[routes[i][j]].size(); h++) //for alle dens router
      {
        cout<<"m";
        vector<int>::iterator it = find(routes[i].begin(), routes[i].end(), routes[j][h]);
        cout<<"test";
        if(it != routes[i].end())
        {
          int idx = it - routes[i].begin();
          int one = routes[j][h];
          int two = i;
          int three = routes[i][routes[j][h]];

          int profit = profits[one][two] + profits[one][three] + profits[two][three];

          maxv = max(profit, maxv);
          }
      }
    }
  }

  cout<<maxv;
}
