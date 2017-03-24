#ifndef __tetrahedron_atd__
#define __tetrahedron_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// шар
	class tetrahedron :public shape {
		int l; // длина стороны
		float d; //плотность(density)
	public:
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutTetrahedron(ofstream &ofst);
		tetrahedron() {};
		~tetrahedron() {};
	};
} // end simple_shapes namespace
#endif