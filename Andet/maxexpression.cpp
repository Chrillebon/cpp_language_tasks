#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <numeric>
#include <queue>
#include <math.h>
#include <functional>

struct PointerComparator {
  bool operator() (int *arg1, int *arg2) {
    return *arg1 < *arg2; //calls your operator
  }
};

int minussum(std::vector<int> vec)
{
  int sum=0;
  for(int i=0; i<vec.size(); i++)
  {
    sum+=vec[i];
  }
  return sum;
}

long long calcrest(std::vector<int> vec, std::vector<long int> result, int start, int zero, int one, int two, long long minus)
{
  int where = start;
  //if(vec[where] > two && vec[where] <= two+one)
  result[where] *= pow(2, two);
  one -= vec[where] - two;
  vec[where] = 0;
  two = 0;

  //Plus 0
  where = 0;
  while(zero) //Fyld med 0-taller
  {
    if(vec[where]) //Hvis der er mere plads i dette led, fylder ud
    {
      zero--;
      result[where] *= 0;
      vec[where]--;
    }
    else //Hvis ikke
    {
      where++; //Gå videre til næste
    }
  }

  //Så skal vi til at regne summen ud:
  long long sum=0;
  for(int i=0; i<vec.size(); i++)
  {
    sum += result[i];
  }
  sum += minus;
  return sum;
}

long long findlargest(std::vector<long long> finalpos) //Finder største resultat af alle mulige
{
  int result = finalpos[0];
  for(int i=1; i<finalpos.size(); i++)
  {
    if(finalpos[i] > result)
    {
      result = finalpos[i];
    }
  }
  return result;
}

