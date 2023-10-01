#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

#define NO_OF_THREADS 10

void *print_hello_world(void*);

int main(void){
  pthread_t threads[NO_OF_THREADS];
  int status;

  for(int i = 0; i < NO_OF_THREADS; i++){
    printf("Creating thread %d\n", i);
    status = pthread_create(&threads[i], NULL, print_hello_world, (void*)i);
    pthread_join(threads[i], NULL);
    if(status != 0){
      printf("pthread returned error: %d\n", status);
    }
  }
  exit(NULL);
}

void *print_hello_world(void* thread_id){
  printf("Hello from thread %d\n", thread_id);
  pthread_exit(NULL);
}
