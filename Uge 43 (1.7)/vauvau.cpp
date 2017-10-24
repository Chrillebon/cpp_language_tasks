#include <iostream>

bool attacked(int who,int agg, int pas)
{
  who %= (agg+pas);
  if(who!=0 and who<=agg)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int print(int Result)
{
  if(Result==0)
  {
    std::cout << "none" << '\n';
  }
  else if(Result==1)
  {
    std::cout << "one" << '\n';
  }
  else if (Result == 2)
  {
    std::cout << "both" << '\n';
  }
  return 0;
}

int main()
{
  int A,B,C,D,P,M,G,Result=0;
  std::cin >> A >> B >> C >> D;
  std::cin >> P >> M >> G;
  if(attacked(P,A,B))
  {
    Result+=1;
  }
  if(attacked(P,C,D))
  {
    Result+=1;
  }
  print(Result);
  Result = 0;
  if(attacked(M,A,B))
  {
    Result+=1;
  }
  if(attacked(M,C,D))
  {
    Result+=1;
  }
  print(Result);
  Result = 0;
  if(attacked(G,A,B))
  {
    Result+=1;
  }
  if(attacked(G,C,D))
  {
    Result+=1;
  }
  print(Result);
  Result = 0;
  return 0;
}
