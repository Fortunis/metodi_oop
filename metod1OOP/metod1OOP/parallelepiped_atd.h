#ifndef __parallelepiped_atd__
#define __parallelepiped_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// параллелепипед
	class parallelepiped: public shape {
		int a, b, c; // стороны
		float d; //плотность(density)
	public:
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutParallelepiped(ofstream &ofst);
		parallelepiped() {};
		~parallelepiped() {};
	};
} // end simple_shapes namespace
#endif