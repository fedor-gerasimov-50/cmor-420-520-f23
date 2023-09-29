#include <stdio.h>
#include <stdlib.h>

// This file is an example of how to write output
// to a file.
int main(void){

  // print ASCII formatted output to file
  FILE * fp = fopen("out.txt", "w");

  int n = 10;
  double * x = (double *) malloc(sizeof(double) * n);
  for (int i = 0; i < n; ++i){
    fprintf(fp, "%f\n", x[i]);
  }

  fclose(fp);

  // printing binary to file
  fp = fopen("out.bin", "w");

  // write out x[0] = 13
  x[0] = 13;
  fwrite(x, sizeof(double), n, fp);

  fclose(fp);
  
  // modify x[0]
  x[0] = 42;

  // read in x[0] again to over-write x[0]
  fp = fopen("out.bin", "r");  
  fread(x, sizeof(double), n, fp);  
  fclose(fp);  

  printf("x[0] = %f\n", x[0]); 

  
  return 0;
}
