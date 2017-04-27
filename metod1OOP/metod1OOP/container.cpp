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
			container *temp = head->next;
			delete head;
			head = temp;
			--size;
		}

		head = nullptr;
		tail = nullptr;
		current = nullptr;
	}

	void container::Add(shape &s) {
		++size;
		container* temp = new container;
		temp->cont = &s;
		temp->next = head;
		current = temp;

		if (head != nullptr) {
			tail->next = temp;
			tail = temp;
		}
		else {
			head = tail = temp;
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

			shape* currentshape;

			for (int i = 0; i < size; i++) {

				current = current->next;

				currentshape = current->cont;
				currentshape->Out(ofst);

				currentshape = nullptr;
				delete currentshape;
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
			shape* currentshape;

			for (int i = 0; i < size; i++) {
				ofst << i << ": ";
				current = current->next;
				currentshape = current->cont;
				currentshape->Out(ofst);
				ofst << "volume = " << currentshape->Volume() << endl;
				currentshape = nullptr;
				delete currentshape;
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

			shape* currentshape;

			for (int i = 0; i < size; i++) {

				current = current->next;

				currentshape = current->cont;
				currentshape->OutBall(ofst);

				currentshape = nullptr;
				delete currentshape;
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

			shape* currentshape;

			for (int i = 0; i < size; i++) {

				current = current->next;

				currentshape = current->cont;
				currentshape->OutParallelepiped(ofst);

				currentshape = nullptr;
				delete currentshape;
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

			shape* currentshape;

			for (int i = 0; i < size; i++) {

				current = current->next;

				currentshape = current->cont;
				currentshape->OutTetrahedron(ofst);

				currentshape = nullptr;
				delete currentshape;
			}
		}
	}

	//-----------------------------------------------------
	// —ортировка содержимого контейнера
	void container::Sort() {
		container *s, *ptr;
		shape *temp;
		if (this->tail == nullptr) {
			return;
		}
		s = this->tail->next;

		while (s != this->tail) {
			ptr = s->next;
			while (ptr != this->tail->next) {
				if (ptr != this->tail->next) {
					if (s->cont->Compare(*ptr->cont)) {
						temp = s->cont;
						s->cont = ptr->cont;
						ptr->cont = temp;
					}
				}
				ptr = ptr->next;
			}
			s = s->next;
		}
	}

} // end simple_shapes namespace