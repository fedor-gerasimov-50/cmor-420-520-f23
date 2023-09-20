#include <stdio.h>
#include <stdlib.h>

// This program shows how to parse input arguments
int main(int argc, char ** argv){
  
  printf("The number of arguments = %d\n", argc);

  for (int i = 0; i < argc; ++i){
    printf("Argument %i = %s\n", i, argv[i]);
  }

  // convert a string into an integer (atoi) or
  // a floating point number (atof).
  int x = atoi(argv[1]);
  int y = atof(argv[1]);  
  printf("First argument as an int = %d, second arg as a double is = %f\n", x, y); 
  
  return 0;
}
