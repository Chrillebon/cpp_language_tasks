/*
ID: Christi69
PROB: sort3
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin ("sort3.in");
ofstream fout ("sort3.out");

int n;
int data[1000]{};
int abc[4], abcpos[4];
int exchanges = 0;

void countdata()
{
  for(int i=0;i<n;i++)
  {
    abc[data[i]]++;
  }
}

int main()
{
  fin >> n;
  for(int i=0;i<n;i++)
  {
    fin >> data[i];
  }
  countdata();
  abcpos[1] = abc[1];
  abcpos[2] = abc[1]+abc[2];
  abcpos[3] = n;
  for(int i=0;i<n;i++) //Go through all swaps
  {
    if(i >= abcpos[data[i]-1] && i < abcpos[data[i]]) //number is good
    {
      //do nothing
    }
    else //Find a swap
    {
      //std::cout << "want to swap pos: " <<i<<" with number: "<<data[i]<< '\n';
      int gofor, best;
      if(i < abcpos[1]) //position where a 1 should be
      {
        gofor=1;
      }
      else if(i < abcpos[2]) //position where a 2 should be
      {
        gofor=2;
      }
      else //position where a 3 should be
      {
        gofor=3;
      }
      //prep done, time to find the best swap
      int buffer = data[i]; //need it later + to see if changed
      for(int o=abcpos[data[i]-1];o<abcpos[data[i]];o++) // go through all spots where it would fit
      {
        if(data[o] == data[i]) //same - no need to change
        {
          //next spot
        }
        else if(data[o] == gofor) //best possible exchange
        {
          data[i] = data[o];
          data[o] = buffer;
          buffer = 0;
          exchanges++;
          //std::cout << "swapped to pos: " <<o<< '\n';
          break; //No need to go through more
        }
        else //needs to be changed again later
        {
          best = o;
        }
      }
      if(buffer != 0) //only suboptimal swaps found
      {
        data[i] = data[best];
        data[best] = buffer;
        buffer = 0;
        //std::cout << "swapped to pos: " <<best<< '\n';
        exchanges++;
      }
    }
    //Has now been swapped to better position if needed
  }
  fout << exchanges << '\n';
  return 0;
}
