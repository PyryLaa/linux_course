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
  char* args[3]; //args to execve
  int status;
  std::vector<std::string> parsed;
  while(true){
    std::string command = type_prompt();
    if (command.empty()){
      break;
    }
  
    if(fork() != 0){
      
      waitpid(-1, &status, 0);      
    }else{
      std::string temp = ""; //String to store parsed options from user
      parse_command(command, parsed);
      char * path = const_cast<char*>(parsed[0].c_str());
      args[0] = path;

      for (int i = 1; i < parsed.size(); i++){
	temp = temp + parsed[i];
	temp = temp + " ";
      }
      args[1] = const_cast<char*>(temp.c_str());
      args[2] = NULL;
      
      
      execve(args[0], &args[1], envs);
    }
    parsed.clear();

  }
  return EXIT_SUCCESS;
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
  unsigned int parsed_size = parsed.size();
  
  while (std::getline(str_s, command, ' ')){
    parsed.push_back(command);
  }
}
