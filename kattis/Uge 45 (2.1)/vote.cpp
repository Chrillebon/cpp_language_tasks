#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
  int n,total=0,votes,T,max;
  std::cin >> T;
  for(int o=0;o<T;o++)
  {
    std::cin >> n;
    std::vector<int> cand(n);
    total=0;
    for(int i=0;i<n;i++)
    {
      std::cin >> votes;
      cand[i]=votes;
      total+=votes;
    }
    max=std::distance(cand.begin(),std::max_element(cand.begin(),cand.end()));
    std::sort (cand.begin(),cand.end());
    if(*(cand.begin()+n-1)==*(cand.begin()+n-2))
    {
      std::cout << "no winner" << '\n';
    }
    else if(*(cand.begin()+n-1)>total/2)
    {
      std::cout << "majority winner " <<max+1<< '\n';
    }
    else if(*(cand.begin()+n-1)<=total/2)
    {
      std::cout << "minority winner " <<max+1<< '\n';
    }
  }
  return 0;
}
