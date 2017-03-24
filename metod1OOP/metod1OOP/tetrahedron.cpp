#include <fstream>
#include <iostream>
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров шара из файла
	void tetrahedron::InData(ifstream &ifst) {
		ifst >> l >> d;
	}

	// Вывод параметров шараа в поток
	void tetrahedron::Out(ofstream &ofst) {
		ofst << "It is Tetrahedron: r = " << l << ", Density = " << d << endl;
	}
} // end simple_shapes namespace