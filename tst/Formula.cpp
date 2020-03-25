#include "gtest/gtest.h"
extern  "C" {
#include "../include/UIController.h"
}

TEST(TryLoginFuncTest, timesType) {
    //arrange
    //act
    //assert
    UiControllerInit();
    EXPECT_EQ (TryLogin("user1","1234"),  -1);
    EXPECT_EQ(TryLogin("admin", "1234"), -1);
    EXPECT_EQ(TryLogin("admin", "12345"), -1);
    EXPECT_EQ(TryLogin("admin", "1111"), -2);
}

TEST(TryLogin, correctLogin) {
    //arrange
    //act
    //assert
    UiControllerInit();
    EXPECT_EQ(TryLogin("admin", "1234"), -1);
    EXPECT_EQ(TryLogin("user1", "1111"), -1);
    EXPECT_EQ(TryLogin("admin", "1111"), 1);
}

