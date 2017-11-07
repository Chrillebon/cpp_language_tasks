#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
  char decoy[30];
  long digits;
  int MAX = 5286;
  ofstream outfile;
  outfile.open("5000_primes_lenght.txt");
  for(int i=0;i<MAX;i++)
  {
    scanf("%5s %29s %li %29[-0-9a-zA-Z? ]", , , &digits, );
    if(! digits > 0)
    {
      MAX++;
      continue;
    }
    //std::cout << digits <<", ";
    outfile << digits <<", ";
  }
  outfile.close();
  return 0;
}
