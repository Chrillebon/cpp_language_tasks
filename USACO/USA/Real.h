float Real()
{
  //What we need:
  float pri,nir,inf,tax;
  std::cout << "Please enter the principal value" << '\n';
  std::cin >> pri;
  std::cout << "Please enter the nominal interest rate" << '\n';
  std::cin >> nir;
  std::cout << "Please enter the average (expected) inflation rate [percent]" << '\n';
  std::cin >> inf;
  std::cout << "Please enter the tax rate[percent]" << '\n';
  std::cin >> tax;
  //What we are getting out
  float nii, rtax, atnii, loss, rii, atrii;
  nii=pri*nir/100;
  std::cout << "The nominal interest income is: $" <<nii<< '\n';
  rtax=nii*tax/100;
  std::cout << "The taxes you have to pay is: $"<< rtax << '\n';
  atnii=nii-rtax;
  std::cout << "The after-tax nominal interest income is: $"<< atnii << '\n';
  loss=pri*inf/100;
  std::cout << "The loss of principal value because of inflation is: $"<< loss << '\n';
  rii=nii-loss;
  std::cout << "The real interest income is: $"<< rii << '\n';
  atrii=rii-rtax;
  std::cout << "The after tax real interest income is: $"<< atrii << '\n';
  char answer;
  while(1)
  {
    std::cout << '\n';
    std::cout << "Do you want the calculations? [y/n]" << '\n';
    std::cin >> answer;
    if(answer == 'n' || answer == '0')
    {
      break;
    }
    if(answer == 'y' || answer == '1')
    {
      std::cout << "The nominal interest income calculation" << '\n';
      std::cout << "Nominal interest income=$"<<pri<<"*"<<nir/100<<"=$"<<nii << '\n' << '\n';
      std::cout << "The taxes you have to pay calculation" << '\n';
      std::cout << "Taxes=$"<<nii<<"*"<<tax/100<<"=$"<<rtax << '\n' << '\n';
      std::cout << "The after-tax nominal interest income calculation" << '\n';
      std::cout << "After-tax nominal interest income=$"<<nii<<"-$"<<rtax<<"=$"<<atnii<< '\n' << '\n';
      std::cout << "The loss of principal value because of inflation calculation" << '\n';
      std::cout << "Loss of principal value=$"<<pri<<"*"<<inf/100<<"=$"<<loss << '\n' << '\n';
      std::cout << "The real interest income calculation" << '\n';
      std::cout << "Real interest income=$"<<nii<<"-$"<<loss <<"=$"<<rii<< '\n' << '\n';
      std::cout << "The after tax real interest income calculation" << '\n';
      std::cout << "After tax real interest income=$"<<rii<<"-$"<<rtax <<"=$"<<atrii<< '\n';
      break;
    }
    else
    {
      std::cout << "ERROR - Please try again:" << '\n';
    }
  }
  while(1)
  {
    std::cout << '\n';
    std::cout << "Do you want to see where the money goes to? [y/n]" << '\n';
    std::cin >> answer;
    if(answer == 'n' || answer == '0')
    {
      break;
    }
    if(answer == 'y' || answer == '1')
    {
      std::cout << "Do you want it in:" << '\n';
      std::cout << "1: Nominal terms" << '\n';
      std::cout << "2: Real terms" << '\n';
      std::cout << "3: Both" << '\n';
      int choice;
      std::cin >> choice;
      if(choice == 1)
      {
        float person, government, inflation;
        person=atrii/nii;
        government=rtax/nii;
        inflation=loss/nii;
        std::cout << "You get $"<<atrii<<"/$"<<nii<<"="<<person*100<<" percent" << '\n';
        std::cout << "The Government gets $"<<rtax<<"/$"<<nii<<"=" <<government*100<<" percent"<< '\n';
        std::cout << "The inflation causes you to lose $"<<loss<<"/$"<<nii<<"="<<inflation*100<<" percent" << '\n';
      }
      else if(choice == 2)
      {
        float person, government;
        person=atrii/rii;
        government=rtax/rii;
        std::cout << "You get $"<<atrii<<"/$"<<rii<<"="<<person*100<<" percent" << '\n';
        std::cout << "The Government gets $"<<rtax<<"/$"<<rii<<"=" <<government*100<<" percent"<< '\n';
      }
      else if(choice == 3)
      {
        float person, government, inflation;
        std::cout << "NOMINAL TERMS:" << '\n';
        person=atrii/nii;
        government=rtax/nii;
        inflation=loss/nii;
        std::cout << "You get $"<<atrii<<"/$"<<nii<<"="<<person*100<<" percent" << '\n';
        std::cout << "The Government gets $"<<rtax<<"/$"<<nii<<"=" <<government*100<<" percent"<< '\n';
        std::cout << "The inflation causes you to lose $"<<loss<<"/$"<<nii<<"="<<inflation*100<<" percent" << '\n';
        std::cout << '\n';
        std::cout << "REAL TERMS:" << '\n';
        person=atrii/rii;
        government=rtax/rii;
        std::cout << "You get $"<<atrii<<"/$"<<rii<<"="<<person*100<<" percent" << '\n';
        std::cout << "The Government gets $"<<rtax<<"/$"<<rii<<"=" <<government*100<<" percent"<< '\n';
      }
      else
      {
        std::cout << "ERROR - Invalid option, please try again" << '\n';
      }
      break;
    }
    else
    {
      std::cout << "ERROR - Please try again:" << '\n';
    }
  }
  return 0;
}
