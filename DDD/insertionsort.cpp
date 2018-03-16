#include <iostream>

void sort(int arr[], int n)
{
  for(int i=1; i<n; i++)
  {
    int j = i;
    while(j>0 && arr[j-1]>arr[j])
    {
      int temp = arr[j-1];
      arr[j-1] = arr[j];
      arr[j] = temp;
      j--;
    }
  }
}

int main()
{
  int n;
  std::cin >> n;
  int arr[n];
  for(int i=0;i<n;i++)
  {
    std::cin >> arr[i];
  }
  sort(arr, n);
  for(int i=0;i<n;i++)
  {
    std::cout << arr[i] << " ";
  }
  return 0;
}
