#ifndef __container_atd__
#define __container_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// ������ �� �������� �������������� ������.
	// ������ ��������� ����� ������ ��� ��������������
	// ���������� ���������� �� ���������
	class shape;
	// ���������� ��������� �� ������ ����������� �������
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
		container() {};
		~container() { Clear(); };
	};
} // end simple_shapes namespace
#endif