#include <cstdio> // can also use <stdio.h>
#include <iostream>

void foo(int & i){
  std::cout << "i = " << i << std::endl;
}

int main(void) {
  printf("In C++, you can use printf like in C...\n");
  std::cout << "...or use the new streaming operator syntax." << std::endl;

  // old vs new array allocation
  int * x = (int *) malloc(sizeof(int) * 10);
  free(x);
  
  double * y = new double [10];
  delete[] y;

  // delete without [] is for single entries
  double * z = new double;
  delete z;

  // references vs pointers
  int i;
  int * i_ptr = &i;
  int & i_reference = i;

  i = 10;
  std::cout << "*i_ptr = " << *i_ptr << std::endl;
  std::cout << "i_reference = " << i_reference << std::endl;

  foo(i_reference);
  
}
