#ifndef __ball_atd__
#define __ball_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class ball:public shape {
	public:
		int r; // ������
		float d; //���������(density)
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);

		double Volume();

		void OutBall(ofstream &ofst);
		
		// �����������
		void MultiMethod(shape *other, ofstream &ofst);
		void MMBall(ofstream &ofst);
		void MMParallelepiped(ofstream &ofst);
		void MMTetrahedron(ofstream &ofst);

		ball() {};
		~ball() {};
	};
} // end simple_shapes namespace
#endif