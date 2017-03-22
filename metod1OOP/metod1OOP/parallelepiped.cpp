#include <fstream>
#include "parallelepiped_atd.h"

using namespace std;

namespace simple_shapes {
	// ���� ���������� ��������������� �� ������
	void parallelepiped::InData(ifstream &ifst)
	{
		ifst >> a >> b >> c >> d;
	}

	// ����� ���������� ��������������� � �����
	void parallelepiped::Out(ofstream &ofst)
	{
		ofst << "It is Parallelepiped: a = "
		<< a << ", b = " << b
		<< ", c = " << c 
		<< ", Density = " << d << endl;
		ofst << endl;
	}

	void parallelepiped::OutParallelepiped(ofstream &ofst) {
		Out(ofst);
	}
} // end simple_shapes namespace