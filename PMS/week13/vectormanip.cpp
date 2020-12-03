#include <iostream>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

// make
// ./vectormanip nums.txt

double mean(const vector<double>& a)
{
  double meanval = 0;
  for(unsigned long i=0;i<a.size();i++)
  {
    meanval += a[i];
  }
  return meanval/a.size();
}

int main(int arg, const char *argv[])
{
  vector<double> vals;
  double tmp;
  ifstream readme (argv[1]);
  std::cout << "testing: " << readme.is_open()<<" med "<<argv[0]<<'\n';
  fprintf(readme, "%lf", tmp)
  while(readme >> tmp)
  {
    printf("%lf\n", tmp);
    vals.push_back(tmp);
  }
  /*FILE * fp;
  fp = fopen(argv[1],"r");
  while(fscanf(fp,"%lf",&tmp))
  {
    std::cout << "testing: " <<tmp<< '\n';
    vals.push_back(tmp);
  }*/
  printf("size: %lu\n", vals.size());
  printf("capacity: %lu\n", vals.capacity());
  // når den løber ud, fordobler den capacity osv...
  printf("meanvalue: %f\n", mean(vals));
  return 0;
}
