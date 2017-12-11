#include <iostream>
#include <string.h>

int main()
{
  int len = 2074/2;
  char number[2100];
  double sum=0;
  std::cin >> number;
  //std::cout << "strlen" <<strlen(number)<< '\n';
  for(int i=0;i<2074;i++)
  {
    if(i+len>2074) len -= 2074;
    //std::cout << "number["<<i<<"] og number["<<i+len<<"]: " <<number[i]<<" og "<<number[i+len]<< '\n';
    if(number[i]==number[i+len]) sum += number[i]-'0';
  }
  std::cout << sum << '\n';
}
