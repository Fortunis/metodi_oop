#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "shape_atd.h"
#include "FilesCmp.h"
#include "gtest/gtest.h"

using namespace std;
using namespace simple_shapes;

class ContainerTest : public ::testing::Test {
};

TEST_F(ContainerTest, CheckClear) {
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.Clear();
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerClear.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutBall) {
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.OutBall(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutBall.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutParallelepiped) {
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.OutParallelepiped(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutParallelepiped.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckOutTetrahedron) {
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.OutTetrahedron(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerOutTetrahedron.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSort) {
	ifstream ifst("ContainerInput.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.Sort();
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSorted.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEmpty) {
	ifstream ifst("Empty.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.Sort();
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSortEmpty.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}

TEST_F(ContainerTest, CheckSortEqual) {
	ifstream ifst("ContainerEqual.txt");
	ofstream ofst("ContainerTest.txt");

	container c;
	c.In(ifst);
	c.Sort();
	c.Out(ofst);
	ifst.close();
	ofst.close();

	ifstream actual("ContainerTest.txt");
	ifstream expected("ContainerSortEqual.txt");
	bool flag = FilesCmp(expected, actual);
	ASSERT_TRUE(flag);
}