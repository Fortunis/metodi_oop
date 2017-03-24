#ifndef __ball_atd__
#define __ball_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class ball:public shape {
		int r; // ������
		float d; //���������(density)
	public:
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);

		double Volume();

		void OutBall(ofstream &ofst);

		ball() {};
		~ball() {};
	};
} // end simple_shapes namespace
#endif