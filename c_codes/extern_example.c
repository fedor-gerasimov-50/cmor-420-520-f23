#include <stdio.h>

/* 
Multi-line 
comment
*/

// Define and declare a variable outside the function
double x;

int main(void){
    // Define, declare, and initialize a variable
    int y = 1;
    printf("y = %d\n", y);
    
    // Declared (extern is similar to a global variable)
    extern double x;
    
    // Initialized
    x = 10.1;
    printf("x = %f\n", x);

    // double precision
    double z = 2.0;
    printf("x * z = %f\n", x * z);
}
