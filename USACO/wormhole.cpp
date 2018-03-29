/*
ID: Christi69
PROB: wormhole
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <numeric>
using namespace std;

ifstream fin ("wormhole.in");
ofstream fout ("wormhole.out");

vector< pair<long long, long long> > worm;
vector< long long > port;
pair<long long, long long> coor;
vector<int> been;
int N, res = 0;

int move()
{
  long long x = coor.first;
  long long tempx = 1000000001;
  int whereto = -1;
  for(int i=0;i<N;i++)
  {
    if(coor.second == worm[i].second) //samme y-koordinat
    {
      if(x<worm[i].first) //Efter nuværrende x
      {
        if(worm[i].first<tempx) //første portal på denne linje
        {
          tempx = worm[i].first;
          whereto = i;
        }
      }
    }
  }
  coor.first = tempx;
  if(tempx < 1000000001)
  {
    return whereto;
  }
  else
  {
    return -1;
  }
}

void tp(int w)
{
  if(w != -1)
  {
    //w er hvor koen står,
    //port[w] er hvor den skal hen,
    //resultatet giver koordinatet for hvor den skal hen
    coor.first = worm[port[w]].first;
    coor.second = worm[port[w]].second;
  }
}

int cycle()
{
  been.clear();
  int temp;
  for(int i=0;i<N;i++)
  {
    coor.first = worm[i].first;
    coor.second = worm[i].second;
    while(coor.first <= 1000000000)
    {
      temp = move(); //Koen går
      if(temp == -1) //Hvis koen når ud
      {
        been.clear(); //Prøv forfra med næste startsted;
        break;
      }
      else //Den står ved en portal
      {
        for(int o=0;o<been.size();o++) //Tjek om den har været her før
        {
          if(temp == been[o])
          {
            return 1;
          }
        }
        been.push_back(temp); //Læg denne til hvor den har været
        tp(temp); //teleporterer koen
      }
    }
  }
  return 0;
}

int sum(int arr[])
{
  int sum=0;
  for(int i=0;i<N;i++)
  {
    sum+=arr[i];
  }
  return sum;
}

void testall(int opt[])
{
  if(sum(opt) == 2) //Nederste gren
  {
    int a=-1, b=-1;
    for(int i=0;i<N;i++)//finder de to sidste
    {
      if(opt[i] == 1)
      {
        if(a == -1)
        {
          a = i;
        }
        else
        {
          b = i;
        }
      }
    }
    port[a] = b;
    port[b] = a;
    if(cycle())
    {
      res++;
    }
    return;
  }
  else
  {
    int i=0, a = -1, b = -1;
    while(opt[i] == 0)
    {
      i++;
    }
    a = i;
    opt[a] = 0;
    int how_long = sum(opt);
    for(int o=0;o<how_long;o++)
    {
      i=0;
      for(int u=0;u<=o;u++)
      {
        while(opt[i] == 0)
        {
          i++;
        }
        i++;
      }
      i--;
      opt[i] = 0;
      port[a] = i;
      port[i] = a;
      testall(opt);
      opt[i] = 1;
    }
    opt[a] = 1;
  }
}

int main()
{
  long long a, b;
  fin >> N;
  for(int i=0;i<N;i++)
  {
    fin >> a >> b;
    worm.push_back(make_pair(a, b));
  }
  port.resize(N, -1);
  int asdf[N];
  fill(asdf, asdf+N, 1);
  testall(asdf);
  fout << res << '\n';
  //lav alle kombinationer
  return 0;
}
