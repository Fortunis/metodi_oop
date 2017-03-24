#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров шара из файла
	void tetrahedron::InData(ifstream &ifst) {
		ifst >> l >> d;
		shape::InData(ifst);
	}

	// Вывод параметров шараа в поток
	void tetrahedron::Out(ofstream &ofst) {
		ofst << "It is Tetrahedron: l = " << l << ", Density = " << d << endl;
		shape::Out(ofst);
		ofst << endl;
	}

	void tetrahedron::OutTetrahedron(ofstream &ofst) {
		Out(ofst);
	}

	double tetrahedron::Volume() {
		return l*l*l*sqrt(2)/12;
	}
} // end simple_shapes namespace