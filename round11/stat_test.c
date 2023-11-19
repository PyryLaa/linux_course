#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
  if(argc < 2 || argc > 2){
    printf("Invalid amount of arguments.\n");
    exit(1);
  }

  struct stat st;
  stat(argv[1], &st);

  printf("File size in bytes: %ld\n", st.st_size);
  printf("Device id: %ld\n", st.st_dev);
  printf("Inode number: %ld\n", st.st_ino);
  printf("File type and mode: %u\n", st.st_mode);
  printf("Amount of hard links to file: %ld\n", st.st_nlink);
  printf("Owner's user id: %u\n", st.st_uid);
  printf("Owner's group id: %u\n", st.st_gid);
  printf("Block size for filesystem I/O: %ld\n", st.st_blksize);
  printf("Amount of 512B blocks allocated for file: %ld\n", st.st_blocks);
  return 0;
}
