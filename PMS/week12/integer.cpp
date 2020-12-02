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

  Integer add(const Integer&);
  Integer subtract(const Integer&);
  Integer multiply(const Integer&);

  Integer operator+(const Integer& num) {i += num.i; return *this;};
  Integer operator-(const Integer& num) {i -= num.i; return *this;};
  Integer operator*(const Integer& num) {i *= num.i; return *this;};
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
  return;
}

Integer Integer::add(const Integer& num)
{
  i += num.i;
  return *this;
}


Integer Integer::subtract(const Integer& num)
{
  i -= num.i;
  return *this;
}

Integer Integer::multiply(const Integer& num)
{
  i *= num.i;
  return *this;
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

  Integer *val;
  val = (Integer *)malloc(10*sizeof(Integer));
  for(int i=0;i<10;i++)
  {
    val[i].set(i);
  }
  Integer tmp(val[4]);
  //std::cout << "4x5 = " <<tmp.multiply(val[5])<< '\n';
  Integer res;
  //val[8].add(val[7].multiply(val[5]))
  /*tmp.set(val[4].get());
  tmp.multiply(val[5]);
  tmp.multiply(val[5]);
  tmp.multiply(val[5]);
  res.add(tmp);
  tmp.set(6);
  tmp.multiply(val[5]);
  tmp.multiply(val[5]);
  res.add(tmp);
  tmp.set(7);
  tmp.multiply(val[5]);
  res.add(tmp);
  tmp.set(8);
  res.add(tmp);
  std::cout << "4*5³+6*5²+7*5+8 = " <<res.get() << '\n';

  std::cout << "YAY!" << (res.add(val[8])).get() <<'\n';*/
  (val[8] + val[7]*val[5] + (val[6]*val[5])*val[5] + ((val[4]*val[5])*val[5])*val[5]).print();
  //val[8].add(  val[7].multiply(val[5])  ).add(  (val[6].multiply(val[5])).multiply(val[5])  ).add(  ((val[4].multiply(val[5])).multiply(val[5])).multiply(val[5])  ).print();
  // testing that private!
  //a.i = 2;
  // Compiler error...
  return 0;
}
