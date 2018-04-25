#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;

int getthird(int start, int end)
{
  return (end-start)/3;
}

void insert(int *tree, int start, int end, int *instruction, int val, int index, int depth)
{
  tree[index] = val;
  if(instruction[depth] == 0)
  {
    return;
  }
  if(instruction[depth] == 1)
  {
    return insert(tree, start, start+getthird(start,end), instruction, val, 2*index+1, depth+1);
  }
  if(instruction[depth] == 2)
  {
    return insert(tree, start+getthird(start,end), start+2*getthird(start,end), instruction, val, 2*index+2, depth+1);
  }
  else //instruction[depth] == 3
  {
    return insert(tree, start+2*getthird(start,end), end, instruction, val, 2*index+3, depth+1);
  }
}

int match(int *tree, int start, int end, int *instruction, int index, int depth)
{
  if(instruction[depth] == 0)
  {
    return tree[index];
  }
  if(instruction[depth] == 4)
  {
    return max(max(match(tree, start, start+getthird(start,end), instruction, 3*index+1, depth+1),
                   match(tree, start+getthird(start,end), start+2*getthird(start,end), instruction, 3*index+2, depth+1)),
                   match(tree, start+2*getthird(start,end), end, instruction, 3*index+3, depth+1));
  }
  if(instruction[depth] == 1)
  {
    return match(tree, start, start+getthird(start,end), instruction, 3*index+1, depth+1);
  }
  if(instruction[depth] == 2)
  {
    return match(tree, start+getthird(start,end), start+2*getthird(start,end), instruction, 3*index+2, depth+1);
  }
  if(instruction[depth] == 3)
  {
    return match(tree, start+2*getthird(start,end), end, instruction, 3*index+3, depth+1);
  }
}

void prep(char chars[], int *ints)
{
  for(int i=0;i<50;i++)
  {
    if(chars[i+1] == '-'){ints[i] = 1;}
    else if(chars[i+1] == '0'){ints[i] = 2;}
    else if(chars[i+1] == '+'){ints[i] = 3;}
    else if(chars[i+1] == '?'){ints[i] = 4;}
    else{return;}
  }
  return;
}

int main()
{
  int height = 50; //log3(50)
  int max = 3*pow(2, height) - 1; //lig med 7500
  int *tree = new int[7500];

  int n, manyT = 0;

  int *instruction = new int[50]{};
  std::cin >> n;
  for(int i=0;i<n;i++)
  {
    char let;
    std::cin >> let;
    if(let == 'T')
    {
      char midstep[50];
      fgets(midstep, 50, stdin);
      prep(midstep, instruction);
      for(int i=0;i<50;i++)
      {
        std::cout << instruction[i] << " ";
      }
      insert(tree, 0, 50, instruction, manyT, 0, 0);
    }
    else
    {
      char midstep[50]{};
      std::cin >> midstep;
      prep(midstep, instruction);
      std::cout << match(tree, 0, 50, instruction, 0, 0) << '\n';
    }
  }
  return 0;
}
