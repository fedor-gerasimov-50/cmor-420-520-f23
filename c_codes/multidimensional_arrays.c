#include <stdio.h>
#include <stdlib.h>

int main(void){

  int m = 10;
  int n = 8;

  // "flat" storage of a matrix
  int * A = (int *) malloc(sizeof(int) * m * n);

  // pointer to pointers: B[i][j]
  int ** B = (int **) malloc(sizeof(int *) * m);
  for (int i = 0; i < m; ++i){
    B[i] = (int *) malloc(sizeof(int) * n);
  }
  
  int ** C = (int **) malloc(sizeof(int *) * m);
  C[0] = (int *) malloc(sizeof(int) * m * n);
  for (int i = 1; i < m; ++i){
    C[i] = C[i-1] + n;
  }

  printf("C = [\n");
  for (int i = 0; i < m; ++i){
    for (int j = 0; j < n; ++j){
      // A[j + i * n] // A[i,j] in row major storage
      A[i + j * m] = (i+j);  // A[i,j] in column major storage

      B[i][j] = (i+j);
      
      C[i][j] = (i+j);
      //C[0][j + i * n];
      // C(:) -> returns back vector of the matrix entries

      //printf("%4.1d ", C[i][j]);
      printf("%2d ", C[0][j + i * n]);
    }
    printf("\n");
  }
  printf("]\n");  
  

  
  
  return 0;
}
