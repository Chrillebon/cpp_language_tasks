#include <iostream>
#include <vector>
using namespace std;

int m,n,b,x;


int main()
{
  while(std::cin >> m)
  {
    std::cin >> n;
    vector<vector<pair<int,int>>> matrix(n, vector<pair<int,int>>());
    for(int i=0;i<m;i++)
    {
      std::cin >> b;
      int pos[b];
      for(int o=0;o<b;o++)
      {
        std::cin >> pos[o];
      }
      for(int o=0;o<b;o++)
      {
        std::cin >> x;
        matrix[pos[o]-1].push_back(make_pair(i, x));
      }
    }

    //output
    std::cout << n <<" "<< m <<'\n';
    for(int i=0;i<matrix.size();i++)
    {
      if(matrix[i].size())
      {
        std::cout << matrix[i].size() << " ";
        for(int o=0;o<matrix[i].size();o++)
        {
          std::cout << matrix[i][o].first+1 << " ";
        }
        std::cout << '\n';
        for(int o=0;o<matrix[i].size();o++)
        {
          std::cout << matrix[i][o].second << " ";
        }
      }
      else
      {
        std::cout << "0" << '\n';
      }
      std::cout << '\n';
    }
  }
  return 0;
}
