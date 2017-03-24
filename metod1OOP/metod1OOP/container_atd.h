#ifndef __container_atd__
#define __container_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// Ссылка на описание геометрической фигуры.
	// Знание структуры самой фигуры для представленной
	// реализации контейнера не требуется
	class shape;
	// Простейший контейнер на основе одномерного массива
	class container
	{
		int size = 0;

		shape *cont = nullptr;
		container* Next = nullptr;
		container *Head = nullptr, *Tail = nullptr, *Current = nullptr;
	public:
		void Clear();
		void Add(shape &s);
		void In(ifstream &ifst);
		void Out(ofstream &ofst);
		void Volume(ofstream &ofst);

		void OutBall(ofstream &ofst);
		void OutParallelepiped(ofstream &ofst);
		void OutTetrahedron(ofstream &ofst);
		container() {};
		~container() { Clear(); };
	};
} // end simple_shapes namespace
#endif