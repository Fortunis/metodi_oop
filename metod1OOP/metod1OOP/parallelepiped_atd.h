#ifndef __parallelepiped_atd__
#define __parallelepiped_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// ��������������
	class parallelepiped: public shape {
	public:
		int a, b, c; // �������
		float d; //���������(density)

		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		double Volume();
		void OutParallelepiped(ofstream &ofst);

		void MultiMethod(shape *other, ofstream &ofst);
		void MMBall(ofstream &ofst);
		void MMParallelepiped(ofstream &ofst);
		void MMTetrahedron(ofstream &ofst);

		parallelepiped() {};
		~parallelepiped() {};
	};
} // end simple_shapes namespace
#endif