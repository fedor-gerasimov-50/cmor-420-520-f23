#include <stdio.h>

// Define and declare a variable outside the function
double x;

#define PI 3.14159

int main(void){
    // Define, declare, and initialize a variable
    int y = 1;
    printf("y = %d\n", y);
    
    // Declare a global variable
    extern double x;
    
    // Initialize the global variable
    x = 10.1;
    printf("x = %f\n", x);

    // A macro is different from a global variable because it is a "preprocessor directive"
    printf("pi = %f\n", PI);
    // PI = 3.14; cannot assign a value to this because it's not a variable
}
