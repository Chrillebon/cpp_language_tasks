#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int maxval = 0;

class Offer
{
public:
  offer();
  int id;
  int amount;
  int save = 0;
  int sale[5*2]{};
  int price;
};

Offer tilbud[99];
Offer varer[5];

bool comp(Offer a, Offer b) { return a.save > b.save; }

int b, c, k, p, s, n; //-------------alle variablerne---------------

int canbuy(int arr[], int i)
{
    int goodtogo = 0;
    for(i;i<s;i++) //Alle tilbuddene
    {
      for(int o=0;o<sizeof(arr)/sizeof(arr[0])/2;o++) //Alle varer du skal have
      {
        goodtogo = 1;
        if(tilbud.amount > arr.size()/2) //flere tilbudsvarer end ting i kuven
        {
          break;
        }
        int cartcont = 0; //om du kan bruge tilbuddet
        for(int u=0;u<tilbud[i].amount;u++) //For alle de varer de har
        {
          if(tilbud[i].sale[u*2] == arr[o*2]) //Hvis de har denne vare
          {
            cartcont = 1;
            if(tilbud[i].sale[u*2+1] > arr[o*2+1]) //Hvis du IKKE kan købe det antal varer
            {
              goodtogo = 0;
              break;
            }
            else
            {
              break;
            }
          }
        }
        if(cartcont == 0)
        {
          goodtogo = 0;
          break;
        }
      }
      if(goodtogo == 1) //Dette tilbud kunne ikke opfylde kravene.
      {
        return i;
      }
    }
    return -1;
}

int maxval(int arr[])
{
  for()
}

void whatoffer(int arr[], int where)
{
  where = canbuy(arr, where);
}

int main()
{
  ifstream fin("INPUT.TXT");
  ifstream fof("OFFER.TXT");

  fin >> b;
  fof >> s;
  int buy[b*2];
  for(int i=0;i<b;i++)
  {
    fin >> c >> k >> p;
    varer[i].id = c;
    buy[2*i] = c;
    buy[2*i+1] = k;
    varer[i].amount = 1;
    varer[i].price = p;
    varer[i].sale[0] = 0;
  }
  for(int i=0;i<s;i++) //For alle tilbud
  {
    fof >> n;
    tilbud[i].amount = n;
    tilbud[i].id = 0;
    int sum = 0;
    for(int u=0;u<n;u++) //for alle varer i tilbuddet
    {
      fof >> c >> k;
      tilbud[i].sale[2*u] = c;
      tilbud[i].sale[2*u+1] = k;
      for(int o=0;o<b;o++)
      {
        if(tilbud[i].sale[2*u] == varer[o].id)
        {
          sum += varer[o].price*tilbud[i].sale[2*u+1];//pris for id ganget antal
          //break;
        }
        /*if(o == b-1)
        {
          sum = -1000;
        }*/
      }
    }
    fof >> p;
    tilbud[i].price = p;
    tilbud[i].save = sum - tilbud[i].price;
  }

  sort(tilbud, tilbud+s, comp);

  std::cout << canbuy(buy, 0) << '\n';



}
