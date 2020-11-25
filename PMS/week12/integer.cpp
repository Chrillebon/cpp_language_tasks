# include <iostream>

class Integer {
private:
  int i;                  // value
public:
  Integer();              // "constructor"
  Integer(const Integer&); // "constructor"

  void set(int newi);     // "setter"
  int get();              // "getter"
  void print();           // print value
  int compare(const Integer);          // comparing value with other Integer
  //int compare(const Integer&);

  
};

Integer::Integer(const Integer& other_int){
  i = other_int.i;
}

Integer::Integer() {
  std::cout << "Congrats idiot, you have number!" << '\n';
  i=0;
}

int Integer::compare(const Integer otherint)
{
  if(i < otherint.i)
  {
    return -1;
  }
  else if(i == otherint.i)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}

// ambiguous, since references are also numbers
/*int Integer::compare(const Integer& otherint)
{
  if(i < otherint.i)
  {
    return -1;
  }
  else if(i == otherint.i)
  {
    return 0;
  }
  else
  {
    return 1;
  }
}*/

void Integer::set(int newi) {
  i = newi;
  return;
}

int Integer::get() {
  return i;
}

void Integer::print() {
  std::cout << i << '\n';
}

int main(int argc, const char *argv[]) {
  Integer a, c;
  a.set(1);
  Integer b(a);
  //b.set(2);
  c.set(3);


  std::cout << "lets try printing:" << '\n';
  a.print();
  b.print();
  c.print();

  std::cout << "summing: "<< a.get()+b.get()+c.get() << '\n';

  std::cout << "comparing values: " <<a.compare(c)<< '\n';
  std::cout << "That is, a is less than c!" << '\n';

  // testing that private!
  //a.i = 2;
  // Compiler error...
  return 0;
}
