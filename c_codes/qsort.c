#include <stdio.h>
#include <stdlib.h>


// this function  returns 0 if a==b, a positive number
// if a is greater than b, negative if a is less than b
int compare(const void * a, const void * b){
  return ( *(int*)a - *(int*)b ); 
}

int compare_vectors(const void * a, const void * b){
  const int * x = *(int (*)[2]) a;
  const int * y = *(int (*)[2]) b;

  if (x[0]==y[0]){
    return x[1] - y[1];
  } else {
    return x[0] - y[0];
  }
}

int main(){
  //int arr[] = {10, 5, 15, 12, 90, 80};
  int arr[][2] = {{1,2}, {3,2}, {1,5}, {2,4}};
  int n = sizeof(arr) / sizeof(arr[0]);
  
  //qsort(arr, n, sizeof(arr[0]), compare);
  qsort(arr, n, sizeof(arr[0]), compare_vectors);
  
  for (int i = 0; i < n; ++i){
    //printf("%d ", arr[i]);
    printf("{%d %d}, ", arr[i][0], arr[i][1]);
  }
  printf("\n");
  
  return 0;
}
