#include <iostream>

int main()
{
  int h,w,n,l;
  std::cin >> h>>w>>n;
  for(int o=1;o<=h;o++)
  {
    int i=0;
    while(i<w)
    {
      std::cin >> l;
      i+=l;
    }
    if(i>w)
    {
      std::cout << "NO" << '\n';
      return 0;
    }
  }
  std::cout << "YES" << '\n';
  return 0;
}
