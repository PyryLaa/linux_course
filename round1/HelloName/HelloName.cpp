#include <iostream>

int main(int argc, char* argv[]){
  if (argc != 2){
    std::cout << "Invalid amount of arguments, please give only 1 name!\n";
  }
  else{
    std::cout <<"Hello " << argv[1] << "\n";
  }
  return 0;
}
