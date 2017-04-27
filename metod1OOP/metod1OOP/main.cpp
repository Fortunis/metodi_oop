#include <iostream>
#include <fstream>
#include "container_atd.h"
#include "ContainerTest.h"
//#include "ShapeTest.h"
#include "BallTest.h"
#include "ParallelepipedTest.h"
#include "TetrahedronTest.h"
#include "gtest/gtest.h"

using namespace std;

using namespace simple_shapes;

int main(int argc, char* argv[]) {
	if(argc !=3) {
		cout << "incorrect command line! "
		"Waited: command infile outfile" << endl;
		exit(1);
	}
	
	//argv[1] = "in.txt";
	//argv[2] = "out.txt";

	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	
	cout << "Start"<< endl;
	container c;
	c.In(ifst);
	ofst << "Filled container. " << endl;
	//ofst << "Sorted container. " << endl;
	//c.Sort();
	c.Volume(ofst);
	//c.Out(ofst);
	//c.Clear();
	//ofst << "Empty container. " << endl;
	cout << "Stop"<< endl;
	return 0;
	//::testing::InitGoogleTest(&argc, argv);
	//return RUN_ALL_TESTS();
}