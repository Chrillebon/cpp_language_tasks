#include <iostream>
#include <algorithm>

long long input[3000000];
bool start[3000000]{};
long long t, result = 0;
int n, visited;


void gothrough(int s)
{
  if(start[s])
  {
    return;
  }
  while(s <= n-result)
  {
    start[s] = true;
    long long locmin = input[s], locmax = input[s], min = std::max(input[s]-t, (long long)(0)), max = std::min(input[s]+t, (long long)(2000000000));
    long long locres = 0;
    while(locmax-locmin <= t && s < n)
    {
      locres++;
      s++;
      //IN RANGE
      if(s < n)
      {
        if(input[s] < locmin)
        {
          locmin = input[s];
        }
        if(input[s] > locmax)
        {
          locmax = input[s];
        }
      }
      //--------------
    }
    result = std::max(result, locres);
    locres = 0;
  }
  return;
}


int findnext()
{
  for(int i=0;i<n;i++)
  {
    if(start[i] != true && i <= n-result)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  std::cin >> t >> n;
  visited = n;
  for(int i=0;i<n;i++)
  {
    std::cin >> input[i];
  }
  int whereto = findnext();
  while(whereto != -1)
  {
    gothrough(whereto);
    whereto = findnext();
  }
  std::cout << result << '\n';
  return 0;
}
/*
3 9
5 1 3 5 8 6 6 9 10

3 16
7 4 13 1 2 5 14 11 9 8 12 13 0 3 5 2
*/
