#ifndef __container_atd__
#define __container_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// —сылка на описание геометрической фигуры.
	// «нание структуры самой фигуры дл€ представленной
	// реализации контейнера не требуетс€
	class shape;
	// ѕростейший контейнер на основе одномерного массива
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
		void Sort();   // сортировка контейнера
		container() {};
		~container() { Clear(); };
	};
} // end simple_shapes namespace
#endif