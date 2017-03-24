#include "container_atd.h"
//#include <fstream>
//#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// Очистка контейнера от элементов
	// (освобождение памяти)
	void container::Clear() {
		while (size != 0)
		{
			container *temp = Head->Next;
			delete Head;
			Head = temp;
			--size;
		}

		Head = nullptr;
		Tail = nullptr;
		Current = nullptr;
	}

	void container::Add(shape &s)
	{
		++size;
		container* temp = new container;
		temp->cont = &s;
		temp->Next = Head;
		Current = temp;

		if (Head != nullptr)
		{
			Tail->Next = temp;
			Tail = temp;
		}
		else
		{
			Head = Tail = temp;
		}
	}


	// Ввод содержимого контейнера из указанного потока
	void container::In(ifstream &ifst) {
		int tmp = 0;
		while (!ifst.eof())
		{
			Add(*shape::In(ifst));
		}
	}


	// Вывод содержимого контейнера в указанный поток
	void container::Out(ofstream &ofst) {
		ofst << "Container contains " << size
			<< " elements." << endl;

		shape* current;

		for (int i = 0; i < size; i++)
		{

			Current = Current->Next;

			current = Current->cont;
			current->Out(ofst);

			current = nullptr;
			delete current;
		}
	}


	void container::Volume(ofstream &ofst) {
		ofst << "Container contains " << size
			<< " elements." << endl;
		shape* current;

		for (int i = 0; i < size; i++)
		{	
			ofst << i << ": ";
			Current = Current->Next;
			current = Current->cont;
			current->Out(ofst);
			ofst << "volume = " << current->Volume() << endl;
			current = nullptr;
			delete current;
		}
	}
=======
	void container::OutBall(ofstream &ofst) {
		ofst << "Only balls." << endl;

		shape* current;

		for (int i = 0; i < size; i++)
		{

			Current = Current->Next;

			current = Current->cont;
			current->OutBall(ofst);

			current = nullptr;
			delete current;
		}
	}

	void container::OutParallelepiped(ofstream &ofst) {
		ofst << "Only parallelepipeds." << endl;

		shape* current;

		for (int i = 0; i < size; i++)
		{

			Current = Current->Next;

			current = Current->cont;
			current->OutParallelepiped(ofst);

			current = nullptr;
			delete current;
		}
	}
	void container::OutTetrahedron(ofstream &ofst) {
		ofst << "Only tetrahedrons." << endl;

		shape* current;

		for (int i = 0; i < size; i++)
		{

			Current = Current->Next;

			current = Current->cont;
			current->OutTetrahedron(ofst);

			current = nullptr;
			delete current;
		}
	}
} // end simple_shapes namespace