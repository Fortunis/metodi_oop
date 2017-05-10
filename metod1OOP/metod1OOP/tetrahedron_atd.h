#ifndef __tetrahedron_atd__
#define __tetrahedron_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class tetrahedron :public shape {
	public:
		int l; // ����� �������
		void InData(ifstream &ifst);
		void Out(ostream &ofst);
		double Volume();
		void OutTetrahedron(ostream &ofst);

		void MultiMethod(shape *other, ostream &ofst);
		void MMBall(ostream &ofst);
		void MMParallelepiped(ostream &ofst);
		void MMTetrahedron(ostream &ofst);

		tetrahedron() {};
		~tetrahedron() {};
	};
} // end simple_shapes namespace
#endif