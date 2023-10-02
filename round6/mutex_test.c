#include <stdio.h>
#include <stdint.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

pthread_mutex_t lock; //Mutex lock for threads
int counter = 0;
void *incrementer();

int main(void){
  pthread_t threads[2];
  int status = 0;
  
  if(pthread_mutex_init(&lock, NULL) != 0){ //Init mutex and check the return val
    printf("Mutex initialization failed\n");
    exit(1);
  }
  
  for(int i = 0; i < 2; i++){
    status = pthread_create(&(threads[i]), NULL, &incrementer, NULL); //Create threads

     if(status != 0){
       printf("Thread creation failed");
       exit(1);
     }
  }
  pthread_join(threads[0], NULL);
  pthread_join(threads[1], NULL);
  pthread_mutex_destroy(&lock);
  
}

void *incrementer(){
  pthread_mutex_lock(&lock); //Lock the mutex lock, so only the working thread may increment counter which is global in this case
  unsigned long int i = 0;
  counter += 1;

  printf("Thread %d working.\n", counter);
  for (i; i < (0xFFFFFFFF); i++); //Just to simulate some work to be done
  printf("Thread %d done.\n", counter);
  
  pthread_mutex_unlock(&lock); //Release the lock so another threads may continue
  
  return EXIT_SUCCESS;
  
}
