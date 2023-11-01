#include <iostream>

// template *declaration*; no specialization
template <typename T, int n> void foo() {
  std::cout << "Running foo with no specialization ";
  std::cout << n << std::endl;
}
// note: template partial specialization for functions
// is not allowed. 
template <> void foo<int, 0>(){
  std::cout << "Running foo with full specialization";
  std::cout << std::endl;
}

// can use partial specialization on classes
// This defines the template ....
template <typename T, int n> class Foo{
public:
  Foo() {
    std::cout << "Running Foo::print with full specialization" << std::endl;
  }
  void print(){
    std::cout << "Fully specialized printing" << std::endl; 
  }  
};

// ... and this code performs specialization on the parameter "n"
template <typename T> class Foo<T, 0> {
 public:
  Foo(){
    std::cout << "Running Foo::foo with partial specialization" << std::endl;
  }
  void print(); 
};

// externally define partially specialized function
template <typename T> void Foo<T, 0>::print(){
  std::cout << "Partially specialized printing";
  std::cout << std::endl;    
}


// a common example of template metaprogramming
template <int n> struct Factorial {
  const static int result = n * Factorial<n - 1>::result;
};

// specialization on n=0
template <>
struct Factorial<0> {
  const static int result = 1;
};


int main(void) {
  foo<double, 1>();
  foo<int, 0>();

  Foo<double, 1> x;
  x.print();
  Foo<double, 0> y;
  y.print();
  
  int n = Factorial<4>::result;
  std::cout << "n = " << n << std::endl;
  
}
