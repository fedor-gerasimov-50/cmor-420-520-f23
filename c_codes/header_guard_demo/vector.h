// header guard for Vector type
#ifndef _VECTOR
#define _VECTOR

typedef struct Vector{
  int n;
  double * data;
}Vector;

#endif

double sum(const Vector * x);
