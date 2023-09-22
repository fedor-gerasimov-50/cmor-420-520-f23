#include <stdio.h>
#include <stdlib.h>

void foo(int x){
  printf("in `foo`, x = %d\n", x);
}

void bar(int x){
  printf("in `bar`, x = %d\n", x);
}

// This file illustrates the use of a function pointer
int main(void){

  void (*fun_ptr)(int) = foo;
  (*fun_ptr)(1);
  
  return 0;
}
