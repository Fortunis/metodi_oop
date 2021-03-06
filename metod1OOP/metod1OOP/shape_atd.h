#ifndef __shape_atd__
#define __shape_atd__
#include <fstream>

using namespace std;

namespace simple_shapes {
	// ���������, ���������� ��� ��������� ������
	class shape {
		int temperature;
	public:
		shape() {};
		virtual ~shape() {};
		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;
		virtual void Out(ofstream &ofst) = 0;
		virtual double Volume() = 0;

		virtual void OutBall(ofstream &ofst);
		virtual void OutParallelepiped(ofstream &ofst);
		virtual void OutTetrahedron(ofstream &ofst);

		virtual void MultiMethod(shape *other, ofstream &ofst) = 0;
		virtual void MMBall(ofstream &ofst) = 0;
		virtual void MMParallelepiped(ofstream &ofst) = 0;
		virtual void MMTetrahedron(ofstream &ofst) = 0;

		bool Compare(shape &other);

	};
} // end simple_shapes namespace
#endif