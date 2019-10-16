#include <iostream>

int deck[52][4];
int pick = 0;
int cases = 1;
char temp;

void reset()
{
  cases++;
  pick = 0;
}

void input()
{
  for(int j=0;j<52;j++)
  {
    std::cin >> temp;
    deck[j][0] = temp;
    std::cin >> temp;
    deck[j][1] = temp;
  }
}

int main()
{
  int n;
  std::cin >> n;
  for(int l=0;l<n;l++) //# of cases
  {
    input();
    //go to #27 (52-25)
    int on = 26;
    int card;
    for(int i=0;i<3;i++)
    {
      card = deck[on][0]-48;
      if(card >= 10)
      {
        card = 10;
      }
      pick += card;
      on -= 1 + (10 - card);
    }
    pick += (25 - on);
    temp = deck[pick][0];
    std::cout << "Case " <<cases<<": "<<temp;
    temp = deck[pick][1];
    std::cout << temp << '\n';
    reset();
  }
  return 0;
}
