#include <stdio.h>

void swap(int * x, int * y){
  int tmp = *x;
  *x = *y; // set x = y
  *y = tmp;
}

int main(void){
  int x = 2;
  int y = 200;

  swap(&x, &y);

  printf("x = %d, y = %d\n", x, y);
  
  return 0;
}
