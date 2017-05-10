#ifndef __ball_atd__
#define __ball_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class ball:public shape {
	public:
		int r; // ������
		void InData(ifstream &ifst);
		void Out(ostream &ofst);

		double Volume();

		void OutBall(ostream &ofst);
		
		// �����������
		void MultiMethod(shape *other, ostream &ofst);
		void MMBall(ostream &ofst);
		void MMParallelepiped(ostream &ofst);
		void MMTetrahedron(ostream &ofst);

		ball() {};
		~ball() {};
	};
} // end simple_shapes namespace
#endif