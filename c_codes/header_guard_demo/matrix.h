#include "vector.h"

#ifndef _MATRIX
#define _MATRIX

typedef struct Matrix{
  int n; // assume square
  double * data;
} Matrix;

#endif

void matvec(Vector * b, const Matrix * A, const Vector * x);
