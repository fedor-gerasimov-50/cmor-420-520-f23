#include <iostream>
#include "vector.hpp"

int main(void) {

  int n = 5;
  Vector x(n);
  Vector y(n);
  for (int i = 0; i < n; ++i){
    x[i] = i;
    y[i] = 1-i;
  }

  x.print("x");
  y.print("y");
  
  // this calls the "copy constructor"
  Vector z = x;
  z.print("(Vector z = x)");

  // this calls the "copy move constructor"
  z = y;
  y[0] = 13;
  z.print("(z = y)");
  
  return 0;
}
