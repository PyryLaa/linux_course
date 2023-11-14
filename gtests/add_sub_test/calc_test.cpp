#include <gtest/gtest.h>
#include "calc.hpp"


TEST(CalcTest, Add){
  ASSERT_EQ(2, add(1, 1));
  ASSERT_EQ(4, add(3, 1));
  ASSERT_EQ(10, add(4, 6));
}

TEST(CalcTest, Sub){
  ASSERT_EQ(0, sub(3, 3));
  ASSERT_EQ(20, sub(50, 30));
  ASSERT_EQ(-30, sub(0, 30));
}

int main(int argc, char* argv[]){
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
