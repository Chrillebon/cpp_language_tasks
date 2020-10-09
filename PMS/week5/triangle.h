#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct {
    float x,y;
} point;

typedef struct {
    point corner[3];
} tri;

// Indsæt kode for at sørge for, at man ikke overflower...
double area(tri *triangle)
{
  double a,b,c,p,res = 0;
  a = sqrt(pow(triangle->corner[1].x - triangle->corner[0].x,2) + pow(triangle->corner[1].y - triangle->corner[0].y,2));
  b = sqrt(pow(triangle->corner[2].x - triangle->corner[1].x,2) + pow(triangle->corner[2].y - triangle->corner[1].y,2));
  c = sqrt(pow(triangle->corner[0].x - triangle->corner[2].x,2) + pow(triangle->corner[0].y - triangle->corner[2].y,2));
  p = (a+b+c)/2;
  res = sqrt(p*(p-a)*(p-b)*(p-c));
  return res;
}

tri * newtriangle()
{
  tri *triangle = malloc(sizeof(*triangle));
  if(triangle==NULL) return NULL;
  for(int i=0;i<3;i++)
  {
    triangle->corner[i] = malloc(sizeof(*(triangle->corner)));
  }
  //triangle->corner = calloc(3,sizeof(*(triangle->corner)));
  //if(triangle->corner == NULL) return NULL;

  float mytmp = 0;
  for(int i=0;i<3;i++)
  {
    printf("Please enter corner number %d\n", i+1);

    scanf("%f", &mytmp);
    triangle->corner[i].x = mytmp;

    scanf("%f", &mytmp);
    triangle->corner[i].y = mytmp;
  }
  return triangle;
}

// Benytter barycentric coordinates non-negative
int point_inside(tri * triangle, point * alpha)
{
  float l1, l2, l3;
  l1 = ((triangle->corner[1].y-triangle->corner[2].y)*(alpha->x-triangle->corner[2].x) + (triangle->corner[2].x-triangle->corner[1].x)*(alpha->y-triangle->corner[2].y));
  l1 /= ((triangle->corner[1].y-triangle->corner[2].y)*(triangle->corner[0].x-triangle->corner[2].x) + (triangle->corner[2].x-triangle->corner[1].x)*(triangle->corner[0].y-triangle->corner[2].y));
  l2 = ((triangle->corner[2].y-triangle->corner[0].y)*(alpha->x-triangle->corner[2].x) + (triangle->corner[0].x-triangle->corner[2].x)*(alpha->y-triangle->corner[2].y));
  l2 /= ((triangle->corner[1].y-triangle->corner[2].y)*(triangle->corner[0].x-triangle->corner[2].x) + (triangle->corner[2].x-triangle->corner[1].x)*(triangle->corner[0].y-triangle->corner[2].y));
  l3 = 1 - l1 - l2;
  if(l1 >= 0 && l2 >= 0 && l3 >= 0)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int congruence(tri * t1,tri * t2)
{
  a1 = sqrt(pow(t1->corner[1].x - t1->corner[0].x,2) + pow(t1->corner[1].y - t1->corner[0].y,2));
  b1 = sqrt(pow(t1->corner[2].x - t1->corner[1].x,2) + pow(t1->corner[2].y - t1->corner[1].y,2));
  c1 = sqrt(pow(t1->corner[0].x - t1->corner[2].x,2) + pow(t1->corner[0].y - t1->corner[2].y,2));

  a2 = sqrt(pow(t2->corner[1].x - t2->corner[0].x,2) + pow(t2->corner[1].y - t2->corner[0].y,2));
  b2 = sqrt(pow(t2->corner[2].x - t2->corner[1].x,2) + pow(t2->corner[2].y - t2->corner[1].y,2));
  c2 = sqrt(pow(t2->corner[0].x - t2->corner[2].x,2) + pow(t2->corner[0].y - t2->corner[2].y,2));

  if(a1 == a2 && b1 == b2 && c1 == c2)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}


#endif
