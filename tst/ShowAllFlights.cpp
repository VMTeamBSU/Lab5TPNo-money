

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(testShowAllFlights, testingvalidShowAllFlights) {

	char*** result;
	char** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllFlights(all, &b, &c);

	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "1");
	EXPECT_STREQ(result[0][3], "12");
	EXPECT_STREQ(result[0][4], "5");
	EXPECT_STREQ(result[0][5], "2");
	EXPECT_STREQ(result[0][6], "5000");
	EXPECT_STREQ(result[0][7], "no");
	EXPECT_STREQ(result[1][0], "2");
	EXPECT_STREQ(result[1][1], "2020-02-01");
	EXPECT_STREQ(result[1][2], "2");
	EXPECT_STREQ(result[1][3], "20");
	EXPECT_STREQ(result[1][4], "3");
	EXPECT_STREQ(result[1][5], "5");
	EXPECT_STREQ(result[1][6], "12000");
	EXPECT_STREQ(result[1][7], "yes");
	EXPECT_STREQ(result[2][0], "3");
	EXPECT_STREQ(result[2][1], "2020-02-02");
	EXPECT_STREQ(result[2][2], "4");
	EXPECT_STREQ(result[2][3], "4");
	EXPECT_STREQ(result[2][4], "8");
	EXPECT_STREQ(result[2][5], "3");
	EXPECT_STREQ(result[2][6], "5600");
	EXPECT_STREQ(result[2][7], "no");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "2020-02-04");
	EXPECT_STREQ(result[3][2], "3");
	EXPECT_STREQ(result[3][3], "3");
	EXPECT_STREQ(result[3][4], "3");
	EXPECT_STREQ(result[3][5], "2");
	EXPECT_STREQ(result[3][6], "4050");
	EXPECT_STREQ(result[3][7], "no");
	EXPECT_STREQ(result[4][0], "5");
	EXPECT_STREQ(result[4][1], "2020-02-05");
	EXPECT_STREQ(result[4][2], "4");
	EXPECT_STREQ(result[4][3], "1");
	EXPECT_STREQ(result[4][4], "7");
	EXPECT_STREQ(result[4][5], "7");
	EXPECT_STREQ(result[4][6], "13750");
	EXPECT_STREQ(result[4][7], "yes");
	EXPECT_STREQ(result[5][0], "6");
	EXPECT_STREQ(result[5][1], "2020-02-07");
	EXPECT_STREQ(result[5][2], "1");
	EXPECT_STREQ(result[5][3], "18");
	EXPECT_STREQ(result[5][4], "15");
	EXPECT_STREQ(result[5][5], "4");
	EXPECT_STREQ(result[5][6], "7000");
	EXPECT_STREQ(result[5][7], "no");
	EXPECT_STREQ(result[6][0], "5");
	EXPECT_STREQ(result[6][1], "2020-02-05");
	EXPECT_STREQ(result[6][2], "4");
	EXPECT_STREQ(result[6][3], "1");
	EXPECT_STREQ(result[6][4], "7");
	EXPECT_STREQ(result[6][5], "7");
	EXPECT_STREQ(result[6][6], "13750");
	EXPECT_STREQ(result[6][7], "yes");
	EXPECT_STREQ(result[7][0], "7");
	EXPECT_STREQ(result[7][1], "2020-02-08");
	EXPECT_STREQ(result[7][2], "2");
	EXPECT_STREQ(result[7][3], "17");
	EXPECT_STREQ(result[7][4], "20");
	EXPECT_STREQ(result[7][5], "10");
	EXPECT_STREQ(result[7][6], "14000");
	EXPECT_STREQ(result[7][7], "yes");
	EXPECT_STREQ(result[8][0], "8");
	EXPECT_STREQ(result[8][1], "2020-02-08");
	EXPECT_STREQ(result[8][2], "3");
	EXPECT_STREQ(result[8][3], "1");
	EXPECT_STREQ(result[8][4], "7");
	EXPECT_STREQ(result[8][5], "2");
	EXPECT_STREQ(result[8][6], "4050");
	EXPECT_STREQ(result[8][7], "no");
	EXPECT_STREQ(result[9][0], "9");
	EXPECT_STREQ(result[9][1], "2020-02-10");
	EXPECT_STREQ(result[9][2], "4");
	EXPECT_STREQ(result[9][3], "3");
	EXPECT_STREQ(result[9][4], "1");
	EXPECT_STREQ(result[9][5], "5");
	EXPECT_STREQ(result[9][6], "5650");
	EXPECT_STREQ(result[9][7], "no");
	EXPECT_STREQ(result[10][0], "10");
	EXPECT_STREQ(result[10][1], "2020-02-11");
	EXPECT_STREQ(result[10][2], "1");
	EXPECT_STREQ(result[10][3], "13");
	EXPECT_STREQ(result[10][4], "15");
	EXPECT_STREQ(result[10][5], "3");
	EXPECT_STREQ(result[10][6], "7000");
	EXPECT_STREQ(result[10][7], "no");
}
TEST(testShowAllFlights, testinginvalidShowAllFlights) {

	char*** result;
	char** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllFlights(all, &b, &c);



	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "2020-02-01");
	EXPECT_STREQ(result[0][2], "1");
	EXPECT_STREQ(result[0][3], "12");
	EXPECT_STREQ(result[0][4], "5");
	EXPECT_STREQ(result[0][5], "2");
	EXPECT_STREQ(result[0][6], "5000");
	EXPECT_STREQ(result[0][7], "no");
	EXPECT_STREQ(result[1][0], "2");
	EXPECT_STREQ(result[1][1], "2020-02-01");
	EXPECT_STREQ(result[1][2], "2");
	EXPECT_STREQ(result[1][3], "20");
	EXPECT_STREQ(result[1][4], "3");
	EXPECT_STREQ(result[1][5], "5");
	EXPECT_STREQ(result[1][6], "12000");
	EXPECT_STREQ(result[1][7], "yes");
	EXPECT_STREQ(result[2][0], "3");
	EXPECT_STREQ(result[2][1], "2020-02-02");
	EXPECT_STREQ(result[2][2], "4");
	EXPECT_STREQ(result[2][3], "4");
	EXPECT_STREQ(result[2][4], "8");
	EXPECT_STREQ(result[2][5], "3");
	EXPECT_STREQ(result[2][6], "5600");
	EXPECT_STREQ(result[2][7], "no");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "2020-02-04");
	EXPECT_STREQ(result[3][2], "3");
	EXPECT_STREQ(result[3][3], "3");
	EXPECT_STREQ(result[3][4], "3");
	EXPECT_STREQ(result[3][5], "2");
	EXPECT_STREQ(result[3][6], "4050");
	EXPECT_STREQ(result[3][7], "no");
	EXPECT_STREQ(result[4][0], "5");
	EXPECT_STREQ(result[4][1], "2020-02-05");
	EXPECT_STREQ(result[4][2], "4");
	EXPECT_STREQ(result[4][3], "1");
	EXPECT_STREQ(result[4][4], "7");
	EXPECT_STREQ(result[4][5], "7");
	EXPECT_STREQ(result[4][6], "13750");
	EXPECT_STREQ(result[4][7], "yes");
	EXPECT_STREQ(result[5][0], "6");
	EXPECT_STREQ(result[5][1], "2020-02-07");
	EXPECT_STREQ(result[5][2], "1");
	EXPECT_STREQ(result[5][3], "18");
	EXPECT_STREQ(result[5][4], "15");
	EXPECT_STREQ(result[5][5], "4");
	EXPECT_STREQ(result[5][6], "7000");
	EXPECT_STREQ(result[5][7], "no");
	EXPECT_STREQ(result[6][0], "5");
	EXPECT_STREQ(result[6][1], "2020-02-05");
	EXPECT_STREQ(result[6][2], "4");
	EXPECT_STREQ(result[6][3], "1");
	EXPECT_STREQ(result[6][4], "7");
	EXPECT_STREQ(result[6][5], "7");
	EXPECT_STREQ(result[6][6], "137540");
	EXPECT_STREQ(result[6][7], "yes");
	EXPECT_STREQ(result[7][0], "7");
	EXPECT_STREQ(result[7][1], "2024-02-08");
	EXPECT_STREQ(result[7][2], "2");
	EXPECT_STREQ(result[7][3], "17");
	EXPECT_STREQ(result[7][4], "20");
	EXPECT_STREQ(result[7][5], "10");
	EXPECT_STREQ(result[7][6], "140400");
	EXPECT_STREQ(result[7][7], "yes");
	EXPECT_STREQ(result[8][0], "8");
	EXPECT_STREQ(result[8][1], "20420-02-08");
	EXPECT_STREQ(result[8][2], "3");
	EXPECT_STREQ(result[8][3], "1");
	EXPECT_STREQ(result[8][4], "7");
	EXPECT_STREQ(result[8][5], "2");
	EXPECT_STREQ(result[8][6], "4050");
	EXPECT_STREQ(result[8][7], "no");
	EXPECT_STREQ(result[9][0], "9");
	EXPECT_STREQ(result[9][1], "2020-02-10");
	EXPECT_STREQ(result[9][2], "44");
	EXPECT_STREQ(result[9][3], "3");
	EXPECT_STREQ(result[9][4], "4");
	EXPECT_STREQ(result[9][5], "65");
	EXPECT_STREQ(result[9][6], "50");
	EXPECT_STREQ(result[9][7], "no");
	EXPECT_STREQ(result[10][0], "1");
	EXPECT_STREQ(result[10][1], "2c020-02-11");
	EXPECT_STREQ(result[10][2], "c1");
	EXPECT_STREQ(result[10][3], "3");
	EXPECT_STREQ(result[10][4], "15");
	EXPECT_STREQ(result[10][5], "3");
	EXPECT_STREQ(result[10][6], "7000");
	EXPECT_STREQ(result[10][7], "no");
}


