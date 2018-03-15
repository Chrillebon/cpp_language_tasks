/*
ID: Christi69
PROB: friday
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int days_in_months[] = {
  31, 28, 31, 30, 31, 30,
  31, 31, 30, 31, 30, 31};

int main()
{
  ofstream fout ("friday.out");
  ifstream fin ("friday.in");
  //start 1900 manday january first.
  int day = 0, n;
  fin >> n;
  int year = 1900;
  int result[7] = {0,0,0,0,0,0,0};
  while(n)
  {
    if(!(year % 4))
    {
      days_in_months[1] = 29;
      if(!(year % 100) && year % 400)
      {
        days_in_months[1] = 28;
      }
    }
    else
    {
      days_in_months[1] = 28;
    }
    for(int i=0; i<12; i++)
    {
      result[day]++;
      day += days_in_months[i];
      day %= 7;
    }
    year++;
    n--;
  }
for(int i=0; i<7; i++)
{
  fout << result[i];
  if(i!=6)
  {
    fout << " ";
  }
}
fout << '\n';
return 0;
}
