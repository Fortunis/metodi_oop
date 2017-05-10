#include <fstream>
#include <iostream>
#include "shape_atd.h"
#include "ball_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров обобщенной фигуры из файла
	shape* shape::In(ifstream &ifst) {
		int k;
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> k;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		if (!(1 <= k && k <= 3)) {
			cerr << "Error: unknown type" << endl;
			exit(1);
		}
		if (ifst.eof()) {
			cerr << "Error: no data after type!" << endl;
			exit(1);
		}
		shape *sp;
		switch (k) {
			case 1:
				sp = new ball;
				break;
			case 2:
				sp = new parallelepiped;
				break;
			case 3:
				sp = new tetrahedron;
				break;
			default:
				return 0;
		}
		sp->InData(ifst);
		return sp;
	}


	void shape::OutBall(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		return;
	}

	void shape::OutParallelepiped(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		return;
	}
	void shape::OutTetrahedron(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		return;
	}
	//----------------------------------------------------
	// Ввод параметров фигуры
	void shape::InData(ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: no input file!" << endl;
			exit(1);
		}
		ifst >> d;
		if (d <= 0)
		{
			cerr << "Wrong density!" << endl;
			exit(1);
		}
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
		ifst >> temperature;
		if (ifst.fail()) {
			cout << "Wrong input!" << endl;
			exit(1);
		}
	}

	//----------------------------------------------------
	// Вывод параметров фигуры
	void shape::Out(ostream &ofst) {
		if (!ofst) {
			cerr << "Error: no output file!" << endl;
			exit(1);
		}
		ofst << "density = " << d;
		ofst << "temperature = " << temperature;
	}

	bool shape::Compare(shape &other) {
		return Volume() < other.Volume();
	}
} // end simple_shapes namespace