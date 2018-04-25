#include <iostream>
using namespace std;

long long res[300][300];
int largenumb[300];
int n, k;

long long power(int numb, int base)
{
  long long res = numb;
  for(int i=0;i<base;i++)
  {
    res *= 10;
    res %= 100000007;
  }
  return res;
}

void fill(int arr[])
{
  for(int i=0;i<n;i++) //Start
  {
    for(int o=0;o<n;o++) //Afstanden
    {
      if(i+o < n) //Ikke for langt
      {
        //Sum:
        res[i][o] = 0;
        for(int u=0;u<=o;u++)
        {
          res[i][o] += power(largenumb[i+o-u], u);
        }
        res[i][o] %= 100000007;
      }
    }
  }
}

int main()
{
  scanf("%d %d\n", &n, &k);
  for(int i=0;i<n;i++)
  {
    scanf("%1d", &largenumb[i]);
  }
  fill(largenumb);
  for(int i=0;i<n;i++)
  {
    std::cout << "tester: "<<i<<"! ";
    for(int o=0;o<n;o++)
    {
      std::cout << res[i][o] <<" ";
    }
    std::cout << '\n';
  }
  return 0;
}
