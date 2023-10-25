#include <iostream>

class Base{
public: 
  void print(){
    std::cout << "Inside base class" << std::endl;
  };
};

class DerivedFromBase : public Base {
public:
  void print(){
    std::cout << "Inside the derived class" << std::endl; 
  } 
};

int main(void){
  
  DerivedFromBase foo;

  return 0;
}
