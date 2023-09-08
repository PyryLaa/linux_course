#include <iostream>

int main(){
  uint8_t a = 25;
  uint16_t b = 340;
  int8_t c = -10;

    if (c < a){
      std::cout << +c << " is less than " << +a << std::endl;
    }
 

  for(uint8_t i = 0; i < 255; i++){
    b--;
  }
  
  std::cout << "Hello world!" << std::endl;
  return 0;
}
