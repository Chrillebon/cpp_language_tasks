#include <iostream>

int n,m;
void merge(int * result, int first[], int second[])
{
  int i=0,j=0, where=0;
  while(i+j < n+m)
  {
    if((first[i]<=second[j] || j>=m) && i<n)
    {
      result[where] = first[i];
      i++;
    }
    else
    {
      result[where] = second[j];
      j++;
    }
    where++;
  }
}

int main()
{
  std::cin >> n;
  int first[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> first[i];
  }
  std::cin >> m;
  int second[m];
  for(int i=0;i<m;i++)
  {
    std::cin >> second[i];
  }
  int result[n+m];
  merge(result, first, second);
  int k=0;
  while(k<n+m)
  {
    std::cout << result[k] << " ";
    k++;
  }
  return 0;
}
