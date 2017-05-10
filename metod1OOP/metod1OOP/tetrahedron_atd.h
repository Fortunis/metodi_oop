#ifndef __tetrahedron_atd__
#define __tetrahedron_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// шар
	class tetrahedron :public shape {
	public:
		int l; // длина стороны
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