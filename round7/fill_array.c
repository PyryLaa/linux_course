#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define MAX_ARR_SIZE 100000000

int main(int argc, char *argv[]){
  int *arr = (int*)malloc(MAX_ARR_SIZE * sizeof(int));

  for(int i = 0; i <= MAX_ARR_SIZE; i++){
    arr[i] = i;
  }
  if(argc == 1){
    for(int j = MAX_ARR_SIZE - 100; j <= MAX_ARR_SIZE; j++){
      printf("%d\n", arr[j]);
    } 
  }
  return 0;
}
