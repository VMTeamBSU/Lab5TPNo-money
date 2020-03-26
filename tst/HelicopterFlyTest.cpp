#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(1, b, &c, &d);
	EXPECT_STREQ(result[0][0], "9");
	EXPECT_STREQ(result[0][1], "1086");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(1, b, &c, &d);
	EXPECT_STRNE(result[0][0], "7");
	EXPECT_STRNE(result[0][1], "1");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(2, b, &c, &d);
	EXPECT_STREQ(result[0][0], "15");
	EXPECT_STREQ(result[0][1], "985");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(2, b, &c, &d);
	EXPECT_STRNE(result[0][0], "-1");
	EXPECT_STRNE(result[0][1], "891");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(3, b, &c, &d);
	EXPECT_STREQ(result[0][0], "4");
	EXPECT_STREQ(result[0][1], "1006");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(3, b, &c, &d);
	EXPECT_STRNE(result[0][0], "5");
	EXPECT_STRNE(result[0][1], "1001");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(4, b, &c, &d);
	EXPECT_STREQ(result[0][0], "15");
	EXPECT_STREQ(result[0][1], "995");
}
TEST(testHelicopterFly, testingvalidResourse) {

	char*** result;
	int** ID = NULL;
	char*** b = 0;
	int c = 0;
	int d = 0;
	result = HelicopterFlyDurationAndFlyingResourse(4, b, &c, &d);
	EXPECT_STRNE(result[0][0], "5");
	EXPECT_STRNE(result[0][1], "101");
}