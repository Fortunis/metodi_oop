#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ���� �� �����
	void tetrahedron::InData(ifstream &ifst) {
		ifst >> l >> d;
	}

	// ����� ���������� ����� � �����
	void tetrahedron::Out(ofstream &ofst) {
		ofst << "It is Tetrahedron: r = " << l << ", Density = " << d << endl;
	}

	void tetrahedron::OutTetrahedron(ofstream &ofst) {
		Out(ofst);
	}
} // end simple_shapes namespace