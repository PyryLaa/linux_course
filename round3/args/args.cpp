#include <iostream>

int main(int argc, char* argv[]){
  int count = argc;
  std::cout << "Komentoriviargumentteja: " << count - 1 << " kpl" << std::endl;
  std::cout << "Ja ne ovat:" << std::endl;

  for (int i = 0; i <= count; i++){
    std::cout << argv[i+1] << std::endl;
  }
  return EXIT_SUCCESS;
}
