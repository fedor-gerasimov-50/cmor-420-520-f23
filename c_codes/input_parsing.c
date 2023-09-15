#include <stdio.h>
#include <stdlib.h> // for atoi, atof
#include <string.h> // for strlen

int main(int argc, char * argv[]){

  printf("There are %d input arguments.\n", argc);
  for (int i = 0; i < argc; ++i){
    printf("Argument %d: %s\n", i, argv[i]);
  }

  printf("The length of the last argument is %lu\n", strlen(argv[argc-1]));

  printf("The last argument interpreted as an integer is %d\n", atoi(argv[argc-1]));
  
  printf("The last argument interpreted as a double is %f\n", atof(argv[argc-1]));  
  
  return 0;
}
