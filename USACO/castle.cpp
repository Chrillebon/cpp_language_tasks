/*
ID: Christi69
PROB: castle
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


ifstream fin ("castle.in");
ofstream fout ("castle.out");

int M, N;
int map[50][50][2]{};
int roomsize[2500]{};
int rooms = 0;
int thewall[4]; //[x]{y][Dir][NewSize]
int Biggest = 0, CurrentSize = 0;

queue<pair<int, int>> cross;
//First room is west/southmost
queue<pair<int, int>> q;

void move(int x, int y)
{
  q.pop();
  if(map[x][y][1] != 0) //has been visited before?
  {
    return;
  }
  CurrentSize++; //Increase size of current room
  map[x][y][1] = rooms; //Marked, now visited
  //move north -------------------------------------------------
  if(map[x][y][0] % 4 >= 2 && y > 0) //if wall north (not outer)
  {
    cross.push(make_pair(x, y-1));
  }
  else if(y > 0) //not outer
  {
    q.push(make_pair(x, y-1));
  }
  //move east ---------------------------------------------------
  if(map[x][y][0] % 8 >= 4 && x < M-1) //if wall east (not outer)
  {
    cross.push(make_pair(x+1, y));
  }
  else if(x < M-1) //not outer
  {
    q.push(make_pair(x+1, y));
  }
  //move south -----------------------------------------------
  if(map[x][y][0] >= 8 && y < N-1) //if wall south (not outer)
  {
    //If it crosses south, then the wall should be built the other way, reversing first and second.
    cross.push(make_pair(x, y+1));
  }
  else if(y < N-1) // not outer
  {
    q.push(make_pair(x, y+1));
  }
  //move west -------------------------------------------------
  if(map[x][y][0] % 2 == 1 && x > 0) //if wall west (not outer)
  {
    //If it crosses west, then the wall should be built the other way, reversing first and second.
    cross.push(make_pair(x-1, y));
  }
  else if(x > 0) // not outer
  {
    q.push(make_pair(x-1, y));
  }
  return;
}

int main()
{
  //input:
  fin >> M >> N;
  for(int i=0;i<N;i++)
  {
    for(int o=0;o<M;o++)
    {
      fin >> map[o][i][0];
    }
  }
  //------------
  cross.push(make_pair(0,N-1)); //Starting point
  while(!cross.empty()) //All rooms
  {
    /*
    //-------------debug---------------
    //Find coordinates for where we are heading:
    for(int i=0;i<N;i++)
    {
      for(int o=0;o<M;o++)
      {
        if(i == cross.front().second && o == cross.front().first)
        {
          std::cerr << "S" << ' ';
        }
        else
        {
          cerr << map[o][i][1] << ' ';
        }
      }
      std::cout << '\n';
    }
    std::cout << '\n';

    //-------------debug---------------
    */
    q.push(make_pair(cross.front().first, cross.front().second)); //Moving from long to short "memory"
    if(map[q.front().first][q.front().second][1] == 0) //if unvisited
    {
      roomsize[rooms] = CurrentSize; //Save last roomsize
      rooms++; //a new room!
      CurrentSize = 0; //reset
    }
    cross.pop();
    while(!q.empty()) //Entire room
    {
      move(q.front().first, q.front().second);
    }
    Biggest = fmax(Biggest, CurrentSize); //Update biggest room
  }
  roomsize[rooms] = CurrentSize; //Save last roomsize
  //output--------------------------------------------------
  fout <<rooms<< '\n'; //Number of rooms
  fout <<Biggest<< '\n'; //Biggest room
  //Find best wall
  for(int o=0;o<M;o++) //Go through x-coordinates slower
  {
    for(int i=N-1;i>=0;i--) //Go through y-coordinates first
    {
      //north
      if(i!=0) //dont go out of bounds
      {
        if(map[o][i][1] != map[o][i-1][1]) //Different rooms
        {
          if(roomsize[map[o][i][1]]+roomsize[map[o][i-1][1]] > thewall[3]) //New bigger wall found
          {
            thewall[0] = o; // x
            thewall[1] = i; // y
            thewall[2] = 0; //north
            thewall[3] = roomsize[map[o][i][1]] + roomsize[map[o][i-1][1]]; //Size of the two rooms
          }
        }
      }
      //east
      if(o!=M-1) //dont go out of bounds
      {
        if(map[o][i][1] != map[o+1][i][1]) //Different rooms
        {
          if(roomsize[map[o][i][1]]+roomsize[map[o+1][i][1]] > thewall[3]) //New bigger wall found
          {
            thewall[0] = o; // x
            thewall[1] = i; // y
            thewall[2] = 1; //east
            thewall[3] = roomsize[map[o][i][1]] + roomsize[map[o+1][i][1]]; //Size of the two rooms
          }
        }
      }

    }
  }

  fout << thewall[3]<< '\n'; // Size of new room
  fout << thewall[1]+1<<" "<<thewall[0]+1<<" "; // Location of new room: y+1, x+1
  if(thewall[2] == 0)
  {
    fout << "N" << '\n';
  }
  else
  {
    fout << "E" << '\n';
  }
  /*
  //-------------debug---------------
  //Find coordinates for where we are heading:

  for(int i=0;i<N;i++)
  {
    for(int o=0;o<M;o++)
    {
      if(i == thewall[1] && o == thewall[0])
      {
        std::cerr << "S" << ' ';
      }
      else
      {
        cerr << map[o][i][1] << ' ';
      }
    }
    std::cout << '\n';
  }
  std::cout << '\n';

  //-------------debug---------------
*/
  return 0;
}

/*

What do I need:

Number of rooms
Size of largest rooms
Largest room by destoying a wall
Wall destroyable for largest room


Steps:
1.  Start in 1,N
2.  Move trough all uncounted Steps, north first then east
3.  Count size of room by adding 1 every step
4.  When encountering a wall:
place in memory/todo do cross wall w. priority through coordinates
5.  When room is counted:
refer to priority memory, if unvisited
save crossing, where and between what sizes
goto square
add 1 to number of rooms
6.  Goto step 2

*/


/*
TESTDATA:
#####
# | #
### #
# # #
#-###
# | #
#####

2 3
11 6
7 13
9 14
*/

/*
FAILING TEST DATA:

15 14
        11 14 3 6 3 6 3 6 3 6 3 6 11 2 6
        3 10 12 9 12 9 12 9 12 9 12 9 6 1 4
        13 7 11 10 10 10 10 10 10 14 11 6 5 1 4
        11 4 3 10 10 10 10 10 10 10 6 5 13 1 4
        7 13 5 7 11 10 2 10 14 7 5 13 7 9 12
        1 14 5 1 10 14 5 11 10 4 9 6 1 10 6
        13 7 5 5 3 10 8 10 6 5 3 12 9 10 12
        11 4 5 13 5 3 10 6 5 13 5 3 10 10 6
        7 13 1 10 4 1 10 4 1 10 4 5 3 10 12
        1 14 5 7 5 9 10 12 5 7 5 5 9 10 6
        13 7 13 5 9 10 2 10 12 13 13 5 3 10 12
        7 5 15 9 10 14 5 11 14 11 14 5 9 10 6
        5 13 7 7 11 10 8 10 14 7 3 12 3 10 12
        13 15 13 13 11 10 14 11 10 12 9 10 8 10 14

ANSWER:

27
55
85
11_11_E
*/
