#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> number(3);
//<3 vector som char array med ints ;)
char order[3];
int Apos,Bpos,Cpos;

//sadly not my code...
int getposition(const char *array, size_t size, char c)
 {
      const char* end = array + size;
      const char* match = std::find(array, end, c);
      return (end == match)? -1 : (match-array);
 }


//A<B<C er ikke det samme som A<B and B<C
void rearange(char A, char B, char C)
{
  if(B<=A and A<=C)
  {
    number[Apos]=B;number[Bpos]=A;number[Cpos]=C;
  }
  else if(C<=A and A<=B)
  {
    number[Apos]=C;number[Bpos]=A;number[Cpos]=B;
  }
  else if(A<=B and B<=C)
  {
    number[Apos]=A;number[Bpos]=B;number[Cpos]=C;
  }
  else if(C<=B and B<=A)
  {
    number[Apos]=C;number[Bpos]=B;number[Cpos]=A;
  }
  else if(A<=C and C<=B)
  {
    number[Apos]=A;number[Bpos]=C;number[Cpos]=B;
  }
  else if(B<=C and C<=A)
  {
    number[Apos]=B;number[Bpos]=C;number[Cpos]=A;
  }
  else
  {
    std::cout << "ERROR!!!" << '\n';
  }
}

int main()
{
  std::cin >> number[0] >> number[1] >> number[2];
  std::cin >> order;

  Apos = getposition(order, 3, 'A');
  Bpos = getposition(order, 3, 'B');
  Cpos = getposition(order, 3, 'C');

  rearange(number[0],number[1],number[2]);
  std::cout << number[0] <<" "<<number[1]<<" "<<number[2]<< '\n';
  return 0;
}
