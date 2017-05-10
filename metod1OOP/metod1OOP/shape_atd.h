#ifndef __shape_atd__
#define __shape_atd__
#include <fstream>

using namespace std;

namespace simple_shapes {
	// структура, обобщающая все имеющиеся фигуры
	class shape {
		int temperature;
		float d; //плотность(density)
	public:
		shape() {};
		virtual ~shape() {};
		static shape* In(ifstream &ifst);
		virtual void InData(ifstream &ifst) = 0;
		virtual void Out(ostream &ofst) = 0;
		virtual double Volume() = 0;

		virtual void OutBall(ostream &ofst);
		virtual void OutParallelepiped(ostream &ofst);
		virtual void OutTetrahedron(ostream &ofst);

		virtual void MultiMethod(shape *other, ostream &ofst) = 0;
		virtual void MMBall(ostream &ofst) = 0;
		virtual void MMParallelepiped(ostream &ofst) = 0;
		virtual void MMTetrahedron(ostream &ofst) = 0;

		bool Compare(shape &other);

	};
} // end simple_shapes namespace
#endif