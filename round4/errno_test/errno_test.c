#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){
  int file = open("somefile.txt", O_RDONLY);
  if (file == -1){
    printf("Error number: %d\n", errno);
    perror("Error message ");
  }
  return 0;
}
