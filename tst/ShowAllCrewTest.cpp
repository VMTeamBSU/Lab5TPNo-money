

#include "gtest/gtest.h"
extern  "C" {
#include "../include/BDfunctions.h"
#include "stdlib.h"
}

TEST(testShowAllCrewMembers, testingvalidShowAllCrew) {

	char*** result;
	char** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllCrewMembers(all, &b, &c);

	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "second pilot");
	EXPECT_STREQ(result[0][2], "1090");
	EXPECT_STREQ(result[0][3], "1985-05-05");
	EXPECT_STREQ(result[0][4], "1");
	EXPECT_STREQ(result[0][5], "Shestopalov");
	EXPECT_STREQ(result[1][0], "2");
	EXPECT_STREQ(result[1][1], "third pilot");
	EXPECT_STREQ(result[1][2], "900");
	EXPECT_STREQ(result[1][3], "1990-10-10");
	EXPECT_STREQ(result[1][4], "1");
	EXPECT_STREQ(result[1][5], "Paloshestov");
	EXPECT_STREQ(result[2][0], "3");
	EXPECT_STREQ(result[2][1], "second pilot");
	EXPECT_STREQ(result[2][2], "1067");
	EXPECT_STREQ(result[2][3], "1991-11-11");
	EXPECT_STREQ(result[2][4], "2");
	EXPECT_STREQ(result[2][5], "Pirsky");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "567");
	EXPECT_STREQ(result[3][3], "1992-12-12");
	EXPECT_STREQ(result[3][4], "2");
	EXPECT_STREQ(result[3][5], "Kotletov");
	EXPECT_STREQ(result[2][0], "5");
	EXPECT_STREQ(result[2][1], "second pilot");
	EXPECT_STREQ(result[2][2], "999");
	EXPECT_STREQ(result[2][3], "1989-12-21");
	EXPECT_STREQ(result[2][4], "3");
	EXPECT_STREQ(result[2][5], "Kalinchuk");
	EXPECT_STREQ(result[3][0], "6");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "765");
	EXPECT_STREQ(result[3][3], "1988-04-13");
	EXPECT_STREQ(result[3][4], "3");
	EXPECT_STREQ(result[3][5], "Opanasenko");
	EXPECT_STREQ(result[2][0], "7");
	EXPECT_STREQ(result[2][1], "second pilot");
	EXPECT_STREQ(result[2][2], "833");
	EXPECT_STREQ(result[2][3], "1990-06-18");
	EXPECT_STREQ(result[2][4], "4");
	EXPECT_STREQ(result[2][5], "Goptev");
	EXPECT_STREQ(result[3][0], "8");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "900");
	EXPECT_STREQ(result[3][3], "1991-07-13");
	EXPECT_STREQ(result[3][4], "4");
	EXPECT_STREQ(result[3][5], "Kleshev");
}
TEST(testShowAllCrewMembers, testinginvalidShowAllCrew) {

	char*** result;
	char** all = NULL;
	int b = 0;
	int c = 0;
	result = ShowAllCrewMembers(all, &b, &c);


	EXPECT_STREQ(result[0][0], "1");
	EXPECT_STREQ(result[0][1], "second pilot");
	EXPECT_STREQ(result[0][2], "1090");
	EXPECT_STREQ(result[0][3], "1985-05-05");
	EXPECT_STREQ(result[0][4], "1");
	EXPECT_STREQ(result[0][5], "Shestopalov");
	EXPECT_STREQ(result[1][0], "2");
	EXPECT_STREQ(result[1][1], "third pilot");
	EXPECT_STREQ(result[1][2], "900");
	EXPECT_STREQ(result[1][3], "1990-10-10");
	EXPECT_STREQ(result[1][4], "1");
	EXPECT_STREQ(result[1][5], "Paloshestov");
	EXPECT_STREQ(result[2][0], "3");
	EXPECT_STREQ(result[2][1], "second pilot");
	EXPECT_STREQ(result[2][2], "10647");
	EXPECT_STREQ(result[2][3], "19491-11-11");
	EXPECT_STREQ(result[2][4], "24");
	EXPECT_STREQ(result[2][5], "Pirsky");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "567");
	EXPECT_STREQ(result[3][3], "1992-12-12");
	EXPECT_STREQ(result[3][4], "2");
	EXPECT_STREQ(result[3][5], "Kotletov");
	EXPECT_STREQ(result[2][0], "54");
	EXPECT_STREQ(result[2][1], "second pilot");
	EXPECT_STREQ(result[2][2], "999");
	EXPECT_STREQ(result[2][3], "1989-12-21");
	EXPECT_STREQ(result[2][4], "0");
	EXPECT_STREQ(result[2][5], "Kalinchuk");
	EXPECT_STREQ(result[3][0], " ");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "7645");
	EXPECT_STREQ(result[3][3], "14988-04-13");
	EXPECT_STREQ(result[3][4], "33");
	EXPECT_STREQ(result[3][5], "Opanasenko");
	EXPECT_STREQ(result[2][0], "47");
	EXPECT_STREQ(result[2][1], "econd pilot");
	EXPECT_STREQ(result[2][2], "3833");
	EXPECT_STREQ(result[2][3], "90-06-18");
	EXPECT_STREQ(result[2][4], "4");
	EXPECT_STREQ(result[2][5], "G3optev");
	EXPECT_STREQ(result[3][0], "4");
	EXPECT_STREQ(result[3][1], "third pilot");
	EXPECT_STREQ(result[3][2], "1900");
	EXPECT_STREQ(result[3][3], "991-07-13");
	EXPECT_STREQ(result[3][4], "r");
	EXPECT_STREQ(result[3][5], "Klesv");
}


