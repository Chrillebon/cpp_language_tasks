#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, start, v1, v2;
vector<int> num;

class tree
{
public:
  vector<int> t;
  int members, total;

  void print(int i)
  {
    std::cout << t[i+1] << '\n';
  }

  void init(int size)
  {
    t.clear();
    t.resize(size);
    members = size;
  }


  void update(int i, int pos, int val, int left, int right) //back end    input er (1, pos, val, 0, size-1)
  {
    if(pos == (left+right)/2)
    {
      t[i] = val;
      return;
    }
    else if(pos > right || pos < left)
    {
      return;
    }
    else
    {
      update((i<<1), pos, val, left, (left+right)/2); //go left, index double
      update((i<<1)+1, pos, val, (left+right)/2+1, right); //go right, index double+1
    }
  }

  void insert(int pos, int val) //front end
  {
    return update(1, pos, val, 0, members-1);
  }

  int resl(int i, int start, int end, int left, int right)
  {
    if(left > start || right < end) //stop denne gren med det samme!
    {
      return 0;
    }
    else //Prøv begge veje
    {
      std::cout << "members: " <<members<< '\n';
      std::cout << "beta" << num[left] << " "<< start<< " "<< num[right]<<" "<< end <<'\n';
      int val1,val2;
      //resultatet af begge grene
      val1 = resl((i<<1), start, end, left, (left+right)/2);
      val2 = resl((i<<1)+1, start, end, (left+right)/2+1, right);
      if(val1 == 0 || val2 == 0) //No lower now
      {
        return i;
      }
      else //Go lower
      {
        return val1+val2;
      }

    }
  }

  int result(int start, int end)
  {
    return resl(1, start, end, 0, members-1);
  }
};

int find(int i, int val1, int val2, int left, int right)
{
  if(right < val2 || left > val1) //out of bounds or too close
  {
    return 0;
  }
  //Trying both paths down:
  int idleft, idright;
  idleft = find((i<<1), val1, val2, left, (left+right)/2); //go left
  idright = find((i<<1)+1, val1, val2, (left+right)/2+1, right); //go right
  if(idleft == 0 && idright == 0)
  {
    return i;
  }
}

int main()
{
  std::cin >> n;
  num.resize(n);
  for(int i=0;i<n;i++)
  {
    std::cin >> num[i];
  }
  sort(num.begin(),num.end());
  tree l;
  l.init(n);
  for(int i=0;i<num.size();i++)
  {
    l.insert(i, num[i]);
  }
  start = n/2;
  std::cin >> v1 >> v2;
  for(int i=0;i<n;i++)
  {
    l.print(i);
  }
  std::cout << "test: " << l.resl(start, v1, v2, 0, num[n-1])<<'\n'; //Finding and printing it
  return 0;
}

/*
8
1 2 3 4 5 6 7 8
2 4

*/
