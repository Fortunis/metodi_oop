#include <iostream>
#include <fstream>
#include "parallelepiped_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

class ParallelepipedTest : public ::testing::Test {
};

TEST_F(ParallelepipedTest, CheckVolume) {
	parallelepiped p;
	p.a = 1;
	p.b = 2;
	p.c = 3;
	p.d = 0;
	double expected = 6;
	ASSERT_EQ(expected, p.Volume());
}

TEST_F(ParallelepipedTest, CheckInput) {
	ifstream ifst("InParallelepiped.txt");
	parallelepiped actual;
	actual.InData(ifst);
	parallelepiped p;
	p.a = 2;
	p.b = 2;
	p.c = 2;
	p.d = 3;

	ASSERT_EQ(actual.a, p.a);
	ASSERT_EQ(actual.b, p.b);
	ASSERT_EQ(actual.c, p.c);
	ASSERT_NEAR(actual.d, p.d, 0.01);
}

/*TEST_F(ParallelepipedTest, CheckOutput) {
	ofstream ofst("OutTest.txt");
	parallelepiped p;
	p.a = 2;
	p.b = 2;
	p.c = 2;
	p.d = 3;
	p.OutParallelepiped(ofst);
	ofst.close();

	ifstream expected("OutParallelepiped.txt");
	ifstream actual("OutTest.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}*/