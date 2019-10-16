#include <iostream>
#include <vector>
using namespace std;

int worst_case[2]; //lost, highest rem. val
int cards[5];

void reset()
{
  worst_case[0] = 0;
  worst_case[1] = 0;
  for(int i=0;i<5;i++)
  {
    cards[i]=0;
  }
  return;
}

int tryall(vector<int> taken, int depth, int lost, int high, int picked)
{
  if(depth != -1)
  {
    if(taken[picked] == 2) //last card is vs 6'th
    {
      high = cards[depth]; //highest rem. card
    }
    else
    {
      if(cards[depth] > cards[3+taken[picked]]) //higher than last card
      {
        lost++;
      }
    }
    taken.erase(taken.begin()+picked);
  }

  for(int i=0;i<(2-depth);i++)
  {
    tryall(taken, depth+1, lost, high, i);
  }

  if(depth == 2) //lowest level - end condition
  {
    if(lost > worst_case[0]) //worse outcome
    {
      worst_case[0] = lost;
      worst_case[1] = high;
    }
    else if(lost == worst_case[0] && high >= worst_case[1])
    {
      worst_case[1] = high;
    }
    return 0;
  }
}


void sixth_card()
{
  if(worst_case[0] == 0)
  {
    int lowest = 1;
    int print = 1;
    while(1)
    {
      print = 1;
      for(int i=0;i<5;i++)
      {
        if(lowest == cards[i])
        {
          lowest++;
          print = 0;
          break;
        }
      }
      if(print)
      {
        std::cout << lowest << '\n';
        return;
      }
    }
    std::cout << lowest << '\n';
  }
  else if(worst_case[0] == 2) //no winning
  {
    std::cout << "-1" << '\n';
  }
  else if(worst_case[0] == 1)
  {
    int lowest = worst_case[1]+1;
    int print = 1;
    while(1)
    {
      print = 1;
      for(int i=0;i<5;i++)
      {
        if(lowest == cards[i])
        {
          lowest++;
          print = 0;
          break;
        }
      }
      if(print)
      {
        if(lowest >= 53)
        {
          std::cout << "-1" << '\n';
        }
        else
        {
          std::cout << lowest << '\n';
        }
        return;
      }
    }
  }
  return;
}

int main()
{
  int temp;
  while(std::cin >> temp)
  {
    if(temp == 0) //the end!
    {
      break;
    }
    cards[0] = temp;
    for(int i=0;i<4;i++)
    {
      std::cin >> cards[1+i];
    }
    tryall({0,1,2}, -1, 0, 0, 0);
    sixth_card();
    reset();
  }
}
