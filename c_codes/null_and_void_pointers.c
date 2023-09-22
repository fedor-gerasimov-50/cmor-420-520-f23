#include <stdio.h>
#include <stdlib.h>

// This file illustrates the use of null and void pointers.
int main(void){
   
  // "malloc" returns (void *) = void pointer. We cast it
  // explicitly to a typed pointer for C++ compatibility.
  void * x = malloc(sizeof(int) * 4);
  ((int *)x)[1] = 13;
  printf("sizeof(x) = %lu\n", sizeof(void));


  return 0;
}
