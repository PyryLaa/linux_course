#include "date.hpp"
#include <iostream>
#include <string>



Date::Date (){
  day = 1;
  month = 1;
  year = 1970;
}

Date::Date(int m_day, int m_month, int m_year) : day(m_day), month(m_month), year(m_year) {};

bool Date::isLeapYear() const{
  bool flag;

  if(year % 400 == 0){ //Leap year if divisible by 400
    flag = true;
  }else if(year % 100 == 0){ //Not a leap year if not divisible by 400 but divisible by 100
    flag = false;
  }else if(year % 4 == 0){ //Leap year if not divisible by 400 and 100 but divisible by 4
    flag = true;
  }else{
    flag = false;
  }

  return flag;
}

void Date::setDay(int m_day){
  day = m_day;
}

void Date::setMonth(int m_month){
  month = m_month;
}

void Date::setYear(int m_year){
  year = m_year;
}

int Date::getDay() const{
  return day;
}

int Date::getMonth() const{
  return month;
}

int Date::getYear() const{
  return year;
}

void Date::printDate() const{
  std::cout << day << '/' << month << '/' << year << std::endl;
}

void Date::weekLater() {
  int month_days;
  if(month == 2 && !isLeapYear()){ //Feb without leap year
    month_days = 28;
  }else if(month == 2 && isLeapYear()){ //Feb with leap year
    month_days = 29;
  }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //Jan, Mar, May, July, Aug, Oct, Dec
    month_days = 31;
  }else{ //April, June, Sept, Nov
    month_days = 30;
  }
  
  day = day + 7;
  if(day > month_days){
    if(month == 12){
      year++;
      month = 1;
    }
    month++;
    day = day - month_days;
  }

  printDate();
}

void Date::nextDay(){
  int month_days;
  day++;
  if(month == 2 && !isLeapYear()){ //Feb without leap year
    month_days = 28;
  }else if(month == 2 && isLeapYear()){ //Feb with leap year
    month_days = 29;
  }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //Jan, Mar, May, July, Aug, Oct, Dec
    month_days = 31;
  }else{ //April, June, Sept, Nov
    month_days = 30;
  }
  
  if(day > month_days){
    if(month == 12){
      year++;
      month = 1;
    }
    month++;
    day = day - month_days;
  }
  
  printDate();

}

void Date::askDate(){
  int month_days;

  std::cout << "Give the year: ";
  std::cin >> year;

  do{
    std::cout << "Give the month: ";
    std::cin >> month;
  }while(month > 12 || month < 1);
  
  if(month == 2 && !isLeapYear()){ //Feb without leap year
    month_days = 28;
  }else if(month == 2 && isLeapYear()){ //Feb with leap year
    month_days = 29;
  }else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){ //Jan, Mar, May, July, Aug, Oct, Dec
    month_days = 31;
  }else{ //April, June, Sept, Nov
    month_days = 30;
  }

  do{
    std::cout << "Give the day: ";
    std::cin >> day;
  }while(day > month_days ||day < 1);
  
}
