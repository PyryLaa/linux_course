#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main(void){
  int file = open("rw_test.txt", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
  char in;
  

  if(file == -1){
    perror("Error: ");
    printf("Error code: %d\n", errno);
  }else{
    printf("Give character to write to file: ");
    scanf("%1c", &in);
    if(write(file, &in, sizeof(char)) == -1){
      perror("Writing failed: ");
      printf("Error code: %d\n", errno);
    };
  }
  if(close(file) == -1){
    perror("File closing failed: ");
    printf("Error code: %d\n", errno);
  };

  return 0;
}




