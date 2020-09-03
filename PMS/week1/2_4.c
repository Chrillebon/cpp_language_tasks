#include <stdio.h>

int main()
{
  printf("What is your weekly pay?\n");
  float weekpay;
  scanf("%f", &weekpay);
  int weekhour;
  printf("How many hours do you work?\n");
  scanf("%d", &weekhour);
  float hourpay = weekpay/weekhour;
  int pay_whole = hourpay;
  int decimal = 100*(hourpay - (int)(hourpay));
  printf("Your average hourly pay rate is %d dollars and %d cents.\n", pay_whole, decimal);
  return 0;
}
