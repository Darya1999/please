#pragma once
#include "matrixx.h"
class Vector :
	public Matrixx
{
public:
	Vector();
	Vector(int size);
	~Vector();

	void Vector::scalar_mult(int &scalar_mult, int **vector1, int **vector2, int p1, int p2); // ������� ��� ���������� ��������� �������� 
};

int operator * (Vector & vector1,
	Vector & vector2); // ���������� ���������

