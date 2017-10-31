#include <iostream>
#include <vector>
using namespace std;

int main()
{
  int ax,ay,bx,by;
  vector< vector<char> > Unlock(3, vector<char> (3));
  for(int i=0; i<3;i++)
  {
    for(int o=0;o<3;o++)
    {
      cin >> Unlock[i][o];
    }
  }
  
  return 0;
}
