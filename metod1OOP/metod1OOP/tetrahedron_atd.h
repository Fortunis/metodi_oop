#ifndef __tetrahedron_atd__
#define __tetrahedron_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class tetrahedron :public shape {
	public:
		int l; // ����� �������
		float d; //���������(density)
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		double Volume();
		void OutTetrahedron(ofstream &ofst);

		void MultiMethod(shape *other, ofstream &ofst);
		void MMBall(ofstream &ofst);
		void MMParallelepiped(ofstream &ofst);
		void MMTetrahedron(ofstream &ofst);

		tetrahedron() {};
		~tetrahedron() {};
	};
} // end simple_shapes namespace
#endif