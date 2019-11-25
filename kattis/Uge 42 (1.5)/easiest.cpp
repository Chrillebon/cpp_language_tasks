#include <iostream>
#include <sstream>

int main()
{
  while(1)
  {
    int N,Nm,Nsum = 0,m;
    scanf("%d", &N);
    std::stringstream Stringify;
    Stringify << N;
    if(N==0)
    {
      break;
    }
    for(int i=0;i<6;i++)
    {
      if((Stringify.str())[i] == '\0')
      {
        break;
      }
      Nsum += (Stringify.str())[i]-48;
      //ingen ide om hvorfor, men alt er lineært lægt 48 til...
    }
    for(m=11;m<100;m++)
    {
      Nm = N*m;
      std::stringstream StringifyNm;
      StringifyNm << Nm;
      int Nmsum = 0;
      for(int i=0;i<9;i++)
      {
        if((StringifyNm.str())[i] == '\0')
        {
          break;
        }
        Nmsum += (StringifyNm.str())[i]-48;
      }
      if(Nmsum == Nsum)
      {
        std::cout << m << '\n';
        break;
      }
    }
    if(m==100)
    {
      std::cout << 100 << '\n';
    }
  }
  return 0;
}
