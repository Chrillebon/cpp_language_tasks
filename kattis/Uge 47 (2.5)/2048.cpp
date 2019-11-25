#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> map(4, vector<int>(4));

void setup()
{
  for(int o=0;o<4;o++)
  {
    for (int u=0;u<4;u++)
    {
      std::cin >> map[u][o];
    }
  }
}

void printresult()
{
  for(int o=0;o<4;o++)
  {
    for (int u=0;u<4;u++)
    {
      std::cout << map[u][o]<<" ";
    }
    std::cout << '\n';
  }
}

int main()
{
  setup();
  int dir,mem1,mem2;
  std::cin >> dir;

  //så virker denne!
  if(dir==0)
  {
    for (int o=0;o<=3;o++)
    {
      int cont = 1;
      int startat = 0;
      while(cont)
      {
        cont = 0;
        for(int u=startat;u<3;u++)
        {
          mem1 = map[u][o];
          mem2 = map[u+1][o];
          if(mem1 == mem2)
          {
            map[u][o] = mem2*2;
            map[u+1][o] = 0;
            if(map[u][o] != 0)
            {
              cont = 1;
              startat=u+1;
            }
          }
          else if(mem1 == 0)
          {
            map[u][o] = mem2;
            map[u+1][o] = 0;
            if(mem2)
            {
              cont = 1;
            }
          }
        }
      }
    }
  }
  //så virker denne også
  else if(dir==1)
  {
    for (int u=3;u>=0;u--)
    {
      int cont = 1;
      int startat = 0;
      while(cont)
      {
        cont = 0;
        for(int o=startat;o<3;o++)
        {
          mem1 = map[u][o];
          mem2 = map[u][o+1];
          if(mem1 == mem2)
          {
            map[u][o] = mem2*2;
            map[u][o+1] = 0;
            if(map[u][o] != 0)
            {
              cont = 1;
              startat=o+1;
            }
          }
          else if(mem1 == 0)
          {
            map[u][o] = mem2;
            map[u][o+1] = 0;
            if(mem2)
            {
              cont = 1;
            }
          }
        }
      }
    }
  }
  //Så virker denne, en tilbage...
  else if(dir==2)
  {
    for (int o=0;o<=3;o++)
    {
      int cont = 1;
      int startat = 3;
      while(cont)
      {
        cont = 0;
        for(int u=startat;u>0;u--)
        {
          mem1 = map[u][o];
          mem2 = map[u-1][o];
          if(mem1 == mem2)
          {
            map[u][o] = mem2*2;
            map[u-1][o] = 0;
            if(map[u][o] != 0)
            {
              cont = 1;
              startat=u-1;
            }
          }
          else if(mem1 == 0)
          {
            map[u][o] = mem2;
            map[u-1][o] = 0;
            if(mem2)
            {
              cont = 1;
            }
          }
        }
      }
    }
  }
  //så håber vi, at der ikke er mere...
  else if(dir==3)
  {
    for (int u=0;u<=3;u++)
    {
      int cont = 1;
      int startat = 3;
      while(cont)
      {
        cont = 0;
        for(int o=startat;o>0;o--)
        {
          mem1 = map[u][o];
          mem2 = map[u][o-1];
          if(mem1 == mem2)
          {
            map[u][o] = mem2*2;
            map[u][o-1] = 0;
            if(map[u][o] != 0)
            {
              cont = 1;
              startat=o-1;
            }
          }
          else if(mem1 == 0)
          {
            map[u][o] = mem2;
            map[u][o-1] = 0;
            if(mem2)
            {
              cont = 1;
            }
          }
        }
      }
    }
  }
  printresult();
  return 0;
}
