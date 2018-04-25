#include <iostream>

long long res = 0;
int n, k;

int dontcollide(int arr[], int x, int y, int d)
{
  if(x>k)
  {
    return 0;
  }
  for(int i=0;i<d;i++)
  {
    if(arr[i*2]-arr[i*2+1] == x-y)
    {
      //std::cout << "A: " <<i<< '\n';
      //std::cout << (arr[i*2]) <<" og "<<arr[i*2+1]<< '\n';
      return 0;
    }
    if(arr[i*2]+arr[i*2+1] == x+y)
    {
      //std::cout << "B" << '\n';
      return 0;
    }
  }
  return 1;
}

void place(int arr[], int d, int l)
{
  if(d == n)
  {
    res++;
    return;
  }
  int x,y;
  if(d!=0)
  {
    //abs(arr[(d-1)*2]-arr[(d-1)*2]+1)
    y=k,x=arr[(d-1)*2]+l; //rykker videre til næste lag
  }
  else
  {
    x=1,y=k;
    d=0;
  }
  while(x < n*2)
  {
    //std::cout << x <<" og "<<y<< '\n';
    if(dontcollide(arr, x, y, d))
    {
      //std::cout << x << " samt "<<y << '\n';
      arr[d*2] = x;
      arr[d*2+1] = y;
      place(arr, d+1, 1);
      arr[d*2] = 0;
      arr[d*2+1] = 0;
    }
    x-=1;
    y-=1;
    if(x == 0 || y == 0)
    {
      l++;
      y=k,x=arr[(d-1)*2]+l; //rykker videre til næste lag
    }
  }
  return;
}

int main()
{
  std::cin >> n >> k;
  int diag[2*n];
  diag[0] = -2; diag[1] = -2;
  place(diag, 0, 1);
  std::cout << res << '\n';
  return 0;
}
