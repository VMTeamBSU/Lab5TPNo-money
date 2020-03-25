

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(test31, timesType) {

	char*** result;
	char** special = NULL;
	int b = 0;
	int c = 0;
	int d = 0;
	result = GetFlightInformation(1, &b, &c, &d);
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
	char**special = NULL;
	int b = 0;
	int c = 0;
	int d = 0;
	result = GetFlightInformation(1, &b, &c, &d);
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
TEST(test31, timesType) {

	char*** result;
	char** special = NULL;
	int b = 0;
	int c = 0;
	int d = 0;
	result = GetFlightInformation(0, &b, &c, &d);
	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "1");
	EXPECT_STREQ(result[0][3], "12");
	EXPECT_STREQ(result[0][4], "5");
	EXPECT_STREQ(result[0][5], "2");
	EXPECT_STREQ(result[0][6], "5000");
	EXPECT_STREQ(result[0][7], "no");
	EXPECT_STREQ(result[1][0], "3");
	EXPECT_STREQ(result[1][1], "2020-02-02");
	EXPECT_STREQ(result[1][2], "4");
	EXPECT_STREQ(result[1][3], "4");
	EXPECT_STREQ(result[1][4], "8");
	EXPECT_STREQ(result[1][5], "3");
	EXPECT_STREQ(result[1][6], "5600");
	EXPECT_STREQ(result[1][6], "no");
	EXPECT_STREQ(result[2][0], "4");
	EXPECT_STREQ(result[2][1], "2020-02-04");
	EXPECT_STREQ(result[2][2], "3");
	EXPECT_STREQ(result[2][3], "3");
	EXPECT_STREQ(result[2][4], "3");
	EXPECT_STREQ(result[2][5], "2");
	EXPECT_STREQ(result[2][6], "4050");
	EXPECT_STREQ(result[2][6], "no");
}
TEST(test31, timesType) {

	char*** result;
	char** special = NULL;
	int b = 0;
	int c = 0;
	int d = 0;
	result = GetFlightInformation(0, &b, &c, &d);
	EXPECT_STRNE(result[0][0], "0");
	EXPECT_STRNE(result[0][1], "2020-11-01");
	EXPECT_STRNE(result[0][2], " ");
	EXPECT_STRNE(result[0][3], "12");
	EXPECT_STRNE(result[0][4], "5");
	EXPECT_STRNE(result[0][5], "2");
	EXPECT_STRNE(result[0][6], "5000");
	EXPECT_STRNE(result[0][7], "Yes");
	EXPECT_STRNE(result[1][0], "3");
	EXPECT_STRNE(result[1][1], "2020-02-02");
	EXPECT_STRNE(result[1][2], "4");
	EXPECT_STRNE(result[1][3], "-1");
	EXPECT_STRNE(result[1][4], "G");
	EXPECT_STRNE(result[1][5], "3");
	EXPECT_STRNE(result[1][6], "5600");
	EXPECT_STRNE(result[1][6], "no");
	EXPECT_STRNE(result[2][0], "0");
	EXPECT_STRNE(result[2][1], "2020-02-04");
	EXPECT_STRNE(result[2][2], "3");
	EXPECT_STRNE(result[2][3], "3");
	EXPECT_STRNE(result[2][4], "3");
	EXPECT_STRNE(result[2][5], "2");
	EXPECT_STRNE(result[2][6], "4050");
	EXPECT_STRNE(result[2][6], "No");
}