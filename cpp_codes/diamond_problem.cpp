#include <iostream>

class A{
public:  
  void foo(){
    std::cout << "A::foo" << std::endl;
  }
};

class B : virtual public A{
public:  
  void foo(){
   std::cout << "B::foo" << std::endl;
  } 
};
class C : virtual public A{
public:  
  void foo(){
   std::cout << "C::foo" << std::endl;
  }
};

class D : public B, public C {
public:
  void foo(){
    std::cout << "D::foo" << std::endl;
  }
};

int main(void){

  D d;
  d.foo();
  return 0;
}
