#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров шара из файла
	void tetrahedron::InData(ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> l >> d;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (l <= 0 || d <= 0) {
			cerr << "Error: Incorrect values in tetrahedron input" << endl;
			exit(1);
		}
		shape::InData(ifst);
	}

	// Вывод параметров шараа в поток
	void tetrahedron::Out(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Tetrahedron: l = " << l << ", Density = " << d << endl;
		shape::Out(ofst);
		ofst << endl;
	}

	void tetrahedron::OutTetrahedron(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		Out(ofst);
	}

	double tetrahedron::Volume() {
		double v = sqrt(2)*l*l*l / 12;
		if (abs((v * 12 / (sqrt(2)*l*l)) - l) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return l*l*l*sqrt(2)/12;
	}
} // end simple_shapes namespace