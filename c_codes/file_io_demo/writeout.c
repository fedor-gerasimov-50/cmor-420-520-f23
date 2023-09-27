#include <stdio.h>
#include <stdlib.h>

// This file is an example of how to write output
// to a file.
int main(int argc, char ** argv){
  FILE *fp;

  // open an output file
  fp = fopen("out.txt", "w+");
  fprintf(fp, "Writing output using fprintf...\n");
  char * string = "Writing output using fputs...\n";
  fputs(string, fp);
  fclose(fp);

  // now write a block of memory to a binary file
  fp = fopen("out.bin", "w+");
  int n = 1;
  int * x = (int *) malloc(sizeof(int) * n);
  x[0] = 13;
  fwrite(x, sizeof(int), n, fp);
  fclose(fp);

  // change x[0]
  x[0] = 42;

  // re-read out.bin into x
  fp = fopen("out.bin", "r");    
  fread(x, sizeof(int), n, fp);
  fclose(fp);

  printf("x[0] = %d\n", x[0]);

  
}
