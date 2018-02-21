#include <iostream>
#include <vector>
using namespace std;

vector < vector< int > > Passengers;
long long BT = 0;
int l = 0;

/*
2
2 2
a) 1 1
b) 1 3
c) 3 2


2 0
1 1

*/

void add()
{
  int pos, t;
  std::cin >> pos >> t;
  Passengers.push_back({pos, t});
  for(int i=0; i<l; i++)
  {
    if(Passengers[l-1-i][1] != 0) //Hvis de ikke har sat sig
    {
      if(pos < Passengers[l-1-i][0])//Han skal ind før ham der står op
      {
        if(t <= Passengers[l-1-i][1]) //han bruger mindre eller lig tid på at pakke
        {
          Passengers[l-1-i][1] -= t;
          return;
        }
        else // han bruger længere tid på at pakke
        {
          BT += Passengers[l-1-i][1];
          Passengers[l][1] -= Passengers[l-1-i][1];
          t -= Passengers[l-1-i][1];
          Passengers[l-1-i][1] = 0;
          //Videre til næste i for-loopet
        }
      }
      else //Han skal ind efter ham der står op
      {
        BT += Passengers[l-1-i][1];
        Passengers[l-1-i][1] = 0;
        //Videre til næste i for-loopet
      }
    }
  }
  //Han må være forreste der står op
  //Gør ikke noget
}

void addrest(int n)
{
  for(int i=0; i<n; i++)//Går alle igennem
  {
    BT += Passengers[i][1]; //lægger resten, der står og venter, til
  }
}

int main()
{
  int n;
  std::cin >> n;

  for(int i=0; i<n; i++)
  {
    add();
    //-----------CMD--------------
/*
    std::cout << "Start:" << '\n';
    for(int i=0;i<=l;i++)
    {
      std::cout << Passengers[i][0] <<" og "<< Passengers[i][1]<<'\n';
    }
    std::cout << "BT: " <<BT<< '\n';
*/
    //-----------CMD--------------
    l++;
  }
  l--;
  //Så tager jeg resten
  addrest(n);
  std::cout << BT << '\n';
  return 0;
}
