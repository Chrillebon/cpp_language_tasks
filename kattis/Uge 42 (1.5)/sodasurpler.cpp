#include <iostream>

int main()
{
  int e,f,c,EB,FB,Result=0;
  scanf("%d %d %d", &e, &f, &c);
  EB = e+f;
  while(EB>=c)
  {
    FB = EB/c;
    while(EB>=c)
    {
      EB -= c;
    }
    Result += FB;
    EB += FB;
  }
  std::cout << Result << '\n';
  return 0;
}
