#include <iostream>
#include <cmath>
#include <string.h>


int opg2(long n,long val)
{
  if(n == 0) return val;
  else
  {
    val += n*n;
    opg2(n-1,val);
  }
}

float opg4b(int n, float val)
{

  if(n == 0) return val;
  else
  {
    val = -val/2;
    //std::cout << "Dette er tallet: " <<val<< '\n';
    return opg4b(n-1,val);
  }
}

float rek3(float start, float rente, float afdrag, int n)
{
  if(n==0) return start;
  start*=(1+rente);
  start-=afdrag;
  return rek3(start, rente, afdrag, n-1);
}

float newtonsmetode(float start, int n)
{
  if(n==0) return start;
  start = start - ( pow(start,3) - 3*pow(start,2) + start + 3) / ( 3*pow(start,2) - 6*start + 1);
  std::cout << "x" <<7-n<<" = "<<start<< '\n';
  return newtonsmetode(start,n-1);
}

float sqrt(float val, float S)
{
  if(val == 0)
  {
    val=1;
  }
  float locval;
  locval = 1.0/2*(val+S/val);
  if(val == locval) return locval;
  else return sqrt(locval,S);
}

float xval[10];
float yval[10];

int euler(int n,int now)
{
  float h = 0.25;
  if(now>n)
  {
    std::cout << "xn: " << '\n';
    for(int i=0;i<n+1;i++)
    {
      std::cout << xval[i]<<" ";
    }
    std::cout << '\n'<<'\n';
    std::cout << "yn: " << '\n';
    for(int i=0;i<n+1;i++)
    {
      std::cout << yval[i]<<" ";
    }
    std::cout << '\n';
    return 1;
  }
  if(xval[0]==0)
  {
    xval[0] = 1;
  }
  xval[now] = xval[now-1]+h;
  if(yval[0]==0)
  {
    yval[0] = 2;
  }
  yval[now] = 1.0*(yval[now-1]+h*sqrt(yval[now-1]));
  return euler(n,now+1);
}

char top[50];
char mid[50];
char bot[50];

void draw(int m, int n)
{
  if(m==1)
  {
    mid[0] = '/';
    mid[1] = '\\';
    bot[0] = 238;
    bot[1] = 238;
  }
  if(m>n)
  {
    for(int i=0;i<n+2;i++)
    {
      std::cout << top[i];
    }
    std::cout << '\n';
    for(int i=0;i<n+2;i++)
    {
      std::cout << mid[i];
    }
    std::cout << '\n';
    for(int i=0;i<n+2;i++)
    {
      std::cout << bot[i];
    }
    std::cout << '\n';
  }
  else
  {
    if(!(m%2))
    {
      top[m-1] = '_';
      top[m] = '_';
      mid[m] = '/';
    }
    else
    {
      bot[m-1] = 238;
      bot[m] = 238;
      mid[m] = '\\';
    }
    return draw(m+1,n);
  }
}

int main()
{
  std::cout.precision(10);
  std::cout << "Opgave 1: " << '\n'<<"Udregn de første 1000 tal i talrækken:"<<'\n';
  std::cout <<"Svaret er: "<< opg2(1000,0) << '\n'<<'\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 2: " << '\n'<<"Udregn hvorvidt betingelserne er opfyldt for n=0...1000000 (100)"<<'\n';
  std::cout << "Svaret er: " << opg4b(100,10.0) << '\n'<<'\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 3: Lånet med afdrag giver: " <<rek3(73000, 0.06, 12000, 7)<< '\n'<<'\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 4: Newtons metode på eksemplet giver:" << '\n';
  newtonsmetode(0,6);
  std::cout << '\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 5: sqrt af 2: " <<sqrt(1.0,2.0)<< '\n'<<'\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 6: eulers metode i eksempel 11: " << '\n'<<'\n';
  std::cout.precision(5);
  euler(8,1);
  std::cout << '\n';
  std::cout << "----------------------------------------------------------------" << '\n'<<'\n';
  std::cout << "Opgave 7: tegningsopgaven:" << '\n';
  for(int i=1;i<=10;i++)
  {
    draw(1,i);
  }
  return 0;
}
