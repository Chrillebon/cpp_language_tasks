#include <iostream>

int n,m;
void merge(int * result, int starto, int sluto, int startt, int slutt)
{
  int temp[sluto-starto+slutt-startt+2]{};
  int i=starto,j=startt, where=0;
  while(i<=sluto || j<=slutt)
  {
    if((result[i]<=result[j] || j>slutt) && i<=sluto)
    {
      temp[where] = result[i];
      i++;
    }
    else
    {
      temp[where] = result[j];
      j++;
    }
    where++;
  }
  for(int i=0;i<sluto-starto+slutt-startt+2;i++)
  {
    result[starto+i] = temp[i];
  }
}

int getmid(int start, int slut)
{
  return (start+slut)/2;
}

void mergesort(int arr[], int start, int slut)
{
  if(start<slut)
  {
    int m = getmid(start, slut);
    mergesort(arr, m+1, slut);
    mergesort(arr, start, m);
    merge(arr, start, m, m+1, slut);
  }
  return;
}

int main()
{
  std::cin >> n;
  int start[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> start[i];
  }
  mergesort(start, 0, n-1);
  int k=0;
  while(k<n)
  {
    std::cout << start[k] << " ";
    k++;
  }
  return 0;
}
