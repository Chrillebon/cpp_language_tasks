#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<int> base{0,1,0,-1};
vector<int> input;
vector<int> full(4550); //7 gange input's størrelse
int skip = 0;

void phase()
{
  int tmp, end;
  vector<int> prog = full;
  for(int i=0;i<full.size();i++)
  {
    tmp = 0;
    end = 0;
    for(int o=0;o<full.size();o++)//Kun 7 gange (full.size()), da den looper derefter, og så kan jeg gange op til sidst
    {
      tmp += full[o]*base[((o+1)/(i+1)) % 4];
      if(o < full.size()*4)
      {
        end += full[o]*base[((o+1)/(i+1)) % 4];
      }
    }
    if(tmp < 0)
    {
      tmp *= -1;
    }
    if(end < 0)
    {
      end *= -1;
    }
    tmp *= 1428; //Antallet af gange input*7 optræder i den fulde længde
    tmp += end; //De sidste 2600 tal
    prog[i] = tmp % 10;
  }

  for(int i=0;i<full.size();i++)
  {
    full[i] = prog[i];
  }
  return;
}

void upscale()
{
  for(int i=0;i<7;i++)
  {
    for(int o=0;o<input.size();o++)
    {
      full[i*input.size()+o] = input[o];
    }
  }
  return;
}

int offset()
{
  int res = 0;
  for(int i=0;i<7;i++)
  {
    res+=full[i]*pow(10,6-i);
  }
  return res;
}

int main()
{
  int tmp;
  while(scanf("%1d", &tmp))
  {
    input.push_back(tmp);
  }
  upscale();
  skip = offset();
  //std::cout << "test: " <<full.size()<< '\n';
  for(int i=0;i<100;i++)
  {
    std::cout << "@ " <<i<< '\n';
    phase();
  }
  std::cout << "After "<< 100 << " phases: ";
  for(int o=0;o<8;o++)
  {
    std::cout << full[skip % 4550 + o]; //De tal jeg skal skippe til optræder også i den stræng jeg har nu
  }
  std::cout << '\n';
  return 0;
}

//Under 53190043
