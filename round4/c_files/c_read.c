#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){
  int file = open("rw_test.txt", O_RDONLY);
  char read_buf;
  if(file == -1){
    perror("File open failed: ");
    printf("Error code: %d\n", errno);
    exit(-1);
  }else{
    if(read(file, &read_buf, sizeof(char)) == -1){
      perror("Reading file failed: ");
      printf("Error code: %d\n", errno);
      exit(-1);
    }else{
      printf("Character from file: %c\n", read_buf);
    }
  }
  if(close(file) == -1){
    perror("Error closing the file: ");
    printf("Error code: %d\n", errno);
  }
  return 0;
  
}
