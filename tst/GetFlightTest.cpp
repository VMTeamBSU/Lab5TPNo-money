

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(test31, timesType) {

	char*** result;
	char** names = NULL;
	int b = 0;
	int c = 0;
	result = GetFlightInformation("Special", &names, &b, &c);
	EXPECT_STREQ(result[0][0], "2");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "2");
	EXPECT_STREQ(result[0][3], "20");
	EXPECT_STREQ(result[0][4], "3");
	EXPECT_STREQ(result[0][5], "5");
	EXPECT_STREQ(result[0][6], "12000");
	EXPECT_STREQ(result[0][7], "yes");
	EXPECT_STREQ(result[1][0], "5");
	EXPECT_STREQ(result[1][1], "2020-02-05");
	EXPECT_STREQ(result[1][2], "4");
	EXPECT_STREQ(result[1][3], "1");
	EXPECT_STREQ(result[1][4], "7");
	EXPECT_STREQ(result[1][5], "7");
	EXPECT_STREQ(result[1][6], "1375");
	EXPECT_STREQ(result[1][6], "yes");
	EXPECT_STREQ(result[2][0], "7");
	EXPECT_STREQ(result[2][1], "2020-02-08");
	EXPECT_STREQ(result[2][2], "2");
	EXPECT_STREQ(result[2][3], "17");
	EXPECT_STREQ(result[2][4], "20");
	EXPECT_STREQ(result[2][5], "10");
	EXPECT_STREQ(result[2][6], "1400");
	EXPECT_STREQ(result[2][6], "yes");
	EXPECT_STREQ(result[2][0], "7");
	EXPECT_STREQ(result[2][1], "2020-02-08");
}
TEST(test31, timesType) {

	char*** result;
	char** names = NULL;
	int b = 0;
	int c = 0;
	result = GetFlightInformation("Special", &names, &b, &c);
	EXPECT_STRNE(result[0][0], "0");
	EXPECT_STRNE(result[0][1], "2020-02-11");
	EXPECT_STRNE(result[0][2], "2");
	EXPECT_STRNE(result[0][3], "20");
	EXPECT_STRNE(result[0][4], " ");
	EXPECT_STRNE(result[0][5], "5");
	EXPECT_STRNE(result[0][6], "12000");
	EXPECT_STRNE(result[0][7], "no");
	EXPECT_STRNE(result[1][0], "5");
	EXPECT_STRNE(result[1][1], "2020-02-05");
	EXPECT_STRNE(result[1][2], "4");
	EXPECT_STRNE(result[1][3], "1");
	EXPECT_STRNE(result[1][4], "G");
	EXPECT_STRNE(result[1][5], "7");
	EXPECT_STRNE(result[1][6], "1375");
	EXPECT_STRNE(result[1][6], "Yes");
	EXPECT_STRNE(result[2][0], "7");
	EXPECT_STRNE(result[2][1], "2020-02-08");
	EXPECT_STRNE(result[2][2], "2");
	EXPECT_STRNE(result[2][3], "17");
	EXPECT_STRNE(result[2][4], "0");
	EXPECT_STRNE(result[2][5], "10");
	EXPECT_STRNE(result[2][6], "1400");
	EXPECT_STRNE(result[2][6], "yes");
	EXPECT_STRNE(result[2][0], "7");
	EXPECT_STRNE(result[2][1], "2020-02-08");
}



