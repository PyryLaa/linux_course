#include <stdio.h>
#include <stdlib.h>

int main(void){
  const int ARR_SIZE = 10;
  int* ptr = (int*)malloc(ARR_SIZE*sizeof(int));

  if (ptr == NULL){
    printf("Memory allocation failed\n");
  }else{
    for(int i = 0; i < ARR_SIZE; i++){
      ptr[i] = i + 1;
    }
    for(int i = 0; i < ARR_SIZE; i++){
      printf("%d\n", ptr[i]);
    }
  }
  free(ptr);
  return EXIT_SUCCESS;
}
