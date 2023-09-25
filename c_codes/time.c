#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

// This example demonstrates how to use time.h to time
// a C function

double sum(int n, double * x){
  double val = 0.0;
  for (int i = 0; i < n; ++i){
    val += x[i];
  }
  return val;
}  

int main(int argc, char ** argv){

  int n = 10000;
  double * x = (double *) malloc(sizeof(double) * n);
  for (int i = 0; i < n; ++i){
    x[i] = .1 * i;
  }

  clock_t tic, toc;
  tic = clock();
  for (int i = 0; i < 100; ++i){
    sum(n, x);
  }
  toc = clock();
  double elapsed = ((double) (end - start)) / CLOCKS_PER_SEC;
  printf("elapsed time = %g\n", elapsed / 100);

  free(x);
  
  return 0;
}
