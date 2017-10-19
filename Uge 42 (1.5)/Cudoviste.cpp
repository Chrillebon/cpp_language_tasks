#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
  int R, C;
  int Result[5] = {0,0,0,0,0};
  scanf("%d %d", &C, &R);

  //------------------------------------------
  //setup vectors
  vector< vector<char> > RnC(R, vector<char>(C));

  for(int ci=0; ci<C; ci++)
  {
    for(int ri=0; ri<R; ri++)
    {
      char PSpot;
      std::cin >> PSpot;
      RnC[ri][ci] = PSpot;
    }
  }
  //-------------------------------------------
  //How many viable spots?

  // gå igennem alle mulge parkeringspladser
  int CrashCars = 0;
  for(int ci=0; ci<C-1; ci++)
  {
    for(int ri=0; ri<R-1; ri++)
    {
      //gå igennem denne ene parkeringsplads
      for(int xi=0; xi<2; xi++)
      {
        for(int yi=0; yi<2; yi++)
        {
          //hvad er på parkeringspladsen
          //husk kun én når jeg nævner chars: 'test' ikke "test"...
          if(RnC[xi+ri][yi+ci] == '#')
          {
            CrashCars += 5;
          }
          else if (RnC[xi+ri][yi+ci] == 'X')
          {
            CrashCars += 1;
          }
        }
      }
      //læg til resultatet
      if (CrashCars < 5)
      {
        Result[CrashCars] += 1;
      }
      CrashCars = 0;
    }
  }

  std::cout << Result[0] << "\n" << Result[1] << "\n" << Result[2] << "\n" << Result[3] << "\n" << Result[4] << '\n';
  }
