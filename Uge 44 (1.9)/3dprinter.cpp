#include <iostream>

int main()
{
  int n,i=1,nr=0,p1=0,p2=0,Result1,Result2;
  double n1,n2=0.5,p1d=0,p2d=0;
  std::cin >> n;
  n1=n;
  n2=n1/2;
  while(1)
  {
    if(i<n2)
    {
      p1=i;
    }
    else if (i>n2)
    {
      p2=i;
    }
    else
    {
      std::cout << nr+2 << '\n';
      break;
    }
    //std::cout << "Dette er i og nr: "<<i<< " og "<<nr << '\n';
    if(p2!=0)
    {
      if(p2==1)
      {
        p1=p2;
      }
      p1d=n%p1;
      p2d=n%p2;
      //std::cout << p1d<<" "<< p2d << '\n';
      Result1=n/p1;
      if(p1d)
      {
        Result1+=1;
      }
      Result2=n/p2;
      if(p2d)
      {
        Result2+=1;
      }
      if(p1!=p2)
      {
        Result1-=1;
      }
      //std::cout << n2 <<" "<<p1<<" "<<p2<<" "<<nr+Result1<<" "<<nr+Result2<< '\n';
      if(Result1<=Result2)
      {
        std::cout << nr+Result1 << '\n';
        break;
      }
      else
      {
        std::cout << nr+Result2 << '\n';
        break;
      }
    }
    i*=2;
    nr++;
  }
  return 0;
}

//printere: 1p -> 2p -> 4p -> 8p -> 16p ()
//de kan p: 1s -> 2s -> 4s -> 8s -> 16s (man skal dele med+1, hvis der er rest)
