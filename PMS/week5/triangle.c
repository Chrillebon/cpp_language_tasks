#include "triangle.h"
#include <stdio.h>
#include <stdlib.h>



int main()
{
  tri *mytriangle = newtriangle();
  printf("Denne trekant er af stoerrelse %f\n", area(mytriangle));
  point * newpoint;
  printf("Indtast nu et punkt, som måske er inden for...\n");
  float tmp;
  scanf("%f", &tmp);
  newpoint->x = tmp;
  scanf("%f", &tmp);
  newpoint->y = tmp;
  if(point_inside(mytriangle, newpoint))
  {
    printf("Du har indtastet et punkt INDEN for trekanten!!!\n");
  }
  else
  {
    printf("Du har indtastet et punkt UDEN for trekanten!!!\n");
  }
  return 0;
}
