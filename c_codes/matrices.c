#include <stdio.h>
#include <stdlib.h>

int main(void){

  int m = 10;
  int n = 8;

  // "flat" storage of a matrix
  int * A = (int *) malloc(sizeof(int) * m * n);

  // pointer to pointers
  int ** B = (int **) malloc(sizeof(int *) * m);
  for (int i = 0; i < m; ++i){
    B[i] = (int *) malloc(sizeof(int) * n);
  }

  // pointer to pointers (contiguous memory)
  int ** C = (int **) malloc(sizeof(int *) * m);
  C[0] = (int *) malloc(sizeof(int) * m * n);
  for (int i = 1; i < m; ++i){
    C[i] = C[i-1] + n;
  }

  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      //A[i + j * m] = (i+j); // A[i,j] in column major format
      A[j + i * n] = (i+j); // A[i,j] in row major format    
      B[i][j] = (i+j);      
      C[i][j] = (i+j);
    }
  }

  // free allocated memory
  free(A);
  
  for (int i = 0; i < m; ++i){
    free(B[i]);
  }
  free(B);
  
  free(C[0]);
  free(C);    
  
  return 0;
}
