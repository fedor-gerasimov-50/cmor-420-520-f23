#include <cstdio> 
#include <iostream>

class Foo{
public:
  void set_x(int value);
  int get_x();

  Foo(){
    std::cout << "Running the constructor" << std::endl;
    x = 0;
  }
  ~Foo(){
    std::cout << "Running the destructor" << std::endl;
  }

private: 
  int x;
};

void Foo::set_x(int value){
  x = value;
}

int Foo::get_x(){
  return x;
}

int main(void) {
  Foo foo;
  foo.set_x(10);
  std::cout << "foo.x = " << foo.get_x() << std::endl;
}
