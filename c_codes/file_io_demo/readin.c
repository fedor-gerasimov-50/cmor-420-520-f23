#include <stdio.h>
#include <stdlib.h>

// This demo is an example of how to use fgets to read
// in ASCII input from a file.

int main(int argc, char ** argv){
  
  char buff[BUFSIZ];
  FILE *fp = fopen("in.txt", "r");
  fgets(buff, BUFSIZ, fp);
  printf("First line read by fgets: %s\n", buff);
  fgets(buff, BUFSIZ, fp);
  printf("Second line read by fgets: %s\n", buff);
  fclose(fp);
  
}
