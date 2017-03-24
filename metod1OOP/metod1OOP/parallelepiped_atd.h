#ifndef __parallelepiped_atd__
#define __parallelepiped_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// ��������������
	class parallelepiped: public shape {
		int a, b, c; // �������
		float d; //���������(density)
	public:
		void InData(ifstream &ifst);
		void Out(ofstream &ofst);
		void OutParallelepiped(ofstream &ofst);
		parallelepiped() {};
		~parallelepiped() {};
	};
} // end simple_shapes namespace
#endif