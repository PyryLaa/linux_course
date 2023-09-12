#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  const char* envs[] = {NULL};
  const char* args[argc-1];
  for(int i = 0; i < argc; i++){
    args[i] = argv[i+1];
  }
  int status;
  const char * path = args[0];
  if(fork() != 0){
    waitpid(-1, &status, 0);
  }else{
    execve(path, const_cast<char**>(args), const_cast<char**>(envs));
  }
  return EXIT_SUCCESS;
}
