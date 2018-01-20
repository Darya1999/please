#pragma once
#include <iostream>

class Matrixx
{

public:

	void set_size(int n, int m); // ������� ������� ������� 

	int get(int i, int j); // ������ �������� �� ������� [i, j]

	void set(int i, int j, int value); // ������ �������� �� ������� [i, j]

	void print(); // ����� ������� �� ����� 

	int num_rows(); // ���������� ����� 

	int num_cols(); // ���������� �������� 

	void matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2); // ������������ ������ 

	void matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2); // �������� ������ 

	Matrixx();
	Matrixx(const Matrixx& other); // ����������� ����������� 
	Matrixx(int n, int m);
	virtual ~Matrixx();

private:

	int m; // ���������� �������� 

	int n; // ���������� ����� 

	int *matrix; // ������ 

};

Matrixx operator + (Matrixx & matrix1,
	Matrixx & matrix2);

Matrixx operator - (Matrixx & matrix1,
	Matrixx & matrix2);

Matrixx operator * (Matrixx & matrix1,
	Matrixx & matrix2);

std::ostream & operator << (std::ostream & os,
	Matrixx & matrix1);