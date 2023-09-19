#include <stdio.h>
#include <stdlib.h>

int main(void){

  int n = 9;
  int width = n / 2;

  int * x = (int *) malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i){
    x[i] = i;
  }

  x = &x[width];
  for (int i = -width; i < width + 1; ++i){
    //recall that x[i] --> *(x + i)
    printf("x[%d] = %d\n", i, x[i]);
  }

  // to free the pointer, we need to 
  free(&x[-width]);
     
  return 0;
}
