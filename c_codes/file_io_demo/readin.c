#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This demo is an example of how to use fgets to read
// in ASCII input from a file.

int main(int argc, char ** argv){

  FILE * fp = fopen("in.txt", "r");
  
  char buffer[BUFSIZ];

  fgets(buffer, BUFSIZ, fp);
  printf("First line read by fgets: %s\n", buffer);
  
  fgets(buffer, BUFSIZ, fp);
  printf("Second line read by fgets: %s\n", buffer);
  
  fclose(fp);
  /*
  int x;
  char c;
  printf("Enter an int and a char, separated "
	 "by a space:\n");	 
  scanf("%d %c", &x, &c);
  printf("Scanned variables: x = %d, c = %c\n", x, c);
  */

  char str[BUFSIZ];
  printf("Enter a single word:\n");
  scanf("%s", str);
  printf("The word entered is: %s\n", str);

  int day, month;
  char year_end[2];  
  char tmp[BUFSIZ];

  sscanf("Date: 9/29/23",
	 "%s %d/%d/%s", tmp, &day, &month, year_end);

  char year[BUFSIZ];
  sprintf(year, "20%s", year_end);
  printf("Day, month, year = %d, %d, %s\n",
	 day, month, year);

}
