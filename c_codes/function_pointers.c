#include <stdio.h>
#include <stdlib.h>

void foo(void * x){
  // x should be type "int" here
  printf("in `foo`, x = %d\n", *((int *)x));
}

void bar(void * x){  
  // x should be type "float" here
  printf("in `bar`, x = %f\n", *((float *)x));
}

// This file illustrates the use of a function pointer
int main(void){

  int x = 1;
  void (*fun_ptr)(void *) = &foo;
  (*fun_ptr)(&x);

  fun_ptr = bar;
  (*fun_ptr)(&x);  
  
  return 0;
}
