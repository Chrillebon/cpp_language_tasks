#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int ax,ay,bx,by;
  double Result=0;
  std::cout.precision(11);
  vector< vector<int> > Unlock(3, vector<int> (3));
  for(int i=0; i<3;i++)
  {
    for(int o=0;o<3;o++)
    {
      cin >> Unlock[i][o];
    }
  }
  for(int u=1;u<=9;u++)
  {
    for(int i=0; i<3;i++)
    {
      for(int o=0;o<3;o++)
      {
        //std::cout << "Så langt så godt: " << u<<" "<<i<<" "<<o<<" "<<Unlock[i][o]<< '\n';
        if(Unlock[i][o] == u)
        {
          //std::cout << "Så er de ens!" << '\n';
          if(u==1)
          {
            ax=i;
            ay=o;
          }
          else
          {
            bx=ax;
            by=ay;
            ax=i;
            ay=o;
            //std::cout << "ax,ay,bx,by: " <<ax<<" "<<ay<<" "<<bx<<" "<<by<< '\n';
            if(bx != ax and by != ay)
            {
              Result+=sqrt(pow(bx-ax,2)+pow(by-ay,2));
            }
            else
            {
              Result += abs((bx-ax)+(by-ay));
            }
            //std::cout <<"Dette er resultatet: "<< Result << '\n';
          }
          o=3;
          i=3;
        }
      }
    }
  }
  std::cout << Result << '\n';
  return 0;
}
