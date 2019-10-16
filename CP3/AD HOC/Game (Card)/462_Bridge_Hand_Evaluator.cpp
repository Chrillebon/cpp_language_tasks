#include <iostream>

char suit[13][2];
int stopped[4];
int color[4];
int score[2];

void subtract(int col, int val, int depth)
{
  if(color[col] <= val)
  {
    score[0]--;
  }
  else if(val != 3)
  {
    stopped[suit[depth][1]] = 1;  //This color has been stopped
  }
  return;
}

void reset()
{
  score[0] = 0;
  score[1] = 0;
  color[0] = 0;
  color[1] = 0;
  color[2] = 0;
  color[3] = 0;
  stopped[0] = 0;
  stopped[1] = 0;
  stopped[2] = 0;
  stopped[3] = 0;
}

int max()
{
  int biggest = 0;
  int where = -1;
  for(int i=0;i<4;i++)
  {
    if(color[i]>biggest)
    {
      biggest = color[i];
      where = i;
    }
  }
  return where;
}

int main()
{
  int depth=0;
  char temp;
  while(std::cin >> temp)
  {
    if(temp != ' ')
    {
      if(temp > 48 && temp <= 65 || temp > 72 && temp < 83 || temp == 'T') //A-K
      {
        suit[depth][0] = temp;
        // rule 1
        if(temp == 'A') //ace
        {
          score[0]+=4;
        }
        if(temp == 'K') //king
        {
          score[0]+=3;
        }
        if(temp == 'Q') //queen
        {
          score[0]+=2;
        }
        if(temp == 'J') //jack
        {
          score[0]+=1;
        }
      }
      else //color
      {
        if(temp == 'S')
        {
          color[0]++;
          suit[depth][1] = 0;
        }
        if(temp == 'H')
        {
          color[1]++;
          suit[depth][1] = 1;
        }
        if(temp == 'D')
        {
          color[2]++;
          suit[depth][1] = 2;
        }
        if(temp == 'C')
        {
          color[3]++;
          suit[depth][1] = 3;
        }
        depth++;
        if(depth >= 13)
        {
          depth = 0;
          //Time to run rules------
          for(int i=0;i<13;i++)
          {
            //stopping
            if(suit[i][0] == 'A')
            {
              stopped[suit[i][1]] = 1; //This color has been stopped
            }
            // rule 2:
            if(suit[i][0] == 'K')
            {
              subtract(suit[i][1], 1, i);
            }
            //rule 3:
            if(suit[i][0] == 'Q')
            {
              subtract(suit[i][1], 2, i);
            }
            //rule 4
            if(suit[i][0] == 'J')
            {
              subtract(suit[i][1], 3, i);
            }
          }
          score[1] = score[0]; //No-trump score
          //rule 5
          for(int i=0;i<4;i++)
          {
            if(color[i] == 2)
            {
              score[0]++;
            }
          }
          //rule 6/7
          for(int i=0;i<4;i++)
          {
            if(color[i] <= 1)
            {
              score[0]+=2;
            }
          }
          if(score[0] < 14)
          {
            std::cout << "PASS" << '\n';
          }
          else if(score[1] >= 16 && stopped[0] == 1 && stopped[1] == 1 && stopped[2] == 1 && stopped[3] == 1)
          {
            std::cout << "BID NO-TRUMP" << '\n';
          }
          else
          {
            if(max() == 0)
            {
              std::cout << "BID S" << '\n';
            }
            else if(max() == 1)
            {
              std::cout << "BID H" << '\n';
            }
            else if(max() == 2)
            {
              std::cout << "BID D" << '\n';
            }
            else if(max() == 3)
            {
              std::cout << "BID C" << '\n';
            }
          }
          //To here ---------------
          reset();
        }
      }
    }
  }
  return 0;

}


/*
test cases:
KH QC 5S 3S AS AD TD TS 9H AH 7S 8C 9D --- 19 17
JD QH 5S 7D 3S 5H 6S 9D AC 7S 3D 4D KH --- 12 10
*/
