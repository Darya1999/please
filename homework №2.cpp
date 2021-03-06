// homework №2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>

using namespace std;

//Функции

// сложение матриц 

void matrix_slozh(int matrix1[3][3], int matrix2[3][3], int matrix_res[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_res[i][j] = 0;
			matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
		}
		
	}
}

// сложение векторов

void vect_slozh(int vect1[1][3], int vect2[1][3], int vect_res[1][3])
{
	for (int i = 0; i < 3; i++)
	{
		vect_res[0][i] = vect1[0][i] + vect2[0][i];
	}
}


// умножение матриц

void martix_umn(int matrix1[3][3], int matrix2[3][3], int matrix_res[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_res[i][j] = 0;
			for (int k = 0; k < 3; k++)
			{
				matrix_res[i][j] = matrix1[i][k] * matrix2[k][j] + matrix_res[i][j];
			}
		}
	}
}

//умножение матрицы на вектор

void matrix_vect(int matrix1[3][3], int vect1[1][3], int matrix_res[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_res[i][j] = 0;
			matrix_res[i][0] = matrix_res[i][0] + matrix1[i][j] * vect1[0][j];
		}
	}
}

//скалярное умножение векторов

void vect_skal(int &otv, int vect1[1][3], int vect2[1][3])
{
	otv = 0;
	for (int i = 0; i < 3; i++) {

		otv = otv + vect1[0][i] * vect2[0][i];
	}
}
// векторное умножение векторов


//ВЫВОД
void write_matrix (int matrix_res[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix_res[i][j] << "\t";
		}
		cout << endl;
	}
}

void write_vect(int vect_res[1][3])
{
	for (int i = 0; i < 3; i++)
	{
		cout << vect_res[0][i] << "\t";
	}
	cout << endl;
}


int main()
{
	int otv = 0;
	int matrix1[3][3] = { { 1, 2, 3 },
	                      { 1, 2, 3 },
	                      { 1, 2, 3 } };
	int matrix2[3][3] = { { 1, 2, 3 },
	                      { 1, 2, 3 },
	                      { 1, 2, 3 } };
	int matrix_res[3][3] = { { 0, 0, 0 },
	                         { 0, 0, 0 },
	                         { 0, 0, 0 } };
	int vect1[1][3] = { 1, 2, 3 };
	int vect2[1][3] = { 1, 2, 3 };
	int vect_res[1][3] = { 0,0,0 };
	

	matrix_slozh( matrix1, matrix2, matrix_res);
	write_matrix(matrix_res);

	cout << endl;

	vect_slozh(vect1, vect2, vect_res);
	write_vect(vect_res);

	cout << endl; 

	martix_umn(matrix1, matrix2, matrix_res);
	write_matrix(matrix_res);

	cout << endl;

	matrix_vect(matrix1, vect1, matrix_res);
	write_matrix(matrix_res);

	cout << endl;

	vect_skal(otv, vect1, vect2);

	std::cout << otv << std::endl << std::endl;
	cout << endl;



	system("pause");
    return 0;
}

