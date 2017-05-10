#ifndef __container_atd__
#define __container_atd__
#include "shape_atd.h"
namespace simple_shapes {
	// ������ �� �������� �������������� ������.
	// ������ ��������� ����� ������ ��� ��������������
	// ���������� ���������� �� ���������
	class shape;
	// ���������� ��������� �� ������ ����������� �������
	class container {
		int size = 0;

		shape *cont = nullptr;
		container* next = nullptr;
		container *head = nullptr, *tail = nullptr, *current = nullptr;
	public:
		void Clear();
		void Add(shape &s);
		void In(ifstream &ifst);
		void Out(ostream &ofst);
		void Volume(ostream &ofst);

		void OutBall(ostream &ofst);
		void OutParallelepiped(ostream &ofst);
		void OutTetrahedron(ostream &ofst);

		void Sort(int des);   // ���������� ����������

		void MultiMethod(ostream &ofst);

		container() {};
		~container() { Clear(); };
	};
} // end simple_shapes namespace
#endif