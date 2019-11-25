#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
using namespace std;

int n, k, tmp, res;
string word;

map<string, vector<int>> items;
vector<int> way;

vector<string> bag;

void rec1(int depth, int store)
{
  if(depth >= bag.size())
  {
    res++;
    return;
  }
  if(res >= 1 || depth >= bag.size() || store > n)
  {
    return;
  }
  for(int i=0;i<items.at(bag[depth]).size();i++)
  {
    //std::cout <<"test: "<< items.at(l.front())[i] << " og "<< l.front()<<" og "<< store<< '\n';
    if(store == items.at(bag[depth])[i]) //der skal udforskes 2 grene:
    {
      way[depth] = store;
      rec1(depth+1, store);
      return;
    }
  }
  rec1(depth, store+1);
  return;
}

void rec2(int depth, int store, int ekstra)
{
  if(depth < 0)
  {
    if(ekstra)
    {
      res++;
    }
    return;
  }
  if(res >= 2 || depth < 0 || store < 0)
  {
    return;
  }
  for(int i=items.at(bag[depth]).size()-1;i>=0;i--)
  {
    //std::cout <<"test: "<< items.at(l.front())[i] << " og "<< l.front()<<" og "<< store<< '\n';
    if(store == items.at(bag[depth])[i]) //der skal udforskes 2 grene:
    {
      if(way[depth] != store)
      {
        ekstra++;
      }
      rec2(depth-1, store, ekstra);
      return;
    }
  }
  rec2(depth, store-1, ekstra);
  return;
}

int main()
{
  std::cin >> n >> k;
  for(int i=0;i<k;i++)
  {
    int tmp;
    std::cin >> tmp;
    std::cin >> word;
    if(items.count(word))//tilføjer butikken til dem der har varen
    {
      items.at(word).push_back(tmp);
    }
    else //tilføj ny vare til listen
    {
      items.insert(pair<string, vector<int>>(word, {tmp}));
    }
  }
  std::cin >> k;
  bag.resize(k);
  way.resize(k);
  for(int i=0;i<k;i++)
  {
    std::cin >> bag[i];
  }
  rec1(0, 0);
  if(res)
  {
    rec2(k-1, n-1, 0);
  }
  if(res == 0)
  {
    std::cout << "impossible" << '\n';
  }
  if(res == 1)
  {
    std::cout << "unique" << '\n';
  }
  if(res >= 2)
  {
    std::cout << "ambiguous" << '\n';
  }
  return 0;
}
