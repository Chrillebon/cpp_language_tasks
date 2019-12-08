#include <iostream>

int findlargest(const int* list)
{
  int largest=0, place;
  for(int i=0;i<16;i++)
  {
    if(list[i]>largest)
    {
      largest = list[i];
      place = i;
    }
  }
  return place;
}

checkmem(const int* list, const short int* mem)
{
  int redoes=0;
  while(mem[20*redoes] != '\0' || mem[20*redoes+1] != '\0' || mem[20*redoes+2])
  {
    int done = 1;
    for(int i=0;i<16;i++)
    {
      //std::cout << "tal den tester: " <<20*redoes<<" og "<<i<<" og så tallene "<<list[i]<<" vs "<<mem[20*redoes+i] <<'\n';
      if(mem[20*redoes+i]!=list[i])
      {
        redoes++;
        done=0;
        break;
      }
    }
    if(done == 1) {std::cout << "Numeret på den anden ens: " <<redoes<< '\n'; return 1;}
    //std::cout << "darn it break! " <<done<< '\n';
  }

  return 0;
}

int main()
{
  int blocks[17];
  short int mem[110000];
  int result=1;
  for(int i=0;i<16;i++)
  {
    std::cin >> blocks[i];
    mem[i] = blocks[i];
  }

  //checkmem(blocks, mem);

  while(1)
  {
    int place = findlargest(blocks);
    int largest = blocks[place];
    std::cout << "Checkmark nr "<<result<<": " << '\n';
    std::cout << "place: " <<place<< '\n';
    std::cout << "largest: " <<largest<< '\n';
    std::cout << "numbers:" << '\n';
    for(int i=0;i<16;i++)
    {
      std::cout << blocks[i] << " ";
    }
    std::cout << '\n';

    blocks[place] = 0;
    for(int i=1;i<=largest;i++)
    {
      if(place + i == 16)
      {
        place -= 16;
      }
      if(place + i == 17)
      {
        place -= 17;
      }
      blocks[place + i]++;
    }


    /*for(int i=0;i<16;i++)
    {
      std::cout << blocks[i] << " ";
    }
    std::cout << '\n';*/


    if(checkmem(blocks, mem))
    {
      std::cout << "Resultatet er: " <<result<< '\n';
      std::cout << "Afsluttende tal:" << '\n';
      for(int i=0;i<16;i++)
      {
        std::cout << blocks[i] << " ";
      }
      std::cout << '\n';
      return 0;
    }
    //addmem
    for(int i = 0;i<16;i++)
    {
      mem[20*result+i] = blocks[i];
    }
    result++;
  }
  return 0;
}
