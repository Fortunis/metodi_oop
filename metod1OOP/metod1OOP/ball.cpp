#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ���� �� �����
	void ball::InData(ifstream &ifst) {
		ifst >> r >> d;
		shape::InData(ifst);
	}

	// ����� ���������� ����� � �����
	void ball::Out(ofstream &ofst) {
		ofst << "It is Ball: r = " << r << ", Density = "<< d << endl;
		shape::Out(ofst);
		ofst << endl;
	}
} // end simple_shapes namespace