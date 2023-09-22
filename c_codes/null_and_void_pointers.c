#include <stdio.h>
#include <stdlib.h>

// This file illustrates the use of null and void pointers.
int main(void){

  int * nullptr = NULL;
  printf("The null pointer address is %p\n", nullptr);
  // *nullptr will throw an error
    
  // "malloc" returns (void *) = void pointer. We cast it
  // explicitly to a typed pointer for C++ compatibility.
  void * x = malloc(sizeof(int) * 4);
  ((float *)x)[0] = 1;
  printf("x[0] = %d\n", ((int *)x)[0]);

  return 0;
}
