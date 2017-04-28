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
		void Out(ofstream &ofst);
		void Volume(ofstream &ofst);

		void OutBall(ofstream &ofst);
		void OutParallelepiped(ofstream &ofst);
		void OutTetrahedron(ofstream &ofst);

		void Sort();   // ���������� ����������

		void MultiMethod(ofstream &ofst);

		container() {};
		~container() { Clear(); };
	};
} // end simple_shapes namespace
#endif