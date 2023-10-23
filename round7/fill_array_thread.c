/*Program to fill 100 million integer array
  with threads*/

#include <stdio.h>
#include <pthread.h>
#include <errno.h>
#include <stdlib.h>
#include <stdint.h>

#define ARR_SIZE 100000000
#define THREAD_AMOUNT 10

void *fill_array(void *data);

int *pArr;

typedef struct{ //Struct to hold data for the threads
  int thid;
  int start;
  int end;
} ThreadData;

int main(int argc, char *argv[]){
  
  int* arr = (int*)malloc(ARR_SIZE * sizeof(int));
  pthread_t threads[THREAD_AMOUNT];
  ThreadData thread_data[THREAD_AMOUNT]; //Array for every thread's data
  
  intptr_t status;
  int thread_elements = ARR_SIZE / THREAD_AMOUNT;
  
  pArr = arr;

  for(int i = 0; i < THREAD_AMOUNT; i++){
    thread_data[i].thid = i;
    thread_data[i].start = i * thread_elements; //Starting index for thread to fill the array
    if(i == THREAD_AMOUNT - 1){
      thread_data[i].end = ARR_SIZE;
    }else{
      thread_data[i].end = ((i+1)*thread_elements) - 1;
    }
    
    status = pthread_create(&threads[i], NULL, fill_array, &thread_data[i]);
    if(status != 0){
      perror("Thread creation failed: ");
      printf("%d", errno);
    }
  }
  for(int i = 0; i < THREAD_AMOUNT; i++){
   status = pthread_join(threads[i], NULL);
   if(status != 0){
     perror("Thread joining failed: ");
     printf("%d", errno);
   }
  }
  if(argc < 2){
    for(int i = ARR_SIZE - 100; i < ARR_SIZE; i++){
      printf("%d\n", arr[i]);
    }
  }
  free(arr);
  return 0;
}

void *fill_array(void* data){
  ThreadData* thdata = (ThreadData*)data;
  int start = thdata -> start;
  int end = thdata -> end;

  for(int i = start; i < end; i++){
    pArr[i] = i;
  }
  pthread_exit(NULL);
}
