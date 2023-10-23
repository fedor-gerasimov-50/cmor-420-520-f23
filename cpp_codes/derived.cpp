#include <iostream>

class Base{
public:
  // virtual = default print() function
  virtual void print(){
    std::cout << "Inside base class" << std::endl;
  };
};

class DerivedFromBase : public Base{
public:
  void print(){
    std::cout << "running print() in class `DerivedFromBase`" << std::endl;
  }  
};

int main(void){

  Base base;
  base.print();
  
  DerivedFromBase foo;

  foo.print();

  // we can create pointers to base classes
  // but assign the address of a derived class.
  Base * baz;
  baz = &foo;
  baz->print();

}
