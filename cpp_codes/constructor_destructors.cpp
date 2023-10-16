#include <iostream>

class Foo{

public:

  Foo(){
    std::cout << "Running the default constructor" << std::endl;
  };
  ~Foo(){
    std::cout << "Running the default destructor" << std::endl;
  };

  Foo(const Foo & foo){
    std::cout << "Running the copy constructor" << std::endl;
  }
  
  Foo & operator=(const Foo & foo){
    std::cout << "Running the copy assignment constructor" << std::endl;
    return *this;
  }

  
};


int main(void){

  Foo foo;
  Foo foo_copy;
  foo_copy = foo;

  return 0;
}
