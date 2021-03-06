// Homework №3.cpp : Defines the entry point for the console application.
// Funct_DynamicMassives.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//ВЫВОД
void vyvod_matrix(int **matrix_Dyn, int m1, int m2)
{
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m2; j++)
		{
			cout << matrix_Dyn[i][j] << " \t";
		}
		cout << std::endl;
	}
	cout << std::endl;
}

void vyvod_vect(int** vector_Dyn, int v1)
{
	for (int i = 0; i < v1; i++)
	{
		cout << vector_Dyn[0][i] << " \t";
	}
	cout << std::endl;
}

// сложение матриц
void matrix_slozh(int**& matrix_Dyn,  int** matrix1Dyn, int m3, int m4, int **matrix2Dyn, int m5, int m6)
{
	if ((m3 == m5) && (m4 == m6) )
	{
		int m1 = m3;
		int m2 = m4;
	for (int i = 0; i < m1; i++) {
		for (int j = 0; j < m2; j++) {
			matrix_Dyn[i][j] = 0;

			matrix_Dyn[i][j] = matrix1Dyn[i][j] + matrix2Dyn[i][j];

		}
	}
	vyvod_matrix(matrix_Dyn, m1, m2);
  }
	else { cout << "Impossible"; }
}

//сложение векторов
void vect_slozh(int**& vect_Dyn, int **vect1, int v1,  int ** vect2, int v2)
{
	if (v1 == v2) {
		for (int i = 0; i < v1; i++)
		{
			vect_Dyn[0][i] = 0;

			vect_Dyn[0][i] = vect1[0][i] + vect2[0][i];

		}
		vyvod_vect(vect_Dyn, v1);
	}
}

//умножение матриц
void matrix_umn(int**& matrix_Dyn,  int** matrix1Dyn, int m3, int m4, int** matrix2Dyn, int m5, int m6)
{ if ((m3==m6) && (m4==m5)) {
	int m1 = m3;
	int m2 = m4;
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < m2; j++) 
		{

			matrix_Dyn[i][j] = 0;

			for (int k = 0; k < m2; k++)

				matrix_Dyn[i][j] = matrix_Dyn[i][j] + matrix1Dyn[i][k] * matrix2Dyn[k][j];

		}
	}
	vyvod_matrix(matrix_Dyn, m1, m2);
}
else { cout << "Impossible" << endl; }
}

// умножение матрицы на вектор
void matrix_vect(int**& matrix_Dyn, int** matrix1Dyn, int m3, int m4, int **vect1, int v1)
{
	
	if (m4 == v1) {
		for (int i = 0; i < m3; i++) 
		{

			matrix_Dyn[0][i] = 0;

		}
		for (int i = 0; i < m3; i++)
		{
			for (int j = 0; j < m4; j++)
			{

				matrix_Dyn[0][i] = matrix_Dyn[0][i] + matrix1Dyn[i][j] * vect1[0][j];

			}
		}
		vyvod_vect(matrix_Dyn, v1);
	}
	else { cout << "Impossible" << endl; }
}

//скалярное произведение
void vect_skal(int &otv, int **vect1, int v1, int ** vect2, int v2)
{
	if (v1 == v2)
	{
		otv = 0;
		for (int i = 0; i < v1; i++)
		{

			otv = otv + vect1[0][i] * vect2[0][i];
		}
		cout << otv << endl;
	}
	else { cout << "Impossible" << endl; }
}

//векторное произведение векторов
void vect_vect(int **& matrix_vect_Dyn , int **vect1, int v1, int ** vect2, int v2, int**& vect_Dyn)
{
	if ((v1 == 3) && (v2 == 3)) {
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				for (int j = 0; j < 3; j++) {

					matrix_vect_Dyn[i][j] = 1;
				}

			}
			else {
				if (i == 1) {
					for (int j = 0; j < 3; j++) {

						matrix_vect_Dyn[i][j] = vect1[0][j];

					}
				}
				else {
					for (int j = 0; j < 3; j++) {

						matrix_vect_Dyn[i][j] = vect2[0][j];

					}
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			vect_Dyn[0][i] = 0;
		}
		for (int i = v1 - 1; i > -1; i--) { 
			(i == 0) ?
				(vect_Dyn[0][i] = matrix_vect_Dyn[1][(i + 1) / 3] * matrix_vect_Dyn[2][i + 1] - matrix_vect_Dyn[1][i + 1] * matrix_vect_Dyn[2][(i + 1) / 3])
				:
				(vect_Dyn[0][i] = matrix_vect_Dyn[1][(i + 1) / 3] * matrix_vect_Dyn[2][2] - matrix_vect_Dyn[1][2] * matrix_vect_Dyn[2][(i + 1) / 3]);
		}
		vyvod_vect(vect_Dyn, v1);
	}
	else { cout << "Impossible"; }
}


