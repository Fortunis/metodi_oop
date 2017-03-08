#include <fstream>
#include "shape_atd.h"
#include "ball_atd.h"
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ���������� ������ �� �����
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
} // end simple_shapes namespace