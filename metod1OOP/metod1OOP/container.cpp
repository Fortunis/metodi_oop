#include "container_atd.h"
#include <iostream>
//#include <fstream>
//#include "shape_atd.h"

using namespace std;

namespace simple_shapes {
	// ќчистка контейнера от элементов
	// (освобождение пам€ти)
	void container::Clear() {
		while (size != 0) {
			container *temp = Head->Next;
			delete Head;
			Head = temp;
			--size;
		}

		Head = nullptr;
		Tail = nullptr;
		Current = nullptr;
	}

	void container::Add(shape &s) {
		++size;
		container* temp = new container;
		temp->cont = &s;
		temp->Next = Head;
		Current = temp;

		if (Head != nullptr) {
			Tail->Next = temp;
			Tail = temp;
		}
		else {
			Head = Tail = temp;
		}
	}


	// ¬вод содержимого контейнера из указанного потока
	void container::In(ifstream &ifst) {
		if (!ifst) {
			cerr << "Error: Unable to open input file" << endl;
			return;
		}
		else {
			int tmp = 0;
			if (ifst.eof()) {
				cerr << "Empty File!" << endl;
				exit(1);
			}
			while (!ifst.eof()) {
				Add(*shape::In(ifst));
			}
		}
	}


	// ¬ывод содержимого контейнера в указанный поток
	void container::Out(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			return;
		}
		else {
			if (size) {
				ofst << "Container is filled:\n";
				ofst << "Container contains " << size
					<< " elements." << endl;
			}
			else {
				ofst << "Container is empty:\n";
			}

			shape* current;

			for (int i = 0; i < size; i++) {

				Current = Current->Next;

				current = Current->cont;
				current->Out(ofst);

				current = nullptr;
				delete current;
			}
		}
	}


	void container::Volume(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			return;
		}
		else {
			if (size) {
				ofst << "Container is filled:\n";
				ofst << "Container contains " << size
					<< " elements." << endl;
			}
			else {
				ofst << "Container is empty:\n";
			}
			shape* current;

			for (int i = 0; i < size; i++) {
				ofst << i << ": ";
				Current = Current->Next;
				current = Current->cont;
				current->Out(ofst);
				ofst << "volume = " << current->Volume() << endl;
				current = nullptr;
				delete current;
			}
		}
	}

	void container::OutBall(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only balls." << endl;

			shape* current;

			for (int i = 0; i < size; i++) {

				Current = Current->Next;

				current = Current->cont;
				current->OutBall(ofst);

				current = nullptr;
				delete current;
			}
		}
	}

	void container::OutParallelepiped(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only parallelepipeds." << endl;

			shape* current;

			for (int i = 0; i < size; i++) {

				Current = Current->Next;

				current = Current->cont;
				current->OutParallelepiped(ofst);

				current = nullptr;
				delete current;
			}
		}
	}

	void container::OutTetrahedron(ofstream &ofst) {
		if (!ofst) {
			cerr << "Error: Unable to open output file" << endl;
			exit(1);
		}
		else {
			if (!size) {
				ofst << "Container is empty:\n";
			}
			ofst << "Only tetrahedrons." << endl;

			shape* current;

			for (int i = 0; i < size; i++) {

				Current = Current->Next;

				current = Current->cont;
				current->OutTetrahedron(ofst);

				current = nullptr;
				delete current;
			}
		}
	}

	//-----------------------------------------------------
	// —ортировка содержимого контейнера
	void container::Sort() {
		container *s, *ptr;
		shape *temp;
		if (this->Tail == nullptr) {
			return;
		}
		s = this->Tail->Next;

		while (s != this->Tail) {
			ptr = s->Next;
			while (ptr != this->Tail->Next) {
				if (ptr != this->Tail->Next) {
					if (s->cont->Compare(*ptr->cont)) {
						temp = s->cont;
						s->cont = ptr->cont;
						ptr->cont = temp;
					}
				}
				ptr = ptr->Next;
			}
			s = s->Next;
		}
	}

} // end simple_shapes namespace