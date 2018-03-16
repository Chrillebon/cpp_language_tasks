#include <iostream>
#include <cmath>

long n,s=0;

int rec(long s,long n,int y)
{
  y += s*s;
  if(s==n){ std::cout <<"I dette tilfælde vil der være "<< y <<" kasser."<< '\n'<<'\n';return y;}
  else if(s>n){std::cout << "Lav lige noget ordentligt input tak!" << '\n'<<'\n'; return -1;}
  else rec(s+1,n,y);
}

/*int eks4(int n, long int Result)
{
  Result += n;
  if(n==0) { std::cout <<"I dette tilfælde vil resultatet være: "<< Result << '\n'<<'\n';return Result;}
  else eks4(n-1,Result);
}*/

int getvariables()
{
  int r=0;
  std::cout << "y0 = ";
  if(scanf("%d",&s)==1) r++;
  std::cout <<'\n'<< "n = ";
  if(scanf("%d",&n)==1) r++;
  std::cout << '\n';
  return r;
}

int main()
{
  std::cout << "Hvor mange lag skal pyramiden være? (f(yn,n) = yn + (n+1)^2)" << '\n'<<'\n';
  getvariables();
  rec(s,n,0);
  while(1)
  {
    std::cout << "Indtast, hvis du vil prøve igen: " << '\n'<<'\n';
    if(getvariables()==2) rec(s,n,0);
    else return 0;
  }
  /*
  std::cout << "Hvad så med denne opgave:" << '\n'<< "f(y,n) = y + n + 1"<<'\n'<<"Hvor mange trin vil du have her?"<<'\n';
  scanf("%ld",&n);
  eks4(n,0);*/
  return 0;
}
