#include <iostream>
#include <sstream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string>
#include <vector>

std::string type_prompt();
void parse_command(std::string&, std::vector<std::string>&);

int main(){
  char* envs[] = {NULL}; //Env variables to execve, null = same as host
  char* args[2] = {NULL, NULL}; //args to execve
  int status;
  std::vector<std::string> parsed;

  while(true){
    std::string command = type_prompt();

    if (command.empty()){
      break;
    }

    
    parse_command(command, parsed);
    char * path = const_cast<char*>(parsed[0].c_str());
    args[0] = const_cast<char*>(command.c_str());
    
    
    
    
    if(fork() != 0){
      waitpid(-1, &status, 0);      
    }else{
      execve(path, (char* const*)args, envs);
    }
    //parsed.clear();

  }
  //return EXIT_SUCCESS;
}

std::string type_prompt(){

  std::string command;
  
  std::cout << "Give command to run: ";
  std::getline(std::cin, command);
  
  
  return command;
}

void parse_command(std::string &com, std::vector<std::string> &parsed){

  std::stringstream str_s(com);
  std::string command;
  
  while (std::getline(str_s, command, ' ')){
    parsed.push_back(command);
  }
}