int main()
{
	int m1;
	int m2;
	int m3;
	int m4;
	int m5;
	int m6;

	int v2;
	int v1;

	cout << "Enter first matrix length " << endl;
	cin >> m3;
	m1 = m3;

	cout << "Enter first matrix width " << endl;
	cin >> m4;
	m2 = m4;

	cout << "Enter second matrix length " << endl;
	cin >> m5;

	cout << "Enter second matrix width " << endl;
	cin >> m6;

	cout << "Enter first vector length " << endl;
	cin >> v1;

	cout << "Enter second vector length " << endl;
	cin >> v2;

	int ** matrix_vect_Dyn = new int *[v1];
	for (int i = 0; i < v1; i++)
	{
		matrix_vect_Dyn[i] = new int[3];

	}

	int ** matrix_Dyn = new int *[m1];

	int ** matrix1Dyn = new int *[m3];

	int ** matrix2Dyn = new int *[m5];

	for (int i = 0; i < m1; i++)
	{
		matrix_Dyn[i] = new int[m2];

	}
	for (int i = 0; i < m1; i++)
	{
		matrix1Dyn[i] = new int[m4];

	}
	for (int i = 0; i < m5; i++)
	{
		matrix2Dyn[i] = new int[m6];

	}
		
	int ** vect_Dyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vect_Dyn[i] = new int[v1];

	}
	
	int ** vect1Dyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vect1Dyn[i] = new int[v1];

	}

	int ** vect2Dyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vect2Dyn[i] = new int[v2];

	}
	
	for (int i = 0; i < m3; i++) 
	{
		for (int j = 0; j < m4; j++)
		{
			matrix1Dyn[i][j] = 1;
		}
	}

	for (int i = 0; i < m5; i++) 
	{
		for (int j = 0; j < m6; j++)
		{
			matrix2Dyn[i][j] = 1;
		}
	}

	for (int i = 0; i < 1; i++) 
	{
		for (int j = 0; j < v1; j++)
		{
			vect1Dyn[i][j] = 1;
		}
	}

	for (int i = 0; i < 1; i++) {
		for (int j = 0; j < v2; j++)
		{
			vect2Dyn[i][j] = 1;
		}
	}


	int otv = 0;

	
	cout << endl << endl;
	cout << "Matrix Sum" << endl;
	matrix_slozh(matrix_Dyn, matrix1Dyn, m3, m4,  matrix2Dyn, m5, m6);
	
	cout << endl << endl;
	cout << "Vect Sum" << endl;

	vect_slozh(vect_Dyn, vect1Dyn, v1 , vect2Dyn, v2);

	cout << endl << endl;
	cout << "Matr Prod" << endl;
	matrix_umn(matrix_Dyn, matrix1Dyn , m3, m4, matrix2Dyn, m5, m6);

	cout << endl << endl;
	cout << "Matr * Vect Prod" << endl;
	matrix_vect(vect_Dyn, matrix1Dyn, m3, m4, vect1Dyn, v1);

	cout << endl << endl;
	cout << "Skal Prod" << endl;

	vect_skal(otv, vect1Dyn, v1, vect2Dyn, v2);

	cout << endl << endl;
	cout << "Vect Prod" << endl;

	vect_vect(matrix_vect_Dyn, vect1Dyn, v1, vect2Dyn, v2, vect_Dyn );

	
	for (int i = 0; i < m3; i++) 
	{
		delete matrix_Dyn[i];
	}

	delete[] matrix_Dyn;



	for (int i = 0; i < m3; i++) {
		delete matrix1Dyn[i];
	}

	delete[] matrix1Dyn;



	for (int i = 0; i < m5; i++)
	{
		delete matrix2Dyn[i];
	}

	delete[] matrix2Dyn;


	for (int i = 0; i < 1; i++) 
	{
		delete vect_Dyn[i];
	}

	delete[] vect_Dyn;

	for (int i = 0; i < 1; i++) 
	{
		delete vect1Dyn[i];
	}

	delete[] vect1Dyn;

	for (int i = 0; i < 1; i++)
	{
		delete vect2Dyn[i];
	}

	delete[] vect2Dyn;

	for (int i = 0; i < v1; i++) {
		delete matrix_vect_Dyn[i];
	}

	delete[] matrix_vect_Dyn;


	cout << endl;
	system("pause");

	return 0;
	
}