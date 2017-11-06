#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
  int T,NG,NM,decoy;
  std::cin >> T;
  for(int o=0;o<T;o++)
  {
    std::cin >> NG>>NM;
    vector<int> G(NG);
    vector<int> M(NM);
    //std::cout << "er jeg overhovedet i gang? " <<NG<<" og "<<NM<<" og "<<decoy<< '\n';
    for(int i=0;i<NG;i++)
    {
      cin >> G[i];
      //std::cout << "Dette tal er tilføjet: " <<G[i]<< " som er placeret i: "<<i<< '\n';
    }
    for(int i=0;i<NM;i++)
    {
      cin >> M[i];
      //std::cout << "Dette tal(2) er tilføjet: " <<M[i]<< " som er placeret i: "<<i<< '\n';
    }
    sort (G.begin(),G.end());
    sort (M.begin(),M.end());
    while(1)
    {
      //std::cout << "Så lange er listerne: " <<NG<<" og "<<NM<< '\n';
      if(NG==0 and NM==0)
      {
        std::cout << "uncertain" << '\n';
        break;
      }
      else if(NG==0)
      {
        std::cout << "MechaGodzilla" << '\n';
        break;
      }
      else if(NM==0)
      {
        std::cout << "Godzilla" << '\n';
        break;
      }
      else
      {
        //std::cout << "Så langt så godt! " <<G[0]<<" og "<<M[0]<< '\n';
        if(G[0]<M[0])
        {
          NG--;
          //std::cout << "Vinder M?" << '\n';
          G.erase((G.begin()));
        }
        else
        {
          NM--;
          //std::cout << "well..." << '\n';
          M.erase((M.begin()));
          //std::cout << "please?" << '\n';
        }
        //std::cout << "Så lange er listerne nu! " <<NG<<" og "<<NM<< '\n';
      }
    }
  }
  return 0;
}
