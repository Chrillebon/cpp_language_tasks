#include <stdio.h>

void myfunc(int * p)
{
  p++;
}

int main(){
  int i[3] = {0,1,2}, *pi = NULL;
  pi = i;
  myfunc(i);
  myfunc(pi);
  printf("%d\n", *pi);
  return 0;
}
