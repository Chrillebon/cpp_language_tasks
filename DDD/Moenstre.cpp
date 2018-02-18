#include <iostream>
#include <vector>

int N;

int test90(std::vector< std::vector<int> > Start, std::vector< std::vector<int> > Goal)
{
  /*
  0 0 -> 3 0
  0 3 -> 0 0
  1 0 -> 3 1
  2 2 -> 1 2

  x y -> N-y x
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[N-i-1][o])
      {
        return 0;
      }
    }
  }
  return 1;
}

int test180(std::vector< std::vector<int> > Start, std::vector< std::vector<int> > Goal)
{
  /*
  0 0 -> 3 3
  0 3 -> 3 0
  1 0 -> 2 3
  2 2 -> 1 2

  x y -> N-x N-y
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[N-o-1][N-i-1])
      {
        return 0;
      }
    }
  }
  return 2;
}

int test270(std::vector< std::vector<int> > Start, std::vector< std::vector<int> > Goal)
{
  /*
  0 0 -> 0 3
  0 3 -> 0 0
  1 0 -> 0 2
  2 2 -> 2 1

  x y -> y N-x
  */
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[i][N-o-1])
      {
        return 0;
      }
    }
  }
  return 3;
}

int testequal(std::vector< std::vector<int> > Start, std::vector< std::vector<int> > Goal)
{
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      if(Start[o][i] != Goal[o][i])
      {
        return 0;
      }
    }
  }
  return 6;
}

int main()
{
  std::cin >> N;
  std::vector< std::vector<int> > Board1(N, std::vector<int> (N) );
  std::vector< std::vector<int> > Board2(N, std::vector<int> (N) );
  //Første mønster
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      std::cin >> Board1[o][i];
    }
  }
  //Andet mønster
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      std::cin >> Board2[o][i];
    }
  }
  //begynder test:
  if(test90(Board1, Board2))
  {
    std::cout << 1 << '\n';
    return 0;
  }
  if(test180(Board1, Board2))
  {
    std::cout << 2 << '\n';
    return 0;
  }
  if(test270(Board1, Board2))
  {
    std::cout << 3 << '\n';
    return 0;
  }
  if(testequal(Board1, Board2))
  {
    std::cout << 6 << '\n';
    return 0;
  }
  //Hvis ikke, så er der måske spejlet:
  //Laver ny plade der er spejlet:
  std::vector< std::vector<int> > Board3(N, std::vector<int> (N) );
  //Første mønster
  for(int i=0; i<N; i++)
  {
    for(int o=0; o<N; o++)
    {
      Board3[o][i] = Board1[N-o-1][i];
    }
  }
  //Så tester jeg videre
  if(testequal(Board3, Board2))
  {
    std::cout << 4 << '\n';
    return 0;
  }
  if(test90(Board3, Board2))
  {
    std::cout << 5 << '\n';
    return 0;
  }
  if(test180(Board3, Board2))
  {
    std::cout << 5 << '\n';
    return 0;
  }
  if(test270(Board3, Board2))
  {
    std::cout << 5 << '\n';
    return 0;
  }
  //Hvis ikke, så har det været en ulovlig transformation!
  std::cout << 7 << '\n';
  return 0;
}
