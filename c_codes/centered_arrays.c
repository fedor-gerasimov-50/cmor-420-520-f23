#include <stdio.h>
#include <stdlib.h>

int main(void){
  int n = 9;
  int width = n / 2;

  int * x = (int *) malloc(sizeof(int) * n);
  for (int i = 0; i < n; ++i){
    x[i] = -width + i;
  }
  
  // enable negative indices
  x = &x[width]; // note: "int x[n]" doesn't allow this because x is statically defined (immutable)
  
  printf("x[i] = ");
  for (int i = -width; i < width; ++i){
    printf("%d ", x[i]);
  }
  printf("\n");

  free(&x[-width]);
  return 0;
}
