#include <iostream>
#include <fstream>
#include <stdio.h>
#include <algorithm>

int n, bot = 0;
int board[1000000];
int maxsum[1000000];

void memset(int arr[])
{
  for(int i=0;i<1000000;i++)
  {
    arr[i] = -1;
  }
}

int move(int i, int whereto)
{
  if(whereto == 0) //højre
  {
    if(i%n == n-1)
    {
      return -1;
    }
    i++;
  }
  else //ned
  {
    if(i >= n*(n-1))
    {
      return -1;
    }
    i += n;
  }
  if(board[i] == 1)
  {
    return -1;
  }
  return i;
}

int backtrack(int i)
{
  if(i == n*n-1) //Tjekker om den er færdig
  {
    bot = 1; //Den når i bund!
    if(board[n*n-1] == 2)
    {
      return 1;
    }
    return 0;
  }
  int a = -100,b = -100;
  if(move(i,0) != -1)
  {
    if(maxsum[move(i, 0)] != -1)
    {
      a = maxsum[move(i,0)];
    }
    else
    {
      a = backtrack(move(i,0));
    }
  }
  if(move(i,1) != -1)
  {
    if(maxsum[move(i, 1)] != -1)
    {
      b = maxsum[move(i,1)];
    }
    else
    {
      b = backtrack(move(i,1));
    }
  }
  maxsum[i] = std::max(a,b);
  if(board[i] == 2 && bot)
  {
    maxsum[i]++;
    return maxsum[i];
  }
  return maxsum[i];
}


int main()
{
  char temp;
  std::cin >> n;
  memset(maxsum);
  for(int i=0;i<n*n;i++)
  {
    std::cin >> temp;
    if(temp == 'X')
    {
      board[i] = 1;
    }
    else if(temp == 'P')
    {
      board[i] = 2;
    }
    else
    {
      board[i] = 0;
    }
  }
  int total = backtrack(0);
  if(total < 0)
  {
    std::cout << "umuligt" << '\n';
    return 0;
  }
  std::cout << total << '\n';
  return 0;
}
