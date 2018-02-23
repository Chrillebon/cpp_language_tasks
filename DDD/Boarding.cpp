#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque < deque < vector < int > > > Passengers;
long long BT = 0;
int group = 0, ekstra = 0;

void add()
{
  int pos, t;
  std::cin >> pos >> t;
  if(Passengers.size() > group) //Næste gruppe er ikke tom
  {
    if(pos < Passengers[group].back()[0])//Han skal ind før ham der står op
    {
      for(int i=1; i<=group; i++)
      {
        if(pos < Passengers[group-1].back()[0]) //Han skal også ind før ham der er i næste gruppe
        {
          ekstra += t; //Hvis man springer over bliver man til et spøgelse
          return;
        }/*
        if(!(pos < Passengers[group-i].back()[0]) )
        {
          Passengers[group-i+1].push_back({pos, t});
          return;
        }*/
      }
      Passengers[group].push_back({pos, t}); //Ellers er man stadig menneske
    }
    else
    {
      group++;
      Passengers.resize(group+1);
      Passengers[group].push_back({pos, t});
    }
  }
  else //Næste gruppe er tom
  {
    Passengers.resize(group+1);
    Passengers[group].push_back({pos, t});
  }
}

int main()
{
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++)
  {
    add();
  }
  //------LOGIK-------
  while(1)
  {
    int PT = Passengers[0].back()[1];
    BT += PT; //Lægger deres tid til boarding tiden
    ekstra -= PT;
    Passengers[0].pop_back();
    if(!Passengers[0].empty())
    {
      for(int i=0; i<Passengers[0].size(); i++)
      {
        Passengers[0][i][1] -= PT;
        if(Passengers[0][i][1] <= 0) // Må ikke komme under 0
        {
          Passengers[0].erase(Passengers[0].begin()+i); //fjerne i'ende person
          i--; //Den skal ikke springe personer over
        }
      }
    }
    if(Passengers[0].empty())
    {
      Passengers.pop_front();
    }
    else
    {
      while(1) //Checker, om der nu kan komme flere ind i gruppen
      {
        if(!Passengers[0+1].empty())
        {
          if(Passengers[0+1].front()[0] < Passengers[0].back()[0]) // De kan pakke samtidigt, hele den næste gruppe
          {
            Passengers[0].push_back({Passengers[0+1].front()[0], Passengers[0+1].front()[1]}); //De rykker deque
            Passengers[0+1].pop_front(); //Fjerner dem fra anden deque
          }
          else
          {
            break;
          }
        }
        else if(Passengers.size() > 1)// Hvis man tømmer gruppen ved at rykke den
        {
          Passengers.erase(Passengers.begin()+1); //remove 2'nd deque
          break;
        }
        else// Hvis man tømmer den sidste anden gruppe ved at rykke den
        {
          break;
        }
      }
    }
    if(Passengers.size() <= 0)
    {
      break;
    }
  }
  //-----LOGIK-----
  std::cout << BT << '\n'; //resultat
  return 0;
}
