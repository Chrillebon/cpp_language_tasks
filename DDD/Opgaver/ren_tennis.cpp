#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;

int main()
{
  int temp = 0, i = 0;
  std::cin >> n;
  priority_queue< pair<int, int> > Players;
  priority_queue< pair<int, int> > Mem;
  while(cin >> temp)
  {
    Players.push(make_pair(temp, i));
    i++;
  }
  vector< vector<int> > result(n, vector<int> (1));

  while(1)
  {
    if(Players.top().first == 0)
    {
      cout << "SOLUTION" << '\n';
      for(int i=0; i<n; i++)
      {
        priority_queue< int, vector<int>, greater<int> > result_print;
        int o=1;
        for(int u=0; u<result[i][0]; u++)
        {
          result_print.push(result[i][o]);
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
    int player = Players.top().second, how_many = Players.top().first, played = 1;
    //Rykker førstepladsen til Mem og går igennem alle dens kampe først. Sætter derfor den til 0
    Mem.push(make_pair(0, Players.top().second));
    Players.pop();

    //Går igennem antallet af kampe som den tidligere første ville spille, før den går videre til den næste
    for(int u=0; u<how_many; u++)
    {
      //Bliver ved indtil den har fundet en kamp eller fundet ingen løsning.
      while(1)
      {
        if(Players.empty() | Players.top().first == 0)
        {
          std::cout << "NO SOLUTION" << '\n';
          return 0;
        }
        else if(played > result[Players.top().second][0])
        {
          result[player].push_back(Players.top().second+1); //(tidligere) første tennisspiller får index på nr. 2
          result[Players.top().second].push_back(player+1); //og omvendt
          //lægger 1 til hver af result[player][0]:
          result[player][0]++;
          result[Players.top().second][0]++;
          //next match
          //Skubber også denne over i den anden bunke før de alle kommer tilbage, for at reducere "first" med 1:
          Mem.push(make_pair(Players.top().first-1, Players.top().second));
          Players.pop();
          played = 1;
          break;
        }
        else if(result[Players.top().second][played] == player+1)
        {
          //next player
          Mem.push(make_pair(Players.top().first, Players.top().second));
          Players.pop();
          played = 1;
        }
        else
        {
          played++;
        }
      }
    }
    //Rykker alle tilbage:
    while(!Mem.empty())
    {
      Players.push(make_pair(Mem.top().first, Mem.top().second));
      Mem.pop();
    }
  }
  return 0;
}
