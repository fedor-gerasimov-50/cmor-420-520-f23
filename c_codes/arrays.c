#include <stdio.h>
#include <stdlib.h>

int main(void){

  int n = 100;  

  // statically defined array; stored on the "stack"
  int x[n];
  for (int i = 0; i < n; ++i){
    x[i] = i;
  }

  // dynamic array; stored on the "heap"
  int * y = (int *) malloc(sizeof(int) * n);
  free(y);
     
  return 0;
}
