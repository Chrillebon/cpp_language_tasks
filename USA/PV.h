float PVGP()
{
  int n;
  float result = 0;
  std::cout << "Please enter the amount of payments:" << '\n';
  std::cin >> n;
  int tim[n], mat;
  float amo[n], i[n];
  for(int o=0;o<n;o++)
  {
    std::cout << "Please enter this seperated by space: "<<'\n'<<" - The invested amount"<<'\n'<<" - At what time unit"<<'\n'<<" - At what interest [percent]" << '\n';
    std::cin >> amo[o] >> tim[o] >> i[o];
    i[o]/=100;
  }
  std::cout << "Please enter the units of time before maturity:" << '\n';
  std::cin >> mat;
  for(int o=0;o<n;o++)
  {
    result+=amo[o]/pow((1.0+i[o]),tim[o]);
    std::cout << "This part is equal to: "<< amo[o]/pow((1.0+i[o]),tim[o]) << '\n';
  }
  return result;
}

float PVFPS()
{
  int n;
  float result = 0;
  std::cout << "Please enter the amount times that you are to repay over:" << '\n';
  std::cin >> n;
  float amo, i;
  std::cout << "Please enter the repay amount"<<'\n';
  std::cin >> amo;
  std::cout << "Please enter the interest rate [percent]" << '\n';
  std::cin >> i;
  i/=100;
  result = amo*(1-pow(1/(1+i),n))/i;
  return result;
}

float PVCB()
{
  int n;
  float result = 0;
  std::cout << "Please enter the amount of payments:" << '\n';
  std::cin >> n;
  float amo, i, fv;
  std::cout << "Please enter the dividens"<<'\n';
  std::cin >> amo;
  std::cout << "Please enter the face value" << '\n';
  std::cin >> fv;
  std::cout << "Please enter the interest rate [percent]" << '\n';
  std::cin >> i;
  i/=100;
  for(int o=0;o<n;o++) //The dividens
  {
    result+=amo/pow((1.0+i),o+1);
    std::cout << "This part is equal to: "<< amo/pow((1.0+i),o+1) << '\n';
  }
  //The return of face value
  result+=fv/pow((1.0+i),n);
  return result;
}

float PVP()
{
  float amo, i, result = 0;
  std::cout << "Please enter the dividens" << '\n';
  std::cin >> amo;
  std::cout << "Please enter the interest rate [percent]" << '\n';
  std::cin >> i;
  i/=100;
  result = amo/i;
  return result;
}

int PV()
{
  std::cout << "This calculator is now used to calculate the Present value" << '\n';
  std::cout << '\n';
  std::cout << "Please enter the type of security that you are dealing with:" << '\n';
  std::cout << "1: General purpose" << '\n';
  std::cout << "2: Fixed payment security" << '\n';
  std::cout << "3: Coupon bonds" << '\n';
  std::cout << "4: Perpertuity" << '\n';
  std::cout << "0: Exit" << '\n';
  int choice = 0;
  float result = 0;
  std::cin >> choice;
  if(choice == 1)
  {
    result = PVGP();
  }
  else if(choice == 2)
  {
    result = PVFPS();
  }
  else if(choice == 3)
  {
    result = PVCB();
  }
  else if(choice == 4)
  {
    result = PVP();
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
    PV();
    return 0;
  }
  std::cout << "The PV is:" << '\n';
  std::cout << result << '\n';
  return 0;
}
