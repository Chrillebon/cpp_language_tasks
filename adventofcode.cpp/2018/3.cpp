#include <iostream>

/*int main()
{
  int number = 368078, steps=0, max=0, edge=0, i, diff,n=0;//368078;
  for(i=1;max<number;i+=2)
  {
    edge = (i*i)-max;
    max += (i*i)-max;
    n++;
  }
  n--;

  diff = max - number;
  edge /= 8;

  while(max-edge>=number && diff)
  {
    steps ++;
    max -= edge;
    diff -= edge;
  }

  std::cout << "max: " <<max<<" og "<<n<<" og "<<edge<<" og "<<steps<< '\n';

  if(max == number)
  {
    if(steps % 2)
    {
      std::cout << "Antallet af steps er: " <<n<< '\n';
    }
    else
    {
      std::cout << "Antallet af steps er: " <<n+edge<< '\n';
    }
  }

  if(diff>edge/2)
  {
    max -= edge;
    diff = number - max;
  }

  if(steps % 2)
  {
    std::cout << "Antallet af steps er: " <<n+diff<< '\n';
  }
  else
  {
    std::cout << "Antallet af steps er: " <<n+edge-diff<< '\n';
  }

  //std::cout << "max: " <<max<<" og "<<i<<" og "<<edge<< '\n';
  return 0;
}*/
int xy[21][21]{};
int placecounter=1, layer=1,dir=0, x=11, y=11, number = 368078;

addall()
{
  //std::cout << "den kører med hvad??? " <<xy[x][y]<<" og "<<x<<" og "<<y<< '\n';
  for(int i=0;i<3;i++)
  {
    for(int o=0;o<3;o++)
    {
      if(!(o==1 and i==1))
      {
        xy[x-1+i][y-1+o] += xy[x][y];
      }
    }
  }
}

goturn()
{
  if(dir == 0)
  {
    dir++;
    addall();
    xy[x][y] -= 99999999;
    x++;
  }
  else if(dir == 1)
  {
    dir++;
    addall();
    xy[x][y] -= 99999999;
    y++;
  }
  else if(dir == 2)
  {
    dir++;
    addall();
    xy[x][y] -= 99999999;
    x--;
  }
  else if(dir == 3)
  {
    dir++;
    addall();
    xy[x][y] -= 99999999;
    y--;
  }
  if(dir>3) dir = 0;
}

go()
{
  if(dir == 0)
  {
    addall();
    xy[x][y] -= 99999999;
    x++;
  }
  else if(dir == 1)
  {
    addall();
    xy[x][y] -= 99999999;
    y++;
  }
  else if(dir == 2)
  {
    addall();
    xy[x][y] -= 99999999;
    x--;
  }
  else if(dir == 3)
  {
    addall();
    xy[x][y] -= 99999999;
    y--;
  }
}

int main()
{
  xy[11][11]=1;
  while(1)
  {
    for(int i=0;i<abs(placecounter)-1;i++)
    {
      std::cout << "den kører med hvad? " <<xy[x][y]<<" og "<<x<<" og "<<y<< '\n';
      go();
      if(xy[x][y]>number)
      {
        std::cout << "Number: " <<xy[x][y]<< '\n';
        return 0;
      }
    }
    if(placecounter>0)
    {
      std::cout << "den kører med hvad? " <<xy[x][y]<<" og "<<x<<" og "<<y<<" og "<< placecounter<< '\n';
      goturn();
      if(xy[x][y]>number)
      {
        std::cout << "Number: " <<xy[x][y]<< '\n';
        return 0;
      }
      placecounter *= -1;
    }
    else
    {
      std::cout << "den kører med hvad? " <<xy[x][y]<<" og "<<x<<" og "<<y<< '\n';
      goturn();
      if(xy[x][y]>number)
      {
        std::cout << "Number: " <<xy[x][y]<< '\n';
        return 0;
      }
      placecounter *= -1;
      placecounter++;
    }
  }
  return 0;
}
