#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров шара из файла
	void ball::InData(ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> r >> d;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (r <= 0 || d <= 0) {
			cerr << "Error: Incorrect values in ball input" << endl;
			exit(1);
		}
		shape::InData(ifst);
	}

	// Вывод параметров шараа в поток
	void ball::Out(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Ball: r = " << r << ", Density = "<< d << endl;

		shape::Out(ofst);
		ofst << endl;
	}

	void ball::OutBall(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		Out(ofst);
	}

	double ball::Volume() {
		double v = 4 * 3.14*r*r*r / 3;
		if (abs((v * 3 / (4 * 3.14 *r*r)) - r) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return 4 * 3.14*r*r*r / 3;
	}

} // end simple_shapes namespace