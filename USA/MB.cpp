//A quick calculator for all things related to money and banking
#include <iostream>
#include <math.h>
#include <cstdlib>
#include "Intro.h"
#include "PV.h"
#include "Real.h"

float FPFPS()
{
  int n;
  float result = 0;
  std::cout << "Please enter the amount times that you are to repay over:" << '\n';
  std::cin >> n;
  float fam, i;
  std::cout << "Please enter the final amount"<<'\n';
  std::cin >> fam;
  std::cout << "Please enter the interest rate [percent]" << '\n';
  std::cin >> i;
  i/=100;
  result = fam*i/(1-pow(1/(1+i),n));
  return result;
}

float FPCB()
{
  std::cout << "WARNING!!!! THIS SINGLE FEATURE HAS NOT BEEN TESTED AT ALL..." << '\n';
  int n;
  float result = 0;
  std::cout << "Please enter the amount of payments:" << '\n';
  std::cin >> n;
  float fam, i, fv;
  std::cout << "Please enter the final amount"<<'\n';
  std::cin >> fam;
  std::cout << "Please enter the face value" << '\n';
  std::cin >> fv;
  std::cout << "Please enter the interest rate [percent]" << '\n';
  std::cin >> i;
  i/=100;
  for(int o=0;o<n;o++) //The dividens
  {
    result+=fam*pow((1.0+i),o+1);
    std::cout << "This part is equal to: "<< fam/pow((1.0+i),o+1) << '\n';
  }
  //The return of face value
  result-=fv/pow((1.0+i),n);
  return result;
}

int FP()
{
  std::cout << "This calculator is now used to calculate the Future payments" << '\n';
  std::cout << '\n';
  std::cout << "Please enter the type of security that you are dealing with:" << '\n';
  std::cout << "1: Fixed payment security" << '\n';
  std::cout << "2: Coupon bonds" << '\n';
  std::cout << "3: Perpertuity" << '\n';
  std::cout << "0: Exit" << '\n';
  int choice = 0;
  float result = 0;
  std::cin >> choice;
  if(choice == 1)
  {
    result = FPFPS();
  }
  else if(choice == 0)
  {
    std::cout << "Thank you for using this M&B calculator!" << '\n';
    std::exit(EXIT_SUCCESS);
  }
  else
  {
    std::cout << "ERROR" << '\n';
    std::cout << "This feature might not be fully developped yet..." << '\n';
    std::cout << "Please try again" << '\n';
    FP();
    return 0;
  }
  std::cout << "The Future payment is:" << '\n';
  std::cout << result << '\n';
  return 0;
}

void Option()
{
  int choice = 0;
  std::cout << "What do you want to calculate?" << '\n';
  std::cout << "1: Present value" << '\n';
  std::cout << "2: Future payments" << '\n';
  std::cout << "3: Returns" << '\n';
  std::cout << "4: Real investments & tax" << '\n';
  std::cout << "0: Exit" << '\n';
  std::cin >> choice;
  if(choice == 1)
  {
    PV();
  }
  else if(choice == 2)
  {
    FP();
  }
  else if(choice == 4)
  {
    Real();
  }
  else if(choice == 0)
  {
    std::cout << "Thanks for using this M&B calculator" << '\n';
    std::exit(EXIT_SUCCESS);
  }
  else
  {
    std::cout << "ERROR - this feature might not be developed yet..." << '\n';
    std::cout << "Please try again" << '\n';
    Option();
  }
  return;
}

int main()
{
  introtext();
  Option();
  return 0;
}
