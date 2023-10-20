#include <iostream>

class Base1{
public:
  // virtual = default print() function
  virtual void print(){
    std::cout << "Inside base class" << std::endl;
  };
};

class Base2{
public:
  int x;
};

class DerivedFromBase1 : public Base1{
public:
  void print(){
    std::cout << "running print() in class `DerivedFromBase1`" << std::endl;
  }  
};

class DerivedFromBothBases : public Base1, public Base2{
public:
  void print(){
    std::cout << "running print() in class `DerivedFromBothBases`" << std::endl;
  }
};

int main(void){

  Base1 base;
  base.print();
  
  DerivedFromBase1 foo;
  DerivedFromBothBases bar;

  foo.print();
  bar.print();

  // we can create pointers to base classes
  // but assign the address of a derived class.
  Base1 * baz;
  baz = &foo;
  baz->print();

  baz = &bar;
  baz->print();

  // the following will not work
  //  Base2 * base2_instance = &foo;

}