int main()
{
  int n, p=1, m=0;
  std::cin >> n;
  std::vector<int> Plus;
  std::vector<int> Minus;
  char questo[n*2]{};
  std::cin >> questo;
  for(int i=0; i<n-1; i++)
  {
    if(questo[i*2+1] == '+') //Næste led er plus
    {
      if(p)
      {
        Plus.push_back(p);
        p=0;
      }
      if(m)
      {
        Minus.push_back(m);
        m=0;
      }
      p++;
    }
    else if(questo[i*2+1] == '-') //Næste led er minus
    {
      if(p)
      {
        Plus.push_back(p);
        p=0;
      }
      if(m)
      {
        Minus.push_back(m);
        m=0;
      }
      m++;
    }
    else //Næste tegn er gange
    {
      if(p)
      {
        p++;
      }
      else
      {
        m++;
      }
    }
  }
  if(p) //Runder af med et plusled
  {
    Plus.push_back(p);
    p=0;
  }
  if(m) //Runder af med et minusled
  {
    Minus.push_back(m);
    m=0;
  }
  sort(Plus.begin(), Plus.end(), std::greater<int>());
  sort(Minus.begin(), Minus.end(), std::greater<int>());
  int numb[4];
  std::vector<long> PlusResult(Plus.size());
  std::vector<long> MinusResult(Minus.size());
  std::fill(PlusResult.begin(), PlusResult.begin()+Plus.size(), 1);
  std::fill(MinusResult.begin(), MinusResult.begin()+Minus.size(), 1);
  std::cin >> numb[0];
  std::cin >> numb[1];
  std::cin >> numb[2];

  int count=0;
  //------------STARTER MED MINUS-------------
  //Minus 0
  while(numb[0]) //Så 0-tallerne i største led negativ
  {
    if(!(minussum(Minus))) //Hvis der ikke er flere pladser
    {
      break;
    }
    if(Minus.size()) //Om der overhovedet er minusstykker
    {
      if(Minus[count]) //Hvis der er mere plads i dette led
      {
        numb[0]--;
        MinusResult[count]*=0;
        Minus[count]--;
        count++;
      }
      else //Hvis ikke
      {
        count++;
      }
      if(count > Minus.size() - 1) //Nu har den cirklet alle elementer igennem i hvert fald 1 gang
      {
        count = 0;
      }
    }
    else //Ingen minusstykker
    {
      break;
    }
  }
  /*
            //------------------------
        for(int i=0; i<Plus.size(); i++)
        {
          std::cout << Plus[i]<< " ";
        }
        std::cout << '\n';
        for(int i=0; i<Minus.size(); i++)
        {
          std::cout << Minus[i]<< " ";
        }
        std::cout << '\n';
*/
  if(minussum(Minus)) //Så minus prioritetskø
  {
    std::priority_queue<int*,std::vector<int*>,PointerComparator> Insertone;
    for(int i=0; i<Minus.size(); i++)
    {
      if(MinusResult[i] != 0) //Alle led uden resultat 0
      {
        Insertone.push(&Minus[i]);
      }
    }
    if(Insertone.size()) //Ellers crasher den, hvis jeg leder efter øverste element og den er tom
    {
      while(*Insertone.top() && numb[1]) //Tag største og indsæt 1. Sorter og gentag.
      {
        numb[1]--;
        int* temp = Insertone.top();
        Insertone.pop();
        (*temp)--;
        Insertone.push(temp);
      }
      while(Insertone.size()) //Sæt dem alle tilbage igen, skal også være size her, da vi fjerner dem
      {
        Insertone.pop(); //Skal også fjerne den øverste, ellers lægger den bare den øverste til mange gange...
      }
    }

    //Minus 1
    count = 0;
    while(numb[1] && count <= Minus.size() - 1) //Hvis der er flere 1-taller
    {
      if(Minus[count]) //Hvis der er mere plads i dette led, fylder ud
      {
        numb[1]--;
        //Ganger med 1
        Minus[count]--;
      }
      else //Hvis ikke
      {
        count++; //Gå videre til næste
      }
    }

    //Minus 2
    count = 0;
    while(minussum(Minus)) //Fyld med 2-taller
    {
      if(Minus[count]) //Hvis der er mere plads i dette led, fylder ud
      {
        numb[2]--;
        MinusResult[count] *= 2;
        Minus[count]--;
      }
      else //Hvis ikke
      {
        count++; //Gå videre til næste
      }
    }
  }

  //Så skal vi til at regne summen ud:
  long long sum=0;
  for(int i=0; i<Minus.size(); i++)
  {
    sum -= MinusResult[i];
  }

  //-------------VIDERE TIL PLUS----------------
  //Plus 2
  std::vector<long long> PosRes;
  count = Plus.size()-1;
  while(numb[2])
  {
    if(numb[2] == Plus[count]) //Rammer rent
    {
      PlusResult[count] *= pow(2, numb[2]);
      Plus[count] = 0;
      numb[2] = 0;
      //Should end after this
    }
    else if(Plus[count] > numb[2] && Plus[count] <= numb[2]+numb[1] && numb[0]) //Mindre numb[2], men kan være der med numb[1], flere numb[0]
    {
      PosRes.push_back(calcrest(Plus, PlusResult, count, numb[0], numb[1], numb[2], sum)); //Tilføger mulighed til vector
      while(Plus[count]) //Fyld denne ud med mest andet end 2-taller
      {
        if(numb[0]) //Flere 0-taller
        {
          PlusResult[count] *= 0;
          Plus[count]--;
          numb[0]--;
        }
        else if(numb[1]) //Ikke flere 0-taller, men flere 1-taller
        {
          //Ganger med 1
          Plus[count]--;
          numb[1]--;
        }
        else //Ikke mere af de andre, kun numb[2]
        {
          PlusResult[count] *= 2;
          Plus[count]--;
          numb[2]--;
        }
      }
      count = Plus.size()-1; //resetter count, så den begynder forfra
    }
    else if(Plus[count] > numb[2] && Plus[count] <= numb[2]+numb[1]) //Mindre numb[2], men kan være der med numb[1], ingen numb[0]
    {
      PlusResult[count] *= pow(2, numb[2]);
      numb[1] -= Plus[count] - numb[2];
      Plus[count] = 0;
      numb[2] = 0;
      //Should end after this
    }
    else if(Plus[count] > numb[2] | count < 0 | Plus[count] == 0) //Mindre numb[2], eller forbi den sidste
    {
      count++; //Gå en tilbage
      while(!Plus[count]) //Hvis denne er fyldt, gå videre.
      {
        count++; // Gå en tilbage (eller frem da retningen er vendt)
      }
      PlusResult[count] *= pow(2, Plus[count]);
      numb[2] -= Plus[count];
      Plus[count] = 0;
      count = Plus.size()-1; // Start forfra
    }
    else //større numb[2]
    {
      count--;
    }
  }

  //Plus 0
  count = 0;
  while(numb[0]) //Fyld med 0-taller
  {
    if(Plus[count]) //Hvis der er mere plads i dette led, fylder ud
    {
      numb[0]--;
      PlusResult[count] *= 0;
      Plus[count]--;
    }
    else //Hvis ikke
    {
      count++; //Gå videre til næste
    }
  }

  //Så skal vi til at regne summen ud:
  for(int i=0; i<Plus.size(); i++)
  {
    sum += PlusResult[i];
  }
  PosRes.push_back(sum);
  //Udregn sum
  std::cout << findlargest(PosRes) << '\n';
  return 0;
}
