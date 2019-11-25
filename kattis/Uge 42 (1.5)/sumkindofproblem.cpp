#include <iostream>

int main()
{
  int P;
  scanf("%d", &P);
  for(int i=1;i<=P;i++)
  {
    int K,N,S1=0,S2=0,S3=0,add,o;
    //når jeg "+="'er' dem skal de have en startværdi...
    scanf("%d %d",&K,&N);
    for(int u=0;u<3;u++)
    {
      if(u==0)
      {
        o = 1;
        add = 1;
        for(;o<=(N*add);o+=add)
        {
          S1 += o;
        }
      }
      else if(u==1)
      {
        o = 1;
        add = 2;
        for(;o<=(N*add);o+=add)
        {
          S2 += o;
        }
      }
      else
      {
        o = 2;
        add = 2;
        for(;o<=(N*add);o+=add)
        {
          S3 += o;
        }
      }
    }
    std::cout << K << " " << S1 << " " << S2 << " " << S3 << '\n';
  }
  return 0;
}
