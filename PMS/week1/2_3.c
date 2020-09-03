#include <stdio.h>

int main()
{
  int option;
  int ammount;
  printf("What version would you like?\n");
  scanf("%d", &option);

  printf("How many of them do you need?\n");
  scanf("%d", &ammount);
  float total = ((option*2)+1.5)*ammount;
  printf("%.2f \n", ((option*2)+1.5)*ammount);
  return 0;
}
