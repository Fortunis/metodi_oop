#include <fstream>
#include "shape_atd.h"
#include "ball_atd.h"
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// ¬вод параметров обобщенной фигуры из файла
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
			default:
				return 0;
		}
		sp->InData(ifst);
		return sp;
	}

	void shape::OutBall(ofstream &ofst) {
		ofst << endl;  // пуста€ строка
	}

	void shape::OutParallelepiped(ofstream &ofst) {
		ofst << endl;  // пуста€ строка
	}

} // end simple_shapes namespace