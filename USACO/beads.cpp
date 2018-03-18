/*
ID: Christi69
PROB: beads
LANG: C++
*/

#include <iostream>
#include <map>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int firstval=0, firstid=-1;

int large(vector<int> pos, vector<int> sur, int *start)
{
  int val = pos[*start+1];
  int last = pos[*start];
  int before = *start;
  while(*start < pos.size()+2)
  {
    *start += 2;
    if(pos[*start] == 21 || pos[*start] == last || last == 21 || *start == pos.size())
    {
      if(*start == pos.size()) //Hvis den er forbi den sidste:
      {
        if(firstid == pos[*start-2] || (firstid == pos[*start-2] && pos[*start-2] == 21)) //Hvis første og sidste passer sammen:
        {
          return val+firstval;
        }
        else
        {
          return val;
        }
      }
      if(last == 21 && pos[*start] != 21)
      {
        last = pos[*start];
      }
      val += pos[*start+1];
    }
    else
    {
      if(pos[*start-2] == 21)
      {
        *start -= 2;
      }
      return val;
    }
  }
  return val;
}

int goback(vector<int> pos, int id)
{
  int sum = 0;
  int index = pos.size()-2;
  while(pos[index] == id || pos[index] == 21)
  {
    sum += pos[index+1];
    index -= 2;
  }
  return sum;
}

int main()
{
  ifstream fin ("beads.in");
  ofstream fout ("beads.out");
  int n;
  fin >> n;
  int necklace[n]{};
  int what=119, first=119;
  char temp;
  int temp2;
  for(int i=0;i<n;i++)
  {
    fin >> temp;
    temp2 = temp-98;
    necklace[i] = temp2;
  }
  first = necklace[0];
  int firstresult = 0;
  what = necklace[0];
  int white = 0, sum = 1;
  vector<int> pos;
  pos.push_back(necklace[0]);
  for(int i=1;i<n;i++)
  {
    if(necklace[i] == what)
    {
      sum++;
    }
    else
    {
      pos.push_back(sum);
      pos.push_back(necklace[i]);
      sum = 1;
      what = necklace[i];
    }
  }
  pos.push_back(sum);
  //---------overlap---------
  vector<int> sur(pos.size()/2);
  for(int i=0;i<pos.size();i+=2)
  {
    if(pos[i] == 21)
    {
      sur[i/2] = 0;
    }
    else
    {
      int asdf=0;
      if(pos[i-2] == 21 || (i==0 && pos[pos.size()-2] == 21))
      {
        asdf += 1;
      }
      if(pos[i+2] == 21 || (i==pos.size()-2 && pos[0] == 21))
      {
        asdf += 2;
      }
      sur[i/2] = asdf;
    }
  }
  int largest = 0, w = 0, start = 0, last[2] = {-1, 0}, end=0, runs = 0;
  int values[2]{}, where[2]{}, overlap = 0;
  while(start < pos.size())
  {
    w = (w+1)%2;
    last[0] = pos[start];
    last[1] = pos[start+1];
    values[w] = large(pos, sur, &start);
    runs++;
    if(start >= pos.size())
    {
      end = 2;
    }
    where[w] = sur[(start-end)/2];
    if(start-end > 0)
    {
      where[(w+1)%2] = sur[((start-end)/2)-1];
    }
    if((last[0] == 21 && pos.size() > 2) && (runs > 2 || last[0] == 21))
    {
      overlap = last[1];
    }
    if(firstval == 0)
    {
      firstval = values[w];
      if(pos[start-2] == 21 && start)
      {
        if(start > 2)
        {
          firstid = pos[start-4];
        }
        else
        {
          firstid = pos[start];
        }
      }
      else if(start == 0)//Så skal pos[0] være 21
      {
        firstid = pos[2];
      }
      else
      {
        firstid = pos[start-2];
      }
      //Så skal jeg gå baglænds nu...
      if(!end)
      {
        values[w] += goback(pos, firstid);
      }
    }
    if(values[0]+values[1]-overlap > largest)
    {
      largest = values[0]+values[1]-overlap;
    }
    overlap = 0;
  }
  fout << largest << '\n';
  return 0;
}
