#include <cstdio> // can also use <stdio.h>
#include <iostream>

extern "C" {
  void c_foo(){
    printf("running c_foo\n");
  }
}

// avoid needing to write "std::" in front of operators 
// such as "cout" or "endl"
using namespace std;

void foo(int & i){
  cout << "i = " << i << endl;
}

int main(void) {

  printf("In C++, you can use printf like in C...\n");
  std::cout << "...or use the new streaming operator syntax." << std::endl;

  // old C-style array allocation
  int * x = (int *) malloc(sizeof(int) * 10);
  free(x);

  // new C++ style array allocation
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
  cout << "*i_ptr = " << *i_ptr << endl;
  cout << "i_reference = " << i_reference << endl;

  // calling a function with a reference argument
  foo(i_reference);

  // const and references: these are equivalent
  const int & a = 10;
  int const & b = 20;
  
}
