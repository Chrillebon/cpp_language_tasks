#include <iostream>
#include <string.h>

/*int main()
{
  int numbers[17]{}, sum = 0;
  int largest, smallest;
  for(int o=0;o<16;o++)
  {
    largest = 0;
    smallest = 9999;
    for(int u=0;u<16;u++)
    {
      std::cin >> numbers[u];
      if(numbers[u]>largest) largest = numbers[u];
      if(numbers[u]<smallest) smallest = numbers[u];
      std::cout << "numbers & largest & smallest: " <<numbers[u]<<" og "<<largest<<" og "<<smallest<< '\n';
    }
    sum += largest-smallest;
    std::cout << "sum, largest, smallest: " <<sum<<", "<<largest<<", "<<smallest<< '\n';
  }

  std::cout << "sum = " <<sum<< '\n';
  return 0;
}*/

int numbers[17]{};
float gonow = 1.0;
int sum = 0, gozero = 0;

int tal(int u)
{
  for(int u=0;u<16;u++)
  {
    for(int p=0;p<16;p++)
    {
      int mod = 0;
      //mod = (numbers[u]%numbers[p]);
      gozero = numbers[u]%numbers[p];
      gonow = 1.0*(numbers[u]%numbers[p]);
      std::cout << "numbers[u] og numbers[p] and rest: "<<u<<": "<<numbers[u]<<" og "<<p<<": "<<numbers[p] <<" og resten: "<<gonow<<" og "<< gozero<< '\n';
      if(gonow==0 && u!=p)//&& gozero==gonow
      {
        std::cout << "del: " <<numbers[u]/numbers[p]<< '\n';
        return numbers[u]/numbers[p];
      }
    }
  }
}

int main()
{
  for(int o=0;o<16;o++)
  {
    for(int u=0;u<16;u++)
    {
      std::cin >> numbers[u];
    }
    sum += tal(o);
  }

  std::cout << "sum = " <<sum<< '\n';
  return 0;
}
