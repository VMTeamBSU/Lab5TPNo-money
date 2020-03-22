#include "gtest/gtest.h"
extern  "C" {
#include "../include/Function.h"
}

TEST(TestFindById, correctValue) {

	char*** result = GetInfoBySurname("Goptev");

	int b = func1(3);
	EXPECT_EQ(result[0][1], "Poletov");
	EXPECT_EQ(6, b);
	EXPECT_EQ(5, b);
}

TEST(TestFindById, incorrectValue) {

	char*** result = GetInfoBySurname("Goptev");

	int b = func1(3);
	EXPECT_EQ(result[0][1], "Poletov");
	EXPECT_EQ(6, b);
	EXPECT_EQ(5, b);
}
