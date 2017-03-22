#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ���� �� �����
	void ball::InData(ifstream &ifst) {
		ifst >> r >> d;
	}

	// ����� ���������� ����� � �����
	void ball::Out(ofstream &ofst) {
		ofst << "It is Ball: r = " << r << ", Density = "<< d << endl;
		ofst << endl;
	}

	void ball::OutBall(ofstream &ofst) {
		Out(ofst);
	}

} // end simple_shapes namespace