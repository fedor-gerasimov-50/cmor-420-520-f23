#include <stdio.h>
#include <stdlib.h>


// this function  returns 0 if a==b, a positive number
// if a is greater than b, negative if a is less than b
int compare(const void * a, const void * b){
  return ( *(int*)a - *(int*)b ); 
}
  
int main(){
  int arr[] = {10, 5, 15, 12, 90, 80};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  qsort(arr, n, sizeof(arr[0]), compare);
  
  for (int i=0; i<n; i++){
    printf ("%d ", arr[i]);
  }
  printf("\n");
  
  return 0;
}
