// GoogleTest.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "gtest/gtest.h"
#include "ball_atd.h"

class CRectTest : public ::testing::Test {
};

TEST_F(CRectTest, CheckPerimeter)
{
	
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}