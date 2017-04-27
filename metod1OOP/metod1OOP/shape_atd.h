#ifndef __shape_atd__
#define __shape_atd__
#include <fstream>

using namespace std;

namespace simple_shapes {
	// структура, обобщающая все имеющиеся фигуры
	class shape {
		
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

		bool Compare(shape &other);
		int temperature;
	};
} // end simple_shapes namespace
#endif