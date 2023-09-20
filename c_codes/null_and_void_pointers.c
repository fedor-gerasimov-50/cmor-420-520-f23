#include <stdio.h>
#include <stdlib.h>

// This file illustrates the use of null and void pointers.

int main(void){

  void * x = malloc(sizeof(int) * 4);
  int * y = NULL;
  printf("x[0] = %d\n", ((int *)x)[0]);
  return 0;
}
