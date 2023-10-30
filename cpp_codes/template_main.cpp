#include <iostream>

template <typename T>
class Foo{
public:
  T get_value(){ return value_; }
  void set_value(T value){ value_ = value; };
  
private:
  T value_;
};

int main(void) {
  Foo<double> foo;
  foo.set_value(1.1);
  std::cout << "the value in Foo::foo is ";
  std::cout << foo.get_value() << std::endl;
}
