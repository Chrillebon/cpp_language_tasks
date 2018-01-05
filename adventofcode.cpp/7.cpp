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
  }
  return 0;
}
