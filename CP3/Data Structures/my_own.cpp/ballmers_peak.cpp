#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int n,k;

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
    members = size;
    int height = ceil(log2(size)); //Højden af træet
    total = 2*pow(2, height) - 1; //max størrelsen af træet
    t.resize(total);
  }


  void update(int i, int pos, int val, int left, int right) //back end    input er (1, pos, val, 0, size-1)
  {
    if(pos == left && pos == right)
    {
      if(val == 0)
      {
        t[i] = 0;
      }
      else if(val>>31) //val er negativ
      {
        t[i] = -1;
      }
      else //val er positiv og forskellig fra 0
      {
        t[i] = 1;
      }
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
      t[i] = t[(i<<1)] * t[(i<<1)+1];
    }
  }

  void insert(int pos, int val) //front end
  {
    return update(1, pos, val, 0, members-1);
  }

  int resl(int i, int start, int end, int left, int right)
  {
    //std::cout << "test" << '\n';
    if(left >= start && right <= end) // Jeg har svaret der hvor jeg står
    {
      //std::cout << "alpha" << left << " "<< start<< " "<< right<<" "<< end <<'\n';
      return t[i];
    }
    else if(left > end || right < start) //stop denne gren med det samme!
    {
      return 1;
    }
    else //Prøv begge veje
    {
      //std::cout << "beta" << left << " "<< start<< " "<< right<<" "<< end <<'\n';
      int val1,val2;
      //resultatet af begge grene
      val1 = resl((i<<1), start, end, left, (left+right)/2);
      val2 = resl((i<<1)+1, start, end, (left+right)/2+1, right);
      if(val1 == 0 || val2 == 0)
      {
        return 0;
      }
      else if((val1>>31) == (val2>>31)) //Hvis de har ens fortegn (plus/minus) som er den første bit i init
      {
        return 1;
      }
      else
      {
        return -1;
      }
    }
  }

  int result(int start, int end)
  {
    return resl(1, start, end, 0, members-1);
  }
};

int main()
{
  char tmp;
  int pos, val, start, end;
  tree seq;
  while(std::cin >> n)
  {
    std::cin >> k;
    seq.init(n);
    for(int i=0;i<n;i++)
    {
      std::cin >> val;
      seq.insert(i, val);
    }
    for(int i=0;i<k;i++)
    {
      std::cin >> tmp;
      if(tmp == 'C')
      {
        std::cin >> pos >> val;
        seq.insert(pos-1, val);
      }
      if(tmp == 'P')
      {
        std::cin >> start >> end;
        val = seq.result(start-1, end-1);
        if(val == 0)
        {
          std::cout << "0";
        }
        else if(val > 0)
        {
          std::cout << "+";
        }
        else
        {
          std::cout << "-";
        }
      }
    }
    std::cout << '\n';
  }
  return 0;
}
