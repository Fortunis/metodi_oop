#include <iostream>
#include <fstream>
#include "ball_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

class BallTest : public ::testing::Test {
};

TEST_F(BallTest, CheckVolume) {
	ball b;
	b.r = 1;
	b.d = 0;
	double expected = 4.18667;
	ASSERT_NEAR(expected, b.Volume(), 0.01);
}

TEST_F(BallTest, CheckInput) {
	ifstream ifst("InBall.txt");
	ball actual;
	actual.InData(ifst);
	ball b;
	b.r = 2;
	b.d = 3;

	ASSERT_EQ(actual.r, b.r);
	ASSERT_NEAR(actual.d, b.d, 0.01);
}

/*TEST_F(BallTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	ball b;
	b.r = 2;
	b.d = 3;
	b.Out(ofst);
	ofst.close();

	ifstream expected("OutBall.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}*/