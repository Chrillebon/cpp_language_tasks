#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>

char piece;
int m, n, result;
int board[10][10];
int kpattern[8][2] = {{1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {-1, 2}};
int around[8][2] = {{-1,0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};

void place(int a, int b, int tempboard[][10])
{
  if(tempboard[a][b] == 0)
  {
    result++;
  }
  tempboard[a][b] = 1;
  if(piece == 'r')
  {
    for(int k=0; k<m; k++)
    {
      tempboard[k][b] = 1;
    }
    for(int l=0; l<n; l++)
    {
      tempboard[a][l] = 1;
    }
  }
  if(piece == 'k')
  {
    tempboard[a][b] = 1;
    for(int i=0;i<8;i++)
    {
      if(a+kpattern[i][0] >= 0 && a+kpattern[i][0] < m && b+kpattern[i][1] >= 0 && b+kpattern[i][1] < n)
      {
        tempboard[a+kpattern[i][0]][b+kpattern[i][1]] = 1;
      }
    }
  }
  if(piece == 'Q')
  {
    for(int k=0; k<m; k++)
    {
      tempboard[k][b] = 1;
    }
    for(int l=0; l<n; l++)
    {
      tempboard[a][l] = 1;
    }
    int h = a, j = b;
    while(h >= 0 && j >= 0)
    {
      tempboard[h][j] = 1;
      h--;
      j--;
    }
    h = a, j = b;
    while(h >= 0 && j < n)
    {
      tempboard[h][j] = 1;
      h--;
      j++;
    }
    h = a, j = b;
    while(h < m && j < n)
    {
      tempboard[h][j] = 1;
      h++;
      j++;
    }
    h = a, j = b;
    while(h < m && j >= 0)
    {
      tempboard[h][j] = 1;
      h++;
      j--;
    }
  }
  if(piece == 'K')
  {
    tempboard[a][b] = 1;
    for(int i=0;i<8;i++)
    {
      if(a+around[i][0] >= 0 && a+around[i][0] < m && b+around[i][1] >= 0 && b+around[i][1] < n)
      {
        tempboard[a+around[i][0]][b+around[i][1]] = 1;
      }
    }
  }
  return;
}

int tryQ(int a, int b, int path[][10])
{
  place(a, b, path);
  int maxval = 0;
  if(a == n-1)
  {
    for(int i=0;i<m;i++)
    {
      if(path[a][i] == 0)
      {
        return a+1;
      }
    }
    return a;
  }
  for(int i=0;i<m;i++)
  {
    if(path[a][i] == 0)
    {
      maxval = std::max(maxval, tryQ(a+1, i, path));
    }
  }
}

int tryall()
{
  if(piece == 'Q')
  {
    for(int o=0;o<m;o++)
    {
      for(int i=0;i<n;i++)
      {
        if(board[i][o] == 0)
        {
          tryQ(i, o, board);
          return 1;
        }
      }
    }
  }
  else
  {
    for(int i=0;i<m;i++)
    {
      for(int o=0;o<n;o++)
      {
        if(board[i][o] == 0 && (piece != 'k' || (i+o)%2 == 0))
        {
          place(i, o, board);
          return 1;
        }
      }
    }
  }
  return 0;
}

/*int tryQ(int a, int b)
{
  place(a, b);
  int good = 0;
  for(int i=0;i<1;i++)
  {
    if(a+kpattern[i][0] >= 0 && a+kpattern[i][0] < m && b+kpattern[i][1] >= 0 && b+kpattern[i][1] < n)
    {
      if(board[a+kpattern[i][0]][b+kpattern[i][1]] == 0)
      {
        place(a+kpattern[i][0], b+kpattern[i][1]);
        tryQ(a+kpattern[i][0], b+kpattern[i][1]);
        return 1;
      }
    }
  }
  return tryall();
}*/

void reset_board()
{
  for(int i=0;i<10;i++)
  {
    for(int o=0;o<10;o++)
    {
      board[i][o] = 0;
    }
  }
  result = 0;
  return;
}

int main()
{
  int u;
  std::cin >> u;
  for(int p=0;p<u;p++)
  {
    std::cin >> piece >> m >> n;
    if(piece == 'Q')
    {
      /*
      int saveres = 0;
      for(int i=0;i<n;i++)
      {
        while(tryQ(0, i, board)){};
        saveres = std::max(result, saveres);
        reset_board();
      }

      result = saveres;
      */
      result = std::min(m, n);
    }
    else
    {
      while(tryall()){};
    }
    std::cout << result << '\n';
    reset_board();
  }
  return 0;
}
