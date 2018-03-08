/*
PROG: ride
LANG: C++
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main()
{
  ofstream fout ("ride.out");
  ifstream fin ("ride.in");
  char comet[7];
  char group[7];
  fin >> comet;
  fin >> group;
  int i=0, val=1, comval=0, groval=0;
  while(comet[i] != '\0')
  {
    val *= comet[i]-64;
    i++;
  }
  comval = val % 47;
  i=0;val=1;
  while(group[i] != '\0')
  {
    val *= group[i]-64;
    i++;
  }
  groval = val % 47;
  if(groval == comval)
  {
    fout << "GO" << '\n';
  }
  else
  {
    fout << "STAY" << '\n';
  }
}
