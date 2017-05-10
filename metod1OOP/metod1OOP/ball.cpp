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
		ifst >> r;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (r <= 0 ) {
			cerr << "Error: Incorrect values in ball input" << endl;
			exit(1);
		}
		shape::InData(ifst);
	}

	// Вывод параметров шараа в поток
	void ball::Out(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Ball: r = " << r << endl;

		shape::Out(ofst);
		ofst << endl;
	}

	void ball::OutBall(ostream &ofst) {
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

	void ball::MultiMethod(shape *other, ostream &ofst) {
		other->MMBall(ofst);
	}

	void ball::MMBall(ostream &ofst) {
		ofst << "Ball and Ball" << endl;
	}


	void ball::MMParallelepiped(ostream &ofst) {
		ofst << "Parallelepiped and Ball" << endl;
	}

	void ball::MMTetrahedron(ostream &ofst) {
		ofst << "Tetrahedron and Ball" << endl;
	}

} // end simple_shapes namespace