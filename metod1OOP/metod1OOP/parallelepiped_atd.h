#ifndef __parallelepiped_atd__
#define __parallelepiped_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// параллелепипед
	class parallelepiped: public shape {
	public:
		int a, b, c; // стороны

		void InData(ifstream &ifst);
		void Out(ostream &ofst);
		double Volume();
		void OutParallelepiped(ostream &ofst);

		void MultiMethod(shape *other, ostream &ofst);
		void MMBall(ostream &ofst);
		void MMParallelepiped(ostream &ofst);
		void MMTetrahedron(ostream &ofst);

		parallelepiped() {};
		~parallelepiped() {};
	};
} // end simple_shapes namespace
#endif