/*
ID: Christi69
PROB: beads
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  int n;
  std::cin >> n;
  int necklace[n]{};
  int what=119, first=119;
  for(int i=0;i<n;i++)
  {
    scanf("%1c", &necklace[i]);
    necklace[i]-=98;
  }
  first = necklace[0];
  int firstresult = 0;
  int result[n]{};
  result[0] = 1;
  what = necklace[0];
  for(int i=1;i<n;i++)
  {
    if(necklace[i] == what || necklace[i] == 21)
    {
      result[i] += result[i-1]+1;
    }
    else
    {
      if(firstresult == 0)
      {
        firstresult = result[i];
      }
      result[i] == 1;
      what = necklace[i];
    }
  }
  if(what == first)
  {
    result[n-1] += firstresult;
  }
  int size = 0;
  int largest = 0;
  int turn = 0;
  for(int i=1;i<n;i++)
  {
    if(result[i] < size)
    {
      if(turn == 0)
      {
        turn = 1;
      }
      else
      {
        turn = 0;
        if(size > largest)
        {
          largest = size;
        }
        size = 0;
      }
      size++;
    }
  }
  for(int i=1;i<n;i++)
  {
    std::cout << necklace[i] << " ";
  }
  std::cout << '\n';
  for(int i=1;i<n;i++)
  {
    std::cout << result[i] << " ";
  }
  std::cout << '\n';
  if(first == necklace[n-1] || necklace[n-1] == 21 || first == 21)
  {
    result[n-1] += firstresult;
  }
  if(result[n-1] > largest)
  {
    largest = result[n-1];
  }
  std::cout << largest << '\n';
  return 0;
}
