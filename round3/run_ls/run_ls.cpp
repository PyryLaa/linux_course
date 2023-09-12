#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
  const char* args[] = {"/bin/ls", NULL};
  const char* envs[] = {NULL};

 
  execve("/bin/ls", const_cast<char**>(args), const_cast<char**>(envs));
  
  return EXIT_SUCCESS;
}
