

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(testShowAllCommanders, testingvalidShowAllCommanders) {

	char*** result;
	char*** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllCommanders(all, &b, &c);

	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "Poletov");
	EXPECT_STREQ(result[0][2], "2000");
	EXPECT_STREQ(result[0][3], "Lenina 6");
	EXPECT_STREQ(result[0][4], "1980-10-29");
	EXPECT_STREQ(result[0][5], "1");
	EXPECT_STREQ(result[1][0], "2");
	EXPECT_STREQ(result[1][1], "Zemnof");
	EXPECT_STREQ(result[1][2], "2201");
	EXPECT_STREQ(result[1][3], "Sadovaya 12");
	EXPECT_STREQ(result[1][4], "1975-01-22");
	EXPECT_STREQ(result[1][5], "2");
	EXPECT_STREQ(result[2][0], "3");
	EXPECT_STREQ(result[2][1], "Vertoletov");
	EXPECT_STREQ(result[2][2], "3683");
	EXPECT_STREQ(result[2][3], "Marksa 21");
	EXPECT_STREQ(result[2][4], "1978-02-14");
	EXPECT_STREQ(result[2][5], "3");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "Koltun");
	EXPECT_STREQ(result[3][2], "2785");
	EXPECT_STREQ(result[3][3], "Jasminova 13");
	EXPECT_STREQ(result[3][4], "1979-03-15");
	EXPECT_STREQ(result[3][5], "4");
}
TEST(testShowAllCommanders, testinginvalidShowAllCommanders) {

	char*** result;
	char*** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllCommanders(all, &b, &c);




	EXPECT_STRNE(result[0][0], "1");
	EXPECT_STRNE(result[0][1], "Poletov");
	EXPECT_STRNE(result[0][2], "200");
	EXPECT_STRNE(result[0][3], "Lenina 6");
	EXPECT_STRNE(result[0][4], "1980-10-29");
	EXPECT_STRNE(result[0][5], " ");
	EXPECT_STRNE(result[1][0], "0");
	EXPECT_STRNE(result[1][1], "9of");
	EXPECT_STRNE(result[1][2], "201");
	EXPECT_STRNE(result[1][3], "Sadovaya 12");
	EXPECT_STRNE(result[1][4], "1975-01-22");
	EXPECT_STRNE(result[1][5], "2");
	EXPECT_STRNE(result[2][0], "i");
	EXPECT_STRNE(result[2][1], "Vertoletov");
	EXPECT_STRNE(result[2][2], "383");
	EXPECT_STRNE(result[2][3], "Marksa 21");
	EXPECT_STRNE(result[2][4], "1978-02-14");
	EXPECT_STRNE(result[2][5], "3");
	EXPECT_STRNE(result[3][0], "94");
	EXPECT_STRNE(result[3][1], "Koltun");
	EXPECT_STRNE(result[3][2], "2785");
	EXPECT_STRNE(result[3][3], "Jasminova 13");
	EXPECT_STRNE(result[3][4], "1979-03-15");
	EXPECT_STRNE(result[3][5], "4");
}


