#include <stdio.h>

int main(void)
{

  int x = 1;
  double y = 1.0;

  // implicit conversion from int to double here  
  double w = 2.0 / y - 4; 

  // += increment
  x += 1; // x = x + 1
  x *= 2; // x = x * 2

  // mod operation
  x = 10;
 
  printf("x %% 3 = %d\n", x % 3);

  return 0;
}
