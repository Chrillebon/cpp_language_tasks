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

/*
ifstream fin ("castle.in");
ofstream fout ("castle.out");
*/

struct comp{
  bool operator() (pair<pair<int, int>, pair<int, int>> a, pair<pair<int, int>, pair<int, int>> b)
  {
    if(a.first.first == b.first.first)
    {
      if(a.first.second == b.first.second) //If starting point are identical
      {
        return a.second.second > b.second.second; //take room N before E
      }
      else
      {
        return a.first.second < b.first.second; //Furthest south, if X-coor is tied
      }
    }
    else
    {
      return a.first.first > b.first.first; //Furthest west
    }
  }
};

int M, N;
int map[50][50][2]{};
int rooms = 0;
int listwalls[5000][4]{}; //[x]{y][Dir][NewSize]
int thewall[4]; //[x]{y][Dir][NewSize]
int Biggest = 0, CurrentSize = 0;

priority_queue<pair<pair<int, int>, pair<int, int>>, vector<pair<pair<int, int>, pair<int,int>>>, comp> cross;
//Xfirst, Yfirst, Xsecond, Ysecond
//First room is west/southmost
queue<pair<int, int>> q;

void move(int x, int y)
{
  q.pop();
  if(map[x][y][1] == 1) //has been visited before?
  {
    return;
  }
  CurrentSize++; //Increase size of current room
  map[x][y][1] = 1; //Marked, now visited
  //move north -------------------------------------------------
  if(map[x][y][0] % 4 >= 2 && y > 0) //if wall north (not outer)
  {
    cross.push(make_pair(make_pair(x, y), make_pair(x, y-1)));
  }
  else if(y > 0) //not outer
  {
    q.push(make_pair(x, y-1));
  }
  //move east ---------------------------------------------------
  if(map[x][y][0] % 8 >= 4 && x < M-1) //if wall east (not outer)
  {
    cross.push(make_pair(make_pair(x, y), make_pair(x+1, y)));
  }
  else if(x < M-1) //not outer
  {
    q.push(make_pair(x+1, y));
  }
  //move south -----------------------------------------------
  if(map[x][y][0] >= 8 && y < N-1) //if wall south (not outer)
  {
    //Should not cross south
    //cross.push(make_pair(make_pair(x, y), make_pair(x, y+1)));
  }
  else if(y < N-1) // not outer
  {
    q.push(make_pair(x, y+1));
  }
  //move west -------------------------------------------------
  if(map[x][y][0] % 2 == 1 && x > 0) //if wall west (not outer)
  {
    //Should not cross west
    //cross.push(make_pair(make_pair(x, y), make_pair(x-1, y)));
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
  cin >> M >> N;
  for(int i=0;i<N;i++)
  {
    for(int o=0;o<M;o++)
    {
      cin >> map[o][i][0];
    }
  }
  //------------
  cross.push(make_pair(make_pair(0, N-1), make_pair(0,N-1))); //Starting point
  while(!cross.empty()) //All rooms
  {
    /*
    //-------------debug---------------
    //Find coordinates for where we are heading:
    for(int i=0;i<N;i++)
    {
      for(int o=0;o<M;o++)
      {
        if(i == cross.top().first.second && o == cross.top().first.first)
        {
          std::cerr << "S" << ' ';
        }
        else if(i == cross.top().second.second && o == cross.top().second.first)
        {
          std::cerr << "X" << ' ';
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
    q.push(make_pair(cross.top().second.first, cross.top().second.second)); //Moving from long to short "memory"
    if(map[q.front().first][q.front().second][1] == 0) //if unvisited
    {
      listwalls[rooms][3] += CurrentSize; // Increasing size of last room
      rooms++; //a new room!
      listwalls[rooms][3] += CurrentSize; // Increasing size of next room
      listwalls[rooms][0] = cross.top().first.first; // x of first room
      listwalls[rooms][1] = cross.top().first.second; // y of first room
      if(cross.top().first.first == cross.top().second.first) //If they have the same x-coor, then the wall is north reletive to the first room
      {
        listwalls[rooms][2] = 0; // 0 = N
      }
      else
      {
        listwalls[rooms][2] = 1; // 1 = E
      }
      CurrentSize = 0; //reset
    }
    cross.pop(); //w8 popping till wall is listed ^^
    while(!q.empty()) //Entire room
    {
      move(q.front().first, q.front().second);
    }
    Biggest = fmax(Biggest, CurrentSize); //Update biggest room
  }
  listwalls[rooms][3] += CurrentSize; // Increasing size of the combined room for the last wall crossing
  cout <<rooms<< '\n'; //Number of rooms
  cout <<Biggest<< '\n'; //Biggest room
  for(int i=2;i<5000;i++)
  {
    if(listwalls[i][3] > thewall[3])
    {
      thewall[0] = listwalls[i][0];
      thewall[1] = listwalls[i][1];
      thewall[2] = listwalls[i][2];
      thewall[3] = listwalls[i][3];
    }
  }
  cout << thewall[3]<< '\n'; // Size of new room
  cout << thewall[1]+1<<" "<<thewall[0]+1<<" "; // Location of new room: y+1, x+1
  if(thewall[2] == 0)
  {
    cout << "N" << '\n';
  }
  else
  {
    cout << "E" << '\n';
  }
  //-------------debug---------------
  //Find coordinates for where we are heading:
  /*
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
