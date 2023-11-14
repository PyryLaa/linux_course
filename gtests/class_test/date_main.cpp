#include <iostream>
#include "date.hpp"

int main(){

  Date today(14, 11, 2023);
  std::cout << "The date is: ";
  today.printDate();
  std::cout << "The next day is: ";
  today.nextDay();
  std::cout << "Date week later is:";
  today.weekLater();

  Date somedate;
  somedate.askDate();
  return 0;
}
