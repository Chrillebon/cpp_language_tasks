#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ofstream fout ("output.txt");
vector<int> list;
int tmp;

int main()
{
  while(std::cin >> tmp)
  {
    list.push_back(tmp);
  }
  for(int i=0;i<list.size();i++)
  {
    fout << list[i] <<", ";
  }
}
