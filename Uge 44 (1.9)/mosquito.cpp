#include <iostream>

int main()
{
  long M,P,L,C;
  int E,R,S,N;

  while(std::cin >>M>>P>>L>>E>>R>>S>>N)
  {
    for(int i=0;i<N;i++)
    {
      C=P/S;
      P=L/R;
      L=M*E;
      M=C;
      }
    std::cout << C << '\n';
  }
  return 0;
}
