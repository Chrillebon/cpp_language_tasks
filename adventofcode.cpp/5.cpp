/*#include <iostream>

int main()
{
  int n=0, steps=0,number, middleman;
  int Jumps[10000];
  while(std::cin >> number)
  {
    Jumps[n] = number;
    n++;
  }
  int max = n;
  n = 0;
  while(n>=0 && n<=max)
  {
    std::cout << "n: " <<n<<" og Jumps[n]: "<<Jumps[n]<< '\n';
    middleman = n;
    n+=Jumps[n];
    Jumps[middleman]++;
    steps++;
  }
  std::cout << "Final amount of steps: " <<steps<< '\n';
  return 0;
}*/


#include <iostream>

int main()
{
  int n=0, steps=0,number, middleman;
  int Jumps[10000];
  while(std::cin >> number)
  {
    Jumps[n] = number;
    n++;
  }
  int max = n-1;
  //std::cout << "max: " <<max<< '\n';
  n = 0;
  while(n>=0 && n<=max)
  {
    //std::cout << "FØR!: n: " <<n<<" og Jumps[n]: "<<Jumps[n]<< '\n';
    middleman = n;
    if(Jumps[n]>=3)
    {
      n+=Jumps[n];
      Jumps[middleman]--;
    }
    else
    {
      n+=Jumps[n];
      Jumps[middleman]++;
    }
    //std::cout << "EFTER!: n: " <<n<<" og Jumps[n]: "<<Jumps[n]<< '\n';
    steps++;
  }
  std::cout << "Final amount of steps: " <<steps<< '\n';
  return 0;
}
