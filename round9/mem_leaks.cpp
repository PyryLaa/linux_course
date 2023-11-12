#include <iostream>

//void ptr_test();

int main(){
  /* Try to store a value to an unitialized pointer*/
  
  // int *ptr;
  // *ptr = 5;

  /* Try to store a value to a null pointer*/
  
  // int *nptr = NULL;
  // *nptr = 4;

  /*Create a pointer in a function, but don't delete it*/
  // ptr_test();

  /* Create an array and try to over-index it */
  int *ptr_arr = new int[5];
  ptr_arr[5] = 3;
  delete []ptr_arr;
  return 0;
}

/*void ptr_test(){
  
  int* test_ptr = new int;
}*/
