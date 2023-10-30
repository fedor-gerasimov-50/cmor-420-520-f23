#include <iostream>

template <typename T> T add(T a, T b) {  
  return a + b;
}

int main(void) {
  int int_val = add<int>(2, 3);
  std::cout << "2 + 3 = " << int_val << std::endl;
  
  double dbl_val = add<double>(2.1, 3.0);
  std::cout << "2.1 + 3.0 = " << dbl_val << std::endl;

  // why does this line of code work?
  dbl_val = add<double>(2, 3.5); 
  std::cout << "2 + 3.5 = " << dbl_val << std::endl;
 
}
