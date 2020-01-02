#include <iostream>
#include <vector>
using namespace std;

vector<int> base{0,1,0,-1};
vector<int> input;

void phase()
{
  int tmp;
  vector<int> prog = input;
  for(int i=0;i<input.size();i++)
  {
    tmp = 0;
    for(int o=0;o<input.size();o++)
    {
      tmp += input[o]*base[((o+1)/(i+1)) % 4];
    }
    if(tmp < 0)
    {
      tmp *= -1;
    }
    prog[i] = tmp % 10;
  }

  for(int i=0;i<input.size();i++)
  {
    input[i] = prog[i];
  }
  return;
}

int main()
{
  int tmp;
  while(scanf("%1d", &tmp))
  {
    input.push_back(tmp);
  }
  std::cout << "test: " <<input.size()<< '\n';
  for(int i=0;i<100;i++)
  {
    phase();
  }
  std::cout << "After "<< 100 << " phases: ";
  for(int o=0;o<8;o++)
  {
    std::cout << input[o];
  }
  std::cout << '\n';
  return 0;
}
