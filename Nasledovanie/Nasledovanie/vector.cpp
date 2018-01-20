#include "stdafx.h"
#include "Vector.h"
#include "matrixx.h"
#include <iostream>
#include <algorithm>


using namespace std;

Vector::Vector() : Matrixx() // �������� ������ �������� 
{

}

Vector::Vector(int size) : Matrixx(size, 1)
{

}


Vector operator + (Vector & vector1,
	Vector & vector2) // ���������� ��������� + 
{
	Vector vector_result;

	return vector_result;
}

Vector operator - (Vector & vector1,
	Vector & vector2) // ���������� ��������� - 
{
	Vector vector_result;


	return vector_result;
}

int operator * (Vector & vector1,

	Vector & vector2) // ���������� ��������� * (������*������ - ��������� ������������) 
{

	if (vector1.num_rows() != vector2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(3);
	}

	int result = 0;

	for (int i = 0; i < vector1.num_rows(); i++)
	{
		result += vector1.get(i, 0) * vector2.get(i, 0);
	}

	return result;
}

void Vector::scalar_mult(int &scalar_mult, int **vector1, int **vector2, int p1, int p2) // ������� ��� ���������� ���������� ������������ �������� 
{
	{
		for (int j = 0; j < p1; j++)
		{
			scalar_mult = scalar_mult + vector1[0][j] * vector2[0][j]; // ������� ���������� ��������� �������� 
		}
	}

}

Vector::~Vector() // ����� ����������� 
{
}
