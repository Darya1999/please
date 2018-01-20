#pragma once
#include <iostream>

class Matrixx
{

public:

	void set_size(int n, int m); // задание размера матрицы 

	int get(int i, int j); // чтение элемента на позиции [i, j]

	void set(int i, int j, int value); // запись элемента на позицию [i, j]

	void print(); // вывод матрицы на экран 

	int num_rows(); // количество строк 

	int num_cols(); // количество столбцов 

	void matrix_mult(int **matrix_result, int **matrix1, int **matrix2, int t1, int p1, int t2, int p2); // произведение матриц 

	void matrix_matrix(int **result, int **matrix1, int **matrix2, int n1, int m1, int n2, int m2); // сложение матриц 

	Matrixx();
	Matrixx(const Matrixx& other); // конструктор копирования 
	Matrixx(int n, int m);
	virtual ~Matrixx();

private:

	int m; // количество столбцов 

	int n; // количество строк 

	int *matrix; // массив 

};

Matrixx operator + (Matrixx & matrix1,
	Matrixx & matrix2);

Matrixx operator - (Matrixx & matrix1,
	Matrixx & matrix2);

Matrixx operator * (Matrixx & matrix1,
	Matrixx & matrix2);

std::ostream & operator << (std::ostream & os,
	Matrixx & matrix1);