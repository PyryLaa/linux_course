#pragma once

class Date{
 private:
  int day, month, year;
  bool isLeapYear() const;
 public:

  Date();
  Date(int day, int month, int year);

  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);

  int getDay() const; //Const to not allow this method to modify data
  int getMonth() const;
  int getYear() const;

  void printDate() const;
  void weekLater();
  void nextDay();
  void askDate();
  
};
