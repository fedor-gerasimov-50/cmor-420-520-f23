#include <stdio.h>
#include <stdlib.h>

// This file illustrates some differences between
// dynamic and statically defined arrays.
void foo(int (*x)[2], char * msg){
  printf("%s[0][0] = %d\n", msg, x[0][0]);
}

int main(void){

  // static array
  int x[10][2] = {{13, 1}, {2, 3}, {1, 2}};

  // dynamic array  
  int ** y = (int **) malloc(sizeof(int *) * 2);
  y[0] = (int *) malloc(sizeof(int) * 2);
  y[1] = (int *) malloc(sizeof(int) * 2);
  y[0][0] = 13;
  
  foo(x, "x");
 
  // similarities
  return 0;
}
