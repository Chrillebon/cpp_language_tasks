#include <deque>
#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

stack<int> deck;

void restart()
{
  for(int i=10006;i>=0;i--)
  {
    deck.push(i);
  }
  return;
}

int find_year()
{
  for(int i=0;i<10007;i++)
  {
    if(deck.top() == 2019)
    {
      return i;
    }
    else
    {
      deck.pop();
    }
  }
  return -1;
}

void deal()
{
  stack<int> n;
  for(int i=0;i<10007;i++)
  {
    n.push(deck.top());
    deck.pop();
  }
  deck.swap(n);
  return;
}

void cut(int m)
{
  stack<int> tmp;
  stack<int> n;
  if(m > 0)
  {
    for(int i=0;i<m;i++) //Alt der skal cuttes over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(int i=0;i<m;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    int s = deck.size();
    for(int i=0;i<s;i++) //Resten over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(int i=0;i<s;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    deck.swap(n);
  }
  else if(m < 0)
  {
    for(int i=0;i<10007+m;i++) //Alt pånær det der skal cuttes over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(int i=0;i<10007+m;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    int s = deck.size();
    for(int i=0;i<s;i++) //Resten over i tmp (vender forkert)
    {
      tmp.push(deck.top());
      deck.pop();
    }
    for(int i=0;i<s;i++) //Fra tmp til new
    {
      n.push(tmp.top());
      tmp.pop();
    }
    deck.swap(n);
  }
  return;
}

void increment(int m)
{
  vector<int> n(10007);
  int s = deck.size();
  for(int i=0;i<10007;i++)
  {
    n[(m*i) % 10007] = deck.top();
    deck.pop();
  }
  for(int i=10006;i>=0;i--)
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
    int n = 0;
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
  std::cout << "2019 er på plads: " <<find_year()<< '\n';
  return 0;
}
