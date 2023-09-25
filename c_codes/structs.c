#include <stdio.h>
#include <stdlib.h>

typedef struct Vector{
  int n;
  double * ptr;
} Vector;

Vector init_vector(int n){
  double * ptr = (double *) malloc(sizeof(double) * n);
  Vector vector = {.n = n, .ptr = ptr};
  return vector;
}

void free_vector(Vector x){
  free(x.ptr);
}

void set_index_Vector(Vector * x,
		      double value,
		      int index){
  x->ptr[index] = value;
}

int main(void){

  int n = 5;
  Vector x = init_vector(n);

  set_index_Vector(&x, 13.0, 1);

  for (int i = 0; i < x.n; ++i){
    printf("x.ptr[%d] = %f\n", i, x.ptr[i]);
  }

  free_vector(x);
}
