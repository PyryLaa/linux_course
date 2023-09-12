#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  const char* args[] = {"/bin/ls", NULL};
  const char* envs[] = {NULL};

  int status;

  if(fork() != 0){
    waitpid(-1, &status, 0);
    std::cout << status << std::endl;
  }else{
    execve("/bin/ls", const_cast<char**>(args), const_cast<char**>(envs));
  }
  return EXIT_SUCCESS;
}
