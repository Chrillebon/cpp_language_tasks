#include <iostream>

int main()
{
  int N, Count = 1, D = 0;
  scanf("%d", &N);
  for(int i=0;i<N;i++)
  {
    D += Count;
    Count = Count*2;
  }
  D += 2;
  int Result = D*D;
  std::cout << Result << '\n';
}

/*
1=i
2=i+2*i
3=i+2*i+4*i
1 = (2+1)^2 --- 1
2= (2+1+2)^2 --- 3
3= (2+1+2+41)^2 --- 7
4= (2+1+2+4+8)^2 --- 15
5 = (2+1+2+4+8+16)^2 --- 31
6 --- 63
F UUUUUU cmath*/
