/*
strategi:
1. tag størst (hvis flere: først)
2. spil mod størst (ikke sig selv)
3. gentag

kodemæssigt:

1. Fortsæt kun hvis sum er lige
2. Find de 2 personer med flest kampe (hvis flere så de første)
3. De stiller op imod hinanden:
  - gem opgøret i output
  - træk 1 fra begge personerne
4. gentag fra "2." indtil alle personer har spillet hvad de skal
5. udskriv output
*/

/*
5
3 234
3 134
3 125
2 12
1 3

5
3 234
3 134
2 12
3 125
1 4

hver spiller:
index
antal kampe

resultat: hvem han spiller mod
*/

#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <string.h>
#include <vector>
using namespace std;

int n;

void insertionsort(pair<int, int> a[], int where)
{
  int whereto = where+1;
  pair<int, int> temp(a[where].first, a[where].second);
  while(1)
  {
    if(temp.first >= a[whereto].first | whereto == n-1)
    {
      break;

    }
    a[whereto-1] = make_pair(a[whereto].first, a[whereto].second);
    whereto++;
  }
  a[whereto-1] = make_pair(a[whereto].first, a[whereto].second);
  a[whereto] = make_pair(temp.first, temp.second);
}

int main()
{

  int temp = 0, i = 0;
  std::cin >> n;
  pair<int, int> Players[n];
  while(cin >> temp)
  {
    Players[i] = make_pair(temp, i);
    i++;
  }
  sort(&Players[0], &Players[n]);
  reverse(&Players[0], &Players[n]);
  string result[n];
  vector< vector<int> > resultint(n, vector<int> (1));

  int s=1, t=1;

  while(1)
  {
    while(1)
    {

      if(resultint[Players[s].second][t] == '\0' | resultint[Players[s].second][t] > n | resultint[Players[s].second][t] < 0) //den har ikke mødt denne spiller før
      {
        break;
      }
      else if(Players[0].second+1 == resultint[Players[s].second][t]) //han har mødt denne spiller før
      {
        s++;
        t=1;
      }
      else if(s>=n | Players[s].first == 0) //der er ikke flere spillere der vil spille flere kampe
      {
        cout << "NO SOLUTION" << '\n';
        return 0;
      }
      else //Han har ikke mødt denne ene spiller, så vi tester lige resten
      {
        t++;
      }
    }
    resultint[Players[0].second].push_back(Players[s].second+1);
    resultint[Players[s].second].push_back(Players[0].second+1);

    Players[0].first--;
    Players[s].first--;
    insertionsort(Players, s);
    insertionsort(Players, 0);
    s=1;
    t=1;
    int done=0;
    for(int i=0; i<n; i++)
    {
      done+=Players[i].first;
    }
    if(done == 1)
    {
      cout << "NO SOLUTION" << '\n';
      return 0;
    }
    else if(done == 0)
    {
      cout << "SOLUTION" << '\n';
      for(int i=0; i<n; i++)
      {
        int o=1;
        while(resultint[i][o] != '\0' & resultint[i][o]<=n & resultint[i][o] > 0)
        {
          std::cout << resultint[i][o] << " ";
          o++;
        }
        std::cout << '\n';
      }
      return 0;
    }
    //ellers er det om igen...
  }

  return 0;
}
