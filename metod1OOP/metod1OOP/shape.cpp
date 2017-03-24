#include <fstream>
#include "shape_atd.h"
#include "ball_atd.h"
#include "parallelepiped_atd.h"
#include "tetrahedron_atd.h"

using namespace std;

namespace simple_shapes {
	// Ввод параметров обобщенной фигуры из файла
	shape* shape::In(ifstream &ifst)
	{
		shape *sp;
		int k;
		ifst >> k;
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

	void shape::OutBall(ofstream &ofst) {
		ofst << endl;  // пустая строка
	}

	void shape::OutParallelepiped(ofstream &ofst) {
		ofst << endl;  // пустая строка
	}
	void shape::OutTetrahedron(ofstream &ofst) {
		ofst << endl;  // пустая строка
	}
	//----------------------------------------------------
	// Ввод параметров фигуры
	void shape::InData(ifstream &ifst) {
		ifst >> temperature;
	}

	//----------------------------------------------------
	// Вывод параметров фигуры
	void shape::Out(ofstream &ofst) {
		ofst << "temperature = " << temperature;
	}

} // end simple_shapes namespace