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
  x = &x[width]; 
  printf("x[i] = ");
  for (int i = -width; i < width; ++i){
    printf("%d ", x[i]);
  }
  printf("\n");
  
  return 0;
}
