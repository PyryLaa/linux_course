/*Program to copy 
contents of one file
to another */

#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096 //Max amount of data to be copied at one time
#define OUTPUT_MODE 0700 //Give the output file r/w/exec permissions

int main(int argc, char *argv[]){
  int file_in, file_out, read_cnt, write_cnt; //File descriptors and r/w counters
  char buffer[BUFFER_SIZE]; //Hold the data for copying
  
  if(argc != 3){ //If invalid amount of arguments, terminate
    exit(1);
  }

  file_in = open(argv[1], O_RDONLY);
  if(file_in < 0){ //If opening of original file failed, terminate
    exit(2);
  }

  file_out = creat(argv[2], OUTPUT_MODE);
  if(file_out < 0){ //If creating the new file failed, terminate
    exit(3);
  }

  while(1){
    read_cnt = read(file_in, buffer, BUFFER_SIZE);

    if(read_cnt <= 0){ //File read complete or error occurred, break the loop
      break;
    }

    write_cnt = write(file_out, buffer, read_cnt);
    if(write_cnt <= 0){ //Write returns <= 0 only on error, terminate
      exit(4);
    }
  }

  //Close files
  close(file_in);
  close(file_out);

  if(read_cnt == 0){ //Last read succesful
    exit(0);
  }else{
    exit(5); //Last read encountered error
  }
  
  
}
