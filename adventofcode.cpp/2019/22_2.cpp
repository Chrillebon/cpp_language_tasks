#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

ofstream fout ("22_x.txt");

stack<long long> deck;
vector<long long> final;

void restart()
{
  for(long long i=119315717514046;i>=0;i--)
  {
    deck.push(i);
  }
  return;
}

long long went(long long id)
{
  for(long long i=0;i<119315717514047;i++)
  {
    if(final[i] == id)
    {
      return i;
    }
  }
  return -1;
}

void deal()
{
  stack<long long> n;
  for(long long i=0;i<119315717514047;i++)
  {
    n.push(deck.top());
    deck.pop();
  }
  deck.swap(n);
  return;
}

void cut(long long m)
{
  stack<long long> tmp;
  stack<long long> n;
  if(m > 0)
  {
    for(long long i=0;i<m;i++) //Alt der skal cuttes over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(long long i=0;i<m;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    long long s = deck.size();
    for(long long i=0;i<s;i++) //Resten over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(long long i=0;i<s;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    deck.swap(n);
  }
  else if(m < 0)
  {
    for(long long i=0;i<119315717514047+m;i++) //Alt pånær det der skal cuttes over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(long long i=0;i<119315717514047+m;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    long long s = deck.size();
    for(long long i=0;i<s;i++) //Resten over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(long long i=0;i<s;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    deck.swap(n);
  }
  return;
}

void increment(long long m)
{
  vector<long long> n(119315717514047);
  long long s = deck.size();
  for(long long i=0;i<119315717514047;i++)
  {
    n[(m*i) % 119315717514047] = deck.top();
    deck.pop();
  }
  for(long long i=119315717514046;i>=0;i--)
  {
    deck.push(n[i]);
  }
  return;
}

int main()
{
  string word;
  restart();
  while(std::cin >> word)
  {
    long long n = 0;
    if(word == "cut")
    {
      std::cin >> n;
      cut(n);
    }
    else if(word == "deal")
    {
      std::cin >> word;
      {
        if(word == "with")
        {
          std::cin >> word; //increment
          std::cin >> n;
          increment(n);
        }
        else if(word == "into")
        {
          std::cin >> word;
          std::cin >> word; //to ord jeg ikke skal bruge...
          deal();
        }
      }
    }
  }
  for(long long i=0;i<119315717514047;i++)
  {
    final.push_back(deck.top());
    deck.pop();
  }
  for(long long i=0;i<119315717514047;i++)
  {
    fout << went(i) <<", ";
  }
  std::cout << "done!" << '\n';
  return 0;
}

/*

efter gang:
1: 2916
2: 4293
3: 5202
4: 7568
5: 758
6: 4896
7: 7366
8: 2456
9:
*/
