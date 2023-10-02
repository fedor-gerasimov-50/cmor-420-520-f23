#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This demo is an example of how to use fgets to read
// in ASCII input from a file.

int main(int argc, char ** argv){

  /*
  FILE * fp = fopen("in.txt", "r");
  
  char buffer[BUFSIZ];

  fgets(buffer, BUFSIZ, fp);
  printf("First line read by fgets: %s\n", buffer);
  
  fgets(buffer, BUFSIZ, fp);
  printf("Second line read by fgets: %s\n", buffer);
  
  fclose(fp);
  */
  
  
  /*
    int x;
  char c;
  printf("Enter an int and a char, separated "
	 "by a space:\n");	 
  scanf("%d %c", &x, &c);
  printf("Scanned variables: x = %d, c = %c\n", x, c);
  */
  // use sscanf to parse a date  

  int day, month;
  char year[2];  
  char tmp[BUFSIZ];

  sscanf("Date: 9/29/23", "%s %d/%d/%s",
	 tmp, &month, &day, year);
  printf("Day, month, year = %d, %d, %s\n",
	 day, month, year); 

}
