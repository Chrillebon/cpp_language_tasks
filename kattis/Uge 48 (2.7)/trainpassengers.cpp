#include <iostream>

int impossible(long leave, long enter, long w8, long C, long InTrain)
{
  if(InTrain-leave<0) return 1;
  if(InTrain-leave+enter>C) return 1;
  if(InTrain-leave+enter!=C and w8) return 1;
  else return 0;
}

int main()
{
  long C, InTrain=0, leave, enter, w8;
  int n;
  std::cin >> C >> n;
  for(int i=0;i<n;i++)
  {
    std::cin >> leave >> enter >> w8;
    if(impossible(leave, enter, w8, C, InTrain))
    {
      std::cout << "impossible" << '\n';
      return 0;
    }
    InTrain += enter-leave;
  }
  if(w8 || InTrain)
  {
    std::cout << "impossible" << '\n';
    return 0;
  }
  std::cout << "possible" << '\n';
  return 0;
}
