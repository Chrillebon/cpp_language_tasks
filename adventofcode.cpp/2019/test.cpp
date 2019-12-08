#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <string>
using namespace std;

map<string,pair<int,vector<string>>> test;

int main()
{
  string a = "abc";
  test[a] = pair<int, vector<string>> (1,vector<string>());
  return 0;
}
