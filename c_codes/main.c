#include <stdio.h>

int main(void)
{
  // Note: &, |, ^, ~, <<, >> are special bitwise operations that you should be careful with

  for (int i = 0; i < 10; ++i){
    printf("i = %d\n", i);
    if (i == 2){
      break;
    }
    if (i > 2){
      printf("This line won't be run\n");
    }
  }    
  printf("This line will be run\n");

  int x = 7;

  // ternary operator 
  int y = (x==7) ? x : 0;
  //  if (x==7){
  //    y = x;
  //  } else {
  //    y = 0;
  //  }
    
  printf("y = %d\n", y);
  
  return 0;
}
