#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main()
{
  int n, m = 100, when;
  std::cin >> n;
  vector<int> days(n);
  for(int i=0;i<n;i++)
  {
    std::cin >> days[i];
  }
  for(int i=2;i<n;i++)
  {
    if(max(days[i],days[i-2]) < m)
    {
      when = i-1;
      m = max(days[i],days[i-2]);
    }
  }
  std::cout << when << " " << m << '\n';
  return 0;
}
