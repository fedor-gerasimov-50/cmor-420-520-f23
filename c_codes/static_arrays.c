#include <stdio.h>
#include <stdlib.h>

// This file illustrates some differences between
// dynamic and statically defined arrays.

// (*x)[2] -> dereferencing x gives an array of size 2
void foo(int (*x)[2]){
  printf("x[0] = %d, %d\n", x[0][0], x[0][1]);
  printf("x[1] = %d, %d\n", x[1][0], x[1][1]);  
}

int main(void){

  int x[2][2] = {{1,2}};
  foo(x);

  // how to cast a statically defined array? use (*) without the variable declaration
  int (*y)[2] = (int (*)[2]) x;
  y[0][1] = 100;

  printf("y = %d, %d\n", y[0][0], y[0][1]);
  printf("x = %d, %d\n", x[0][0], x[0][1]);  

  /*
    void * z = malloc(sizeof(int) * 4);
    int * w = NULL;
    printf("z[0] = %d\n", ((int *)z)[0]);
  */
  return 0;
}
