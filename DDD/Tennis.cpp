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
#include <queue>
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

void next_player(priority_queue< pair<int, int> > a, priority_queue< pair<int, int> > b)
{
  b.push(make_pair(a.top().first, a.top().second));
  a.pop();
}

void next_match(priority_queue< pair<int, int> > a, priority_queue< pair<int, int> > b)
{
  while(!b.empty())
  {
    a.push(make_pair(b.top().first, b.top().second));
    b.pop();
  }
}

int main()
{

  int temp = 0, i = 0;
  std::cin >> n;
  priority_queue< pair<int, int> > PlayersP;
  priority_queue< pair<int, int> > Mem;
  priority_queue< pair<int, int> > Mem2;
  pair<int, int> Players[n];
  while(cin >> temp)
  {
    PlayersP.push(make_pair(temp, i));
    Players[i] = make_pair(temp, i);
    i++;
  }
  vector< vector<int> > resultint(n, vector<int> (1));

  while(1)
  {
    std::cout << "den tester om den har vundet?" << '\n';
    if(PlayersP.top().first == 0)
    {
      cout << "SOLUTION" << '\n';
      for(int i=0; i<n; i++)
      {
        priority_queue< int, vector<int>, greater<int> > result_print;
        int o=1;
        for(int u=0; u<resultint[i][0]; u++)
        {
          result_print.push(resultint[i][o]);
          o++;
        }
        //print det ud
        while(!result_print.empty())
        {
          std::cout << result_print.top() << " ";
          result_print.pop();
        }
        std::cout << '\n';
      }
      return 0;
    }
    int player = PlayersP.top().second, how_many = PlayersP.top().first, played = 1;
    //Rykker førstepladsen til Mem
    Mem.push(make_pair(0, PlayersP.top().second));
    PlayersP.pop();
    //HERFRA NU*******************************************************

    for(int u=0; u<how_many; u++)
    {
      while(1)
      {
        std::cout << Mem.top().first << " og "<<Mem.top().second+1<< '\n';
        for(int i=0; i<PlayersP.size()+Mem2.size(); i++)
        {
          std::cout << PlayersP.top().first << " og "<<PlayersP.top().second+1<< '\n';
          Mem2.push(make_pair(PlayersP.top().first, PlayersP.top().second));
          PlayersP.pop();
        }
        while(!Mem2.empty())
        {
          PlayersP.push(make_pair(Mem2.top().first, Mem2.top().second));
          Mem2.pop();
        }
        std::cout << "U: " <<u<< '\n';
        if(PlayersP.empty() | PlayersP.top().first == 0)
        {
          std::cout << "NO SOLUTION" << '\n';
          //PRINT RESULT------
          for(int i=0; i<n; i++)
          {
            priority_queue< int, vector<int>, greater<int> > result_print;
            int o=1;
            for(int u=0; u<resultint[i][0]; u++)
            {
              result_print.push(resultint[i][o]);
              o++;
            }
            //print det ud
            while(!result_print.empty())
            {
              std::cout << result_print.top() << " ";
              result_print.pop();
            }
            std::cout << '\n';
          }
          //TO HERE-----------
          return 0;
        }
        else if(played > resultint[PlayersP.top().second][0])
        {
          //std::cout << "Nu gemmer den resultatet for " <<player+1<<" og "<<PlayersP.top().second+1<< '\n';
          resultint[player].push_back(PlayersP.top().second+1); //(tidligere) første tennisspiller får index på nr. 2
          resultint[PlayersP.top().second].push_back(player+1); //og omvendt
          //lægger 1 til hver af result[player][0]:
          resultint[player][0]++;
          resultint[PlayersP.top().second][0]++;
          //next match
          //std::cout << "Start over, det har lige været: " << player+1<<" mødte: "<<PlayersP.top().second+1<< '\n';
          //Skubber også denne over i den anden bunke før de alle kommer tilbage, for at reducere "first" med 1:
          std::cout <<"tester1: "<< PlayersP.top().first << " og "<<PlayersP.top().second+1<< '\n';
          Mem.push(make_pair(PlayersP.top().first-1, PlayersP.top().second));
          PlayersP.pop();
          played = 1;
          break;
        }
        else if(resultint[PlayersP.top().second][played] == player+1)
        {
          //next player
          std::cout <<"tester2: "<< PlayersP.top().first << " og "<<PlayersP.top().second+1<< '\n';
          Mem.push(make_pair(PlayersP.top().first, PlayersP.top().second));
          PlayersP.pop();
          played = 1;
        }
        else
        {
          std::cout << "Spil mod den næste: nu: " <<played<< '\n';
          played++;
        }
        for(int i=0; i<n; i++)
        {
          priority_queue< int, vector<int>, greater<int> > result_print;
          int o=1;
          for(int u=0; u<resultint[i][0]; u++)
          {
            result_print.push(resultint[i][o]);
            o++;
          }
          //print det ud
          while(!result_print.empty())
          {
            std::cout << result_print.top() << " ";
            result_print.pop();
          }
          std::cout << '\n';
        }
        std::cout << "Så nu ser den såden her ud ^^" << '\n';
      }
    }

    std::cout << "Den rykker alle tilbage nu" << '\n';
    //Rykker alle tilbage:
    while(!Mem.empty())
    {
      PlayersP.push(make_pair(Mem.top().first, Mem.top().second));
      Mem.pop();
    }
    //OG HERTIL*******************************************************
  }
  return 0;
}
