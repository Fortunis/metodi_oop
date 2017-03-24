#ifndef __tetrahedron_atd__
#define __tetrahedron_atd__
#include "shape_atd.h"

namespace simple_shapes {
	// ���
	class tetrahedron :public shape {
		int l; // ����� �������
		float d; //���������(density)
	public:
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutTetrahedron(ofstream &ofst);
		tetrahedron() {};
		~tetrahedron() {};
	};
} // end simple_shapes namespace
#endif