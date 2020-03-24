

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
}

TEST(test1, timesType) {
	
	char*** result;
	result = CrewMemberInformation("Shestopalov", 0, 0, 0);

	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "1");
	EXPECT_STREQ(result[0][3], "12");
	EXPECT_STREQ(result[0][4], "5");
	EXPECT_STREQ(result[0][5], "2");
	EXPECT_STREQ(result[0][6], "5000");
	EXPECT_STREQ(result[0][7], "no");
	EXPECT_STREQ(result[1][0], "6");
	EXPECT_STREQ(result[1][1], "2020-02-07");
	EXPECT_STREQ(result[1][2], "1");
	EXPECT_STREQ(result[1][3], "18");
	EXPECT_STREQ(result[1][4], "15");
	EXPECT_STREQ(result[1][5], "4");
	EXPECT_STREQ(result[1][6], "7000");
	EXPECT_STREQ(result[1][7], "no");
}
TEST(TryLogin321, timesType) {
	char*** result = CrewMemberInformation("Shestopalov",0,0,0);
	EXPECT_STRNE(result[0][0], "4");
	EXPECT_STRNE(result[0][1], "2020-06-07");
	EXPECT_STRNE(result[0][2], "D");
	EXPECT_STRNE(result[0][3], "18");
	EXPECT_STRNE(result[0][4], "15");
	EXPECT_STRNE(result[0][5], "6");
	EXPECT_STRNE(result[0][6], " ");
	EXPECT_STRNE(result[0][7], "yes");
}
TEST(TryLogin31313, timesType) {
	char*** result = CrewMemberInformation("Pirsky",0,0,0);
	
	EXPECT_STREQ(result[0][0], "2");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "2");
	EXPECT_STREQ(result[0][3], "20");
	EXPECT_STREQ(result[0][4], "3");
	EXPECT_STREQ(result[0][5], "5");
	EXPECT_STREQ(result[0][6], "12000");
	EXPECT_STREQ(result[0][7], "yes");
	EXPECT_STREQ(result[1][0], "7");
	EXPECT_STREQ(result[1][1], "2020-02-08");
	EXPECT_STREQ(result[1][2], "2");
	EXPECT_STREQ(result[1][3], "17");
	EXPECT_STREQ(result[1][4], "20");
	EXPECT_STREQ(result[1][5], "10");
	EXPECT_STREQ(result[1][6], "14000");
	EXPECT_STREQ(result[1][7], "yes");
	}
TEST(TryL3131ogin, timesType) {
	char*** result = CrewMemberInformation("Pirsky",0,0,0);
	EXPECT_STRNE(result[0][0], "0");
	EXPECT_STRNE(result[0][1], "2020-06-09");
	EXPECT_STRNE(result[0][2], "F");
	EXPECT_STRNE(result[0][3], "18");
	EXPECT_STRNE(result[0][4], "15");
	EXPECT_STRNE(result[0][5], "6");
	EXPECT_STRNE(result[0][6], " ");
	EXPECT_STRNE(result[0][7], "yes");
	EXPECT_STREQ(result[1][0], "15");
	EXPECT_STREQ(result[1][1], "2020-00-08");
	EXPECT_STREQ(result[1][2], "2");
	EXPECT_STREQ(result[1][3], "67");
	EXPECT_STREQ(result[1][4], "20");
	EXPECT_STREQ(result[1][5], "10");
	EXPECT_STREQ(result[1][6], "14000");
	EXPECT_STREQ(result[1][7], "no");
}


