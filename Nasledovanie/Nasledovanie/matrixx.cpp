#include "stdafx.h"
#include "Matrixx.h"
#include <algorithm>
#include <iostream> 

using namespace std;

Matrixx::Matrixx() // �������� ������ ������
{
	m = 0; // ���������� �������� 
	n = 0; // ���������� ����� 
	data = 0; // ������� 
}

Matrixx::Matrixx(const Matrixx& other)
{
	m = other.m;
	n = other.n;
	data = new int[m * n];
	for (int i = 0; i < m * n; i++)
	{
		data[i] = other.data[i];
	}
}

int Matrixx::get(int i, int j)
{
	if ((data != 0) && (i < n) && (j < m))
	{
		return data[i * m + j]; // ������ �������� �� ������� [i, j] 
	}
	else
	{
		return 0;
	}
}


Matrixx operator + (Matrixx & matrix1,
	Matrixx & matrix2) // ���������� ��������� +
{
	if (matrix1.num_cols() != matrix2.num_cols() ||
		matrix1.num_rows() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(1);
	}

	Matrixx result(matrix1.num_rows(), matrix1.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			int value = matrix1.get(i, j) + matrix2.get(i, j);
			result.set(i, j, value);
		}
	}



	return result;
}


Matrixx operator - (Matrixx & matrix1,
	Matrixx & matrix2) // ���������� ��������� +
{
	if (matrix1.num_cols() != matrix2.num_cols() ||
		matrix1.num_rows() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(2);
	}

	Matrixx result(matrix1.num_rows(), matrix1.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			int value = matrix1.get(i, j) - matrix2.get(i, j);
			result.set(i, j, value);
		}
	}

	return result;
}


Matrixx operator * (Matrixx & matrix1,
	Matrixx & matrix2) // ���������� ��������� * (�������*�������) 
{
	if (matrix1.num_cols() != matrix2.num_rows())
	{
		cout << "WRONG" << endl;
		exit(3);
	}

	Matrixx result(matrix1.num_rows(), matrix2.num_cols());
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		for (int j = 0; j < matrix2.num_cols(); j++)
		{
			int value = 0;

			for (int k = 0; k < matrix1.num_cols(); k++)
			{
				value += matrix1.get(i, k) * matrix2.get(k, j);
			}
			result.set(i, j, value);
		}
	}

	return result;
}

ostream & operator << (ostream & os,
	Matrixx & matrix1) // ���������� ��������� << 
{
	for (int i = 0; i < matrix1.num_rows(); i++)
	{
		os << "\t ";
		for (int j = 0; j < matrix1.num_cols(); j++)
		{
			os << matrix1.get(i, j) << " ";
		}
		os << " " << endl;
	}

	return os;
}


void Matrixx::set(int i, int j, int value)
{
	if ((data != 0) && (i < n) && (j < m))
	{
		data[i * m + j] = value; // ������ �������� �� ������� [i, j]
	}
}

void Matrixx::set_size(int new_n, int new_m) // ������� ������� �������
{
	int *new_data = new int[new_n * new_m];
	for (int i = 0; i < new_n; ++i)
	{
		for (int j = 0; j < new_m; ++j)
		{
			new_data[i * new_m + j] = get(i, j);
		}
	}
	n = new_n;
	m = new_m;
	delete[] data;
	data = new_data;
}

int Matrixx::num_rows() // ���������� ����� 
{
	return n;
}

int Matrixx::num_cols() // ���������� �������� 
{
	return m;
}

void Matrixx::print() // ������ ������� 
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << get(i, j) << " ";
		}
		cout << endl;
	}
}

void Matrixx::matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2) //������������ ������ 
{

	for (int i = 0; i < t1; i++)
	{
		for (int j = 0; j < p2; j++)
		{
			int s = 0;
			for (int z = 0; z < p1; z++)
			{
				s = s + matrix1[i][z] * matrix2[z][j]; // ������� ��������� ���� ������ 
			}
			matrix_result[i][j] = s;
		}
	}
}

void Matrixx::matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2) // ������� ��� �������� ����� ������ 
{

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < m1; j++)
		{
			result[i][j] = matrix1[i][j] + matrix2[i][j]; // ������� �������� ������
		}

	}
}



Matrixx::Matrixx(int nn, int mm) // ����� ������������ 
{
	data = 0;
	n = 0;
	m = 0;
	set_size(nn, mm); // �������� ������� �������� 0�0 
}

Matrixx::~Matrixx() // ����� ����������� 
{
	delete[] data;
}