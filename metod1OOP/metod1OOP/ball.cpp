#include <fstream>
#include <iostream>
#include "ball_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров шара из файла
	void ball::InData(ifstream &ifst) {
		ifst >> r >> d;
	}

	// Вывод параметров шараа в поток
	void ball::Out(ofstream &ofst) {
		ofst << "It is Ball: r = " << r << ", Density = "<< d << endl;
	}

	double ball::Volume() {
		return 4 * 3.14*r*r*r / 3;
	}
} // end simple_shapes namespace