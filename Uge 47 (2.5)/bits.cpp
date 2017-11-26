#include <iostream>

int DtB(long a)
{
    int onebits = 0;
    int mask = 1;
    for(int i = 0; i < 33; i++)
    {
        if((mask&a) >= 1)
            onebits += 1;
        mask<<=1;
    }
    return onebits;
}

int Resultat(char number[11])
{
  int Result = 0,X=0;
  for(int o=0;o<11;o++)
  {
    if(number[o]=='\0') break;
    int tal = number[o]-48;
    //åndsvag "-48" bug igen...
    X*=10;
    X+=tal;
    if(DtB(X)>Result)
      Result = DtB(X);
  }
  return Result;
}

int main()
{
  int T;
  std::cin >> T;
  for(int i=0;i<T;i++)
  {
    long X=0;
    char number[11];
    int Result=0;
    std::cin >> number;
    std::cout << Resultat(number) << '\n';
  }
  return 0;
}
