#include <fstream>
#include <iostream>
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров параллелепипеда из потока
	void parallelepiped::InData(ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> a >> b >> c;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (a <= 0 || b <= 0 || c <= 0 ) {
			cerr << "Error: Incorrect values in parallelepiped input" << endl;
			exit(1);
		}
		shape::InData(ifst);
	}

	// Вывод параметров параллелепипеда в поток
	void parallelepiped::Out(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "It is Parallelepiped: a = "
		<< a << ", b = " << b
		<< ", c = " << c << endl;
		shape::Out(ofst);
		ofst << endl;
	}

	void parallelepiped::OutParallelepiped(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		Out(ofst);
	}

	double parallelepiped::Volume() {
		double v = a * b * c;
		if (abs(v / (a* b) - c) >= 0.00001) {
			cerr << "ERROR VOLUME OVERFLOW" << endl;
			return 0;
		}
		return a*b*c;
	}

	//-----------------------------------------------------
	// мультиметод
	void parallelepiped::MultiMethod(shape *other, ostream &ofst) {
		other->MMParallelepiped(ofst);
	}

	void parallelepiped::MMBall(ostream &ofst) {
		ofst << "Ball and Parallelepiped" << endl;
	}

	void parallelepiped::MMParallelepiped(ostream &ofst) {
		ofst << "Parallelepiped and Parallelepiped" << endl;
	}

	void parallelepiped::MMTetrahedron(ostream &ofst) {
		ofst << "Tetrahedron and Parallelepiped" << endl;
	}

} // end simple_shapes namespace