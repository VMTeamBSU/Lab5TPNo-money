

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(testAllHelicopters, testingvalidAllHelicopters) {

	char*** result;
	char** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllHelicopters(&all, &b, &c);

	EXPECT_STREQ(result[0][0], "MI-26");
	EXPECT_STREQ(result[0][1], "2");
	EXPECT_STREQ(result[0][2], "2011-02-23");
	EXPECT_STREQ(result[0][3], "20");
	EXPECT_STREQ(result[0][4], "2020-02-23");
	EXPECT_STREQ(result[0][5], "1095");
	EXPECT_STREQ(result[1][0], "MI-26");
	EXPECT_STREQ(result[1][1], "2");
	EXPECT_STREQ(result[1][2], "2014-11-11");
	EXPECT_STREQ(result[1][3], "20");
	EXPECT_STREQ(result[1][4], "2020-11-11");
	EXPECT_STREQ(result[1][5], "1000");
	EXPECT_STREQ(result[2][1], "MI-171");
	EXPECT_STREQ(result[2][2], "3");
	EXPECT_STREQ(result[2][3], "2014-12-09");
	EXPECT_STREQ(result[2][4], "4");
	EXPECT_STREQ(result[2][5], "1010");
	EXPECT_STREQ(result[3][0], "MI-171");
	EXPECT_STREQ(result[3][1], "3");
	EXPECT_STREQ(result[3][2], "2014-12-09");
	EXPECT_STREQ(result[3][3], "4");
	EXPECT_STREQ(result[3][4], "2014-12-09");
	EXPECT_STREQ(result[3][5], "1010");
	EXPECT_STREQ(result[4][0], "MI-38");
	EXPECT_STREQ(result[4][1], "4");
	EXPECT_STREQ(result[4][2], "2017-12-09");
	EXPECT_STREQ(result[4][3], "6");
	EXPECT_STREQ(result[4][4], "2020-12-09");
	EXPECT_STREQ(result[4][5], "1010");
}
TEST(testAllHelicopters, testinginvalidAllHelicopter) {

	char*** result;
	char*** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllHelicopters(all, &b, &c);


	EXPECT_STRNE(result[0][0], "MI-26");
	EXPECT_STRNE(result[0][1], "2");
	EXPECT_STRNE(result[0][2], "2011-02-23");
	EXPECT_STRNE(result[0][3], "20");
	EXPECT_STRNE(result[0][4], "2020-02-23");
	EXPECT_STRNE(result[0][5], "1095");
	EXPECT_STRNE(result[1][0], "MI-26");
	EXPECT_STRNE(result[1][1], "2");
	EXPECT_STRNE(result[1][2], "2014-11-11");
	EXPECT_STRNE(result[1][3], "20");
	EXPECT_STRNE(result[1][4], "2020-11-11");
	EXPECT_STRNE(result[1][5], "1000");
	EXPECT_STRNE(result[2][1], "MI-171");
	EXPECT_STRNE(result[2][2], "3");
	EXPECT_STRNE(result[2][3], "2014-12-09");
	EXPECT_STRNE(result[2][4], "4");
	EXPECT_STRNE(result[2][5], "1010");
	EXPECT_STRNE(result[3][0], "MI-171");
	EXPECT_STRNE(result[3][1], "3");
	EXPECT_STRNE(result[3][2], "2014-12-09");
	EXPECT_STRNE(result[3][3], "4");
	EXPECT_STRNE(result[3][4], "2014-12-09");
	EXPECT_STRNE(result[3][5], "1010");
	EXPECT_STRNE(result[4][0], "MI-38");
	EXPECT_STRNE(result[4][1], "4");
	EXPECT_STRNE(result[4][2], "2017-12-09");
	EXPECT_STRNE(result[4][3], "6");
	EXPECT_STRNE(result[4][4], "2020-12-09");
	EXPECT_STRNE(result[4][5], "1010");
}


