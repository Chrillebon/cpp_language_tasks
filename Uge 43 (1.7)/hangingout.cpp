#include <iostream>
#include <string>

int main()
{
  int L,x,p,OT=0,Result=0;
  std::string Whereto;
  std::cin >> L >> x;
  for(int i=0;i<x;i++)
  {
    std::cin >> Whereto >> p;
    if(Whereto == "enter")
    {
      if(p+OT<=L)
      {
        OT += p;
      }
      else
      {
        Result += 1;
      }
    }
    else
    {
      OT -= p;
    }
  }
  std::cout << Result << '\n';
  return 0;
  //return 1; giver time error...
}
