#include <iostream>
#include <gtest/gtest.h>
#include "date.hpp"

TEST(DateClass, defaultConstructor){
  Date date;

  //Check if data was constructed correctly with def constructor
  EXPECT_EQ(1, date.getDay());
  EXPECT_EQ(1, date.getMonth());
  EXPECT_EQ(1970, date.getYear());
}

TEST(DateClass, setters){
  Date date;

  date.setDay(20);
  date.setMonth(10);
  date.setYear(2020);

  EXPECT_EQ(20, date.getDay());
  EXPECT_EQ(10, date.getMonth());
  EXPECT_EQ(2020, date.getYear());
}

TEST(DateClass, nextDay){
  Date date;

  date.setDay(31);
  date.setMonth(12);
  date.setYear(2020);

  date.nextDay();
  EXPECT_EQ(1, date.getDay());
  EXPECT_EQ(1, date.getMonth());
  EXPECT_EQ(2021, date.getYear());
  
}

TEST(DateClass, weekLater){
  Date date;

  date.setDay(28);
  date.setMonth(3);
  date.setYear(1995);

  date.weekLater();
  EXPECT_EQ(4, date.getDay());
  EXPECT_EQ(4, date.getMonth());
  EXPECT_EQ(1995, date.getYear());
}

int main(int argc, char* argv[]){

  /*  Date today(14, 11, 2023);
  std::cout << "The date is: ";
  today.printDate();
  std::cout << "The next day is: ";
  today.nextDay();
  std::cout << "Date week later is:";
  today.weekLater();

  Date somedate;
  somedate.askDate();*/

  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
