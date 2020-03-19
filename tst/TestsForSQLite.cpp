#include "gtest/gtest.h"
extern  "C" {
#include "../include/Formula.h"
}


TEST(TestFuncByMaks, test4)
{
	EXPECT_EQ(request(5), 25);
	EXPECT_EQ(request(10), 100);
	EXPECT_EQ(request(7), 49);
}