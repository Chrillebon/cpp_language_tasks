#include <iostream>

int n;

int put_toget(int first, int second)
{
  int res = 0;
  res += first * 10;
  res += second;
  return res;
}

int zerosum(int* str)
{
  int sum = str[0];
  for(int i=1;i<2*n-1;i+=2)
  {
    if(str[i] == 0) // '+'
    {
      sum += str[i+1];
    }
    else if(str[i] == 1) // '-'
    {
      sum -= str[i]+1;
    }
    else // ' '
    {
      if(str[i-2] == 0) //tidligere var +
      {
        sum -= str[i-1]; //træk tidligere værdi fra
        sum += put_toget(str[i-1], str[i+1]); //Læg større tal til
        if(i != 0)
        {
          str[i] = str[i-2];
          str[i] = put_toget(str[i-1], str[i+1]);
        }
      }
      else //Tidligere var
      {
        sum += str[i-1]; //læg tidligere værdi til
        sum -= put_toget(str[i-1], str[i+1]); //træk større tal fra
        if(i != 0)
        {
          str[i] = str[i-2];
          str[i] = put_toget(str[i-1], str[i+1]);
        }
      }
    }
    std::cout << "part: " <<sum<< '\n';
  }
  return sum;
}

int main()
{
  std::cin >> n;
  int arr[5] = {1, 1, 2, 0, 3};
  std::cout << zerosum(arr) << '\n';
}
