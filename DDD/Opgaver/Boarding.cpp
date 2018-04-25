#include <iostream>
#include <vector>
#include <deque>
using namespace std;

deque < deque < vector < int > > > Passengers;
vector< vector <int> > Ghosts (1);
int What_ghost = 1;
long long BT = 0;
int group = 0, ekstra = 0;

void add()
{
  int pos, t;
  std::cin >> pos >> t;
  //std::cout << pos << " og "<< t<<'\n';
  if(Passengers.size() > group) //Næste gruppe er ikke tom
  {
    if(pos < Passengers[group].back()[0])//Han skal ind før ham der står op
    {
      //std::cout << "a" << '\n';
      for(int i=1; i<=group; i++)
      {
        //std::cout << "0000" << '\n';
        if(!(pos < Passengers[group-i].back()[0]) | (i == group & pos < Passengers[group-i].back()[0])) //Han rykker ind i en gruppe længere fremme, foran den gruppe som han ikke kan komme foran, eller han kan være på forreste
        {
          //std::cout << "tester: " <<Passengers[group-i].back()[0]<< '\n';
          if(i!=1 & i != group) //Hvis i=1, så skal den ikke køre det, med mindre det er sidste
          {
            //std::cout << "Den tilføger et spøgelse: " <<What_ghost<<" med tiden "<<t<< '\n';
            Passengers[group-i+1].push_front({pos, -What_ghost});
            Passengers[group].push_back({pos, -What_ghost}); //Tilføger et spøgelse, tiden bliver reference til index i "Ghosts"
            Ghosts.push_back({t, 0}); //Tiden gemmes et andet sted, i "Ghosts"
            What_ghost++; //Næste spørgelse bliver gemt på et andet sted
            return;
          }
          else if(i==group & (pos < Passengers[group-i].back()[0]))//Forreste gruppe har plads til spøgelser
          {
            //std::cout << "Den tilføger forrest et spøgelse: " <<What_ghost<<" med tiden "<<t<< '\n';
            Passengers[0].push_front({pos, -What_ghost});
            Passengers[group].push_back({pos, -What_ghost}); //Tilføger et spøgelse, tiden bliver reference til index i "Ghosts"
            Ghosts.push_back({t, 0}); //Tiden gemmes et andet sted, i "Ghosts"
            What_ghost++; //Næste spørgelse bliver gemt på et andet sted
            return;
          }
          else
          {
            i = group+1; //Så skal den hoppe ud af for-løkken
          }
        }
        /*
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
      //std::cout << "b: group forøges til " <<group+1<< '\n';
      group++;
      Passengers.resize(group+1);
      Passengers[group].push_back({pos, t});
    }
  }
  else //Næste gruppe er tom
  {
    //std::cout << "c" << '\n';
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
    int PT;
    //std::cout << "Den fjerner alt fra: " <<Passengers[0].back()[0]<<" og "<<Passengers[0].back()[1]<< '\n';
    if(Passengers[0].back()[1] < 0)
    {
      PT = Passengers[0].back()[1]; //Spøgelser er flere steder på én gang
      if(Ghosts[-PT][1] == 1) //Dette er den bagerste del af spøgelset
      {
        BT += Ghosts[-PT][0]; //Lægger dens tid til boarding tiden
      }
      Passengers[0].pop_back();
    }
    else
    {
      PT = Passengers[0].back()[1]; //De er kun mennesker
      BT += PT; //Lægger deres tid til boarding tiden
      Passengers[0].pop_back();
    }
    //std::cout << "size af forreste gruppe: " <<Passengers[0].size()<< '\n';
    if( !Passengers[0].empty() )
    {
      int no_exit = 1;
      if( PT < 0 )
      {
        if(Ghosts[-PT][1] == 0) //ikke tom og forreste spøgelse
        {
          no_exit = 0;
        }
      }
      if(no_exit)
      {
        for(int i=0; i<Passengers[0].size(); i++)
        {
          //std::cout << "trækker " <<PT<<" fra "<<Passengers[0][i][0]<<" og "<<Passengers[0][i][1]<< '\n';
          if(PT < 0) //PT er et spøgelse
          {
            if(Passengers[0][i][1] < 0)// Så er han også et spørgelse
            {
              //std::cout << "S S" << '\n';
              Ghosts[-Passengers[0][i][1]][0] -= Ghosts[-PT][0];
              if(Ghosts[-Passengers[0][i][1]][0] <= 0) //Spøgelset på rækken bruger ikke mere tid på at pakke
              {
                Passengers[0].erase(Passengers[0].begin()+i); //fjerne i'ende person
                i--; //Den skal ikke springe personer over
              }
            }
            else //Kun PT er spøgelse
            {
              Passengers[0][i][1] -= Ghosts[-PT][0];
              //std::cout << "S M " <<Ghosts[-PT][0]<<" Så den anden nu mangler"<<Passengers[0][i][1]<< '\n';
              if(Passengers[0][i][1] <= 0) //Mennesket på rækken bruger ikke mere tid på at pakke
              {
                Passengers[0].erase(Passengers[0].begin()+i); //fjerne i'ende person
                i--; //Den skal ikke springe personer over
              }
            }
          }
          else //PT er ikke et spøgelse
          {
            if(Passengers[0][i][1] < 0)// Så er den anden et spørgelse
            {
              //std::cout << "M S" << '\n';
              Ghosts[-Passengers[0][i][1]][0] -= PT;
              if(Ghosts[-Passengers[0][i][1]][0] <= 0) //Spøgelset på rækken bruger ikke mere tid på at pakke
              {
                Passengers[0].erase(Passengers[0].begin()+i); //fjerne i'ende person
                i--; //Den skal ikke springe personer over
              }
            }
            else //De er begge mennesker
            {
              //std::cout << "M M" << '\n';
              Passengers[0][i][1] -= PT;
              if(Passengers[0][i][1] <= 0) //Mennesket på rækken bruger ikke mere tid på at pakke
              {
                Passengers[0].erase(Passengers[0].begin()+i); //fjerne i'ende person
                i--; //Den skal ikke springe personer over
              }
            }
          }
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
            //std::cout << "Den rykker " <<Passengers[0+1].front()[0]<<" og "<<Passengers[0+1].front()[1]<<" til forreste gruppe"<< '\n';
            Passengers[0].push_back({Passengers[0+1].front()[0], Passengers[0+1].front()[1]}); //De rykker deque
            Passengers[0+1].pop_front(); //Fjerner dem fra anden deque
          }
          else
          {
            //std::cout << "break" << '\n';
            break;
          }
        }
        else if(Passengers.size() > 1)// Hvis man tømmer gruppen ved at rykke den
        {
          //std::cout << "test2" << '\n';
          Passengers.erase(Passengers.begin()+1); //remove 2'nd deque
          break;
        }
        else// Hvis man tømmer den sidste anden gruppe ved at rykke den
        {
          //std::cout << "test3" << '\n';
          break;
        }
      }
    }
    if(PT < 0) //Hvis vi lige har arbejdet med en del af et spøgelse
    {
      if(Ghosts[-PT][1] != 0)
      {
        Ghosts[-PT][0] = 0; //Har været hos den forreste, så er nu færdig med dette spøgelse
      }
      else
      {
        Ghosts[-PT][1] = 1; //Markerer, at jeg har været hos den forreste
      }
    }
    if(Passengers.size() <= 0)
    {
      //std::cout << "end" << '\n';
      break;
    }
  }
  //-----LOGIK-----
  std::cout << BT << '\n'; //resultat
  return 0;
}
