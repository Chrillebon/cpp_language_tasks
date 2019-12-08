#include <iostream>
#include <string>
#include <string.h>
#include <cstdio>
using namespace std;
#include "7.h"

string move(Towers source)
{
  string buff = "";
  buff += source.name();
  buff += " (";
  buff += to_string(source.weight());
  buff += ")";
  if(source.relations())
  {
    buff += " -> ";
    for(int i=0;i<source.relations();i++)
    {
      if(i != 0)
      {
        buff += ", ";
      }
      buff += source.relation(i);
    }
  }
  return buff;
}

int search(string Name, Towers* Tree)
{
  for(int i=0;i<1500;i++)
  {
    if(Tree[i].name() == Name)
    {
      return i;
    }
  }
  std::cout << "Kan ikke finde den..." << '\n';
  return -1;
}

int main()
{
  /*Towers test;
  char h[100];
  scanf("%100[a-z 0-9,->()]",&h);
  std::cout << "h: " <<h<< '\n';
  test.set(h);
  std::cout << "Test af klasser giver: " << test.name() << " og " << test.weight();/* << " og "  << test.relation(0) << " og "  << test.relation(1) << " og "  << test.relation(2) << " og "  << test.relation(3) << " og "  << test.relation(4) << " og "  << test.relation(5) << " og "  << test.relation(6)*/// << " og til sidst, relationer: "<< test.relations()<< '\n';


  char h[100];
  Towers Programs[2000];
  fgets(h, 100, stdin);
  //scanf("%100[a-z 0-9,->()]",&h);
  Programs[0].set(h);
  int i=1;
  //std::cout << Programs[0].name() << '\n';
  //std::cout << "Den klarede den første!" << '\n';
  while(Programs[i-1].cont())
  {
    fgets(h, 100, stdin);
    Programs[i].set(h);
    i++;
  }
  /*
  int max = i-1;
  std::cout << "Antallet af programmer: " <<i-1<< '\n';
  //std::cout << "move test: " <<Programs[0].name()<< '\n';
  Towers TOP[500];
  int t=0;
  for(int i=0;i<max;i++)
  {
    if(Programs[i].relations()!=0)
    {
      //const char *memmov = move(Programs[i]).c_str();
      TOP[t].set(move(Programs[i]).c_str());
      //std::cout << "nr. " <<t<<" er: "<<TOP[t].name()<< '\n';
      t++;
    }
  }
  max = t-1;
  for(int i=0;i<max;i++)
  {
    for(int o=0;o<TOP[i].relations();o++)
    {
      string GETOUT = TOP[i].relation(o);
      for(int u=0;u<max;u++)
      {
        if(GETOUT[0] == '_')
        {
          break;
        }
        if(TOP[u].name() == GETOUT)
        {
          std::cout << "Den fjerner nr. " <<u<<" som har navnet: "<<TOP[u].name()<< '\n';
          TOP[u].stop();
          break;
        }
      }
    }
  }
  for(int i=0;i<max;i++)
  {
    if(TOP[i].cont() == 1)
    {
      std::cout << "Og svaret er: " <<TOP[i].name()<< '\n';
      break;
    }
  }*/
  string Branch[50];
  int BR [50]{};
  int ID [50]{};
  double Weights[8]{};
  int dir=1;
  int next;
  int depth = 0;
  Branch[depth] = "mkxke";
  BR[depth] = 0;
  ID[depth] = 1205;
  while(depth >= 0)
  {
    std::cout << "Branch[1]" <<Branch[1]<< '\n';
    if(Branch[1] == "uhcrfl") dir = 1;
    else if(Branch[1] == "bnhfnlw") dir = 2;
    else if(Branch[1] == "hdzls") dir = 3;
    else if(Branch[1] == "pcfilur") dir = 4;
    else if(Branch[1] == "onnfacs") dir = 5;
    else if(Branch[1] == "wdugfj") dir = 6;
    else if(Branch[1] == "jakdiea") dir = 7;
    else std::cout << "'DIR' ERROR" << '\n';

    std::cout << "Switch done: " <<dir<<" and "<<Programs[ID[depth]].relations()<< '\n';
    if(Programs[ID[depth]].relations() - BR[depth] == 0)
    {
      Branch[depth] = "";
      BR[depth] = 0;
      ID[depth] = 0;
      depth--;
      BR[depth]++;
    }
    else
    {
      next = search(Programs[ID[depth]].relation(BR[depth]), Programs);
      depth++;
      Branch[depth] = Programs[next].name();
      BR[depth] = 0;
      ID[depth] = next;
    }
    Weights[dir] += Programs[ID[depth]].weight();
    std::cout << "Weight: " <<Weights[dir]<<" name: "<<Branch[depth]<<" og depth: "<<depth<< '\n';
  }

  std::cout << "Resultater af vægtene:" << '\n';
  std::cout << "Nr. 1: " <<Weights[1]<< '\n';
  std::cout << "Nr. 2: " <<Weights[2]<< '\n';
  std::cout << "Nr. 3: " <<Weights[3]<< '\n';
  std::cout << "Nr. 4: " <<Weights[4]<< '\n';
  std::cout << "Nr. 5: " <<Weights[5]<< '\n';
  std::cout << "Nr. 6: " <<Weights[6]<< '\n';
  std::cout << "Nr. 7: " <<Weights[7]<< '\n';

  return 0;
}
