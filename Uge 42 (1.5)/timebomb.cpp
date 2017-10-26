#include <iostream>
#include <vector>
#include <string>

//global variable
char Digits1[45];
char Digits2[45];
char Digits3[45];
char Digits4[45];
char Digits5[45];

int howmany()
{
  if(Digits1[30]!='\0')
  {
    return 8;
  }
  else if(Digits1[26]!='\0')
  {
    return 7;
  }
  else if(Digits1[22]!='\0')
  {
    return 6;
  }
  else if(Digits1[18]!='\0')
  {
    return 5;
  }
  else if(Digits1[14]!='\0')
  {
    return 4;
  }
  else if(Digits1[10]!='\0')
  {
    return 3;
  }
  else
  {
    return 2;
  }
}


int testnumber(int i)
{
  if(i!=0)
  {
    i=i*4;
  }
  char Number[15];
  for(int o=0;o<3;o++)
  {
    Number[o]=Digits1[i+o];
  }
  for(int o=0;o<3;o++)
  {
    Number[3+o]=Digits2[i+o];
  }
  for(int o=0;o<3;o++)
  {
    Number[6+o]=Digits3[i+o];
  }
  for(int o=0;o<3;o++)
  {
    Number[9+o]=Digits4[i+o];
  }
  for(int o=0;o<3;o++)
  {
    Number[12+o]=Digits5[i+o];
  }
  std::string theDigit(Number);
  if(theDigit=="**** ** ** ****")
  {
    return 0;
  }
  if(theDigit=="  *  *  *  *  *")
  {
    return 1;
  }
  if(theDigit=="***  *****  ***")
  {
    return 2;
  }
  if(theDigit=="***  ****  ****")
  {
    return 3;
  }
  if(theDigit=="* ** ****  *  *")
  {
    return 4;
  }
  if(theDigit=="****  ***  ****")
  {
    return 5;
  }
  if(theDigit=="****  **** ****")
  {
    return 6;
  }
  if(theDigit=="***  *  *  *  *")
  {
    return 7;
  }
  if(theDigit=="**** ***** ****")
  {
    return 8;
  }
  if(theDigit=="**** ****  ****")
  {
    return 9;
  }
  else
  {
    return -1;
  }
}

int main()
{
  fgets(Digits1,45,stdin);
  fgets(Digits2,45,stdin);
  fgets(Digits3,45,stdin);
  fgets(Digits4,45,stdin);
  fgets(Digits5,45,stdin);
  int howmany2,single=0,Result=0,e;
  howmany2 = howmany();
  for(int i=0;i<howmany2;i++)
  {
    single=testnumber(i);
    if(single==-1)
    {
      std::cout << "BOOM!!" << '\n';
      return 0;
    }
    else
    {
      e=howmany2-i-1;
      int T = 1;
      for(int k=1;k<=e;k++)
      {
        T *=10;
      }
      Result+=single * T;
    }
  }
  if(Result%6==0)
  {
    std::cout << "BEER!!" << '\n';
  }
  else
  {
    std::cout << "BOOM!!" << '\n';
  }
  return 0;
}
