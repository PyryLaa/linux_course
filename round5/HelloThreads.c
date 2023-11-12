#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdint.h>

#define NO_OF_THREADS 10

void *print_hello_world(void*);

int main(void){
  pthread_t threads[NO_OF_THREADS];
  intptr_t status;

  for(intptr_t i = 0; i < NO_OF_THREADS; i++){
    printf("Creating thread %ld\n", i);
    status = pthread_create(&threads[i], NULL, print_hello_world, (void*)i);

    if(status != 0){
      printf("pthread returned error: %ld\n", status);
    }
  }
  return EXIT_SUCCESS;
}

void *print_hello_world(void* thread_id){
  printf("Hello from thread %ld\n", (intptr_t)thread_id);
  pthread_exit(NULL);
}
