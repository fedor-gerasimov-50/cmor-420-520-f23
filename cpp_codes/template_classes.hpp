#include <iostream>

#ifndef _FOO
#define _FOO

template <typename T>
class Foo{
public:
  T get_value(); // define function here
  void set_value(T value){ value_ = value; };
private:
  T value_;
};

#endif

template <typename T>
T Foo<T>::get_value(){
  return value_;
}
