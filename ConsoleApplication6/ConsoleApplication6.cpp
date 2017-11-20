// Funct_DynamicMassives.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>


using namespace std;

void vyvod_mat(int ** matrixDyn, int l1, int l2)
{
	for (int i = 0; i < l1; i++) {
		for (int j = 0; j < l2; j++)
		{
			std::cout << matrixDyn[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void vyvod_vect(int** vectorDyn, int g1)
{
	for (int i = 0; i < 3; i++) {
		std::cout << vectorDyn[0][i] << " \t";
	}
	std::cout << std::endl;
}

void matrix_slozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
{
	if (l3 == l5 | l4 == l6) {
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < l2; j++) {
				matrixDyn[i][j] = 0;

				matrixDyn[i][j] = matrix1Dyn[i][j] + matrix2Dyn[i][j];

			}
		}
		vyvod_mat(matrixDyn, l1, l2);
	}
	else { cout << "Sum cant be found"; }
}





void vect_slozh(int**& vectSumDyn, int **v1, int g1, int ** v2, int g2)
{
	if (g1 == g2) {
		for (int i = 0; i < g1; i++) {
			vectSumDyn[0][i] = 0;

			vectSumDyn[0][i] = v1[0][i] + v2[0][i];

		}
		vyvod_vect(vectSumDyn, g1);
	}
}






void matrix_umnozh(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int** matrix2Dyn, int l5, int l6)
{
	if (l3 == l6 | l4 == l5) {
		int l1 = l3;
		int l2 = l4;
		for (int i = 0; i < l1; i++) {
			for (int j = 0; j < l2; j++) {

				matrixDyn[i][j] = 0;

				for (int k = 0; k < l2; k++)

					matrixDyn[i][j] = matrixDyn[i][j] + matrix1Dyn[i][k] * matrix2Dyn[k][j];

			}
		}
		vyvod_mat(matrixDyn, l1, l2);
	}
	else { cout << "Uncountable pair of matrix" << endl; }
}

void matrix_x_vect(int**& matrixDyn, int** matrix1Dyn, int l3, int l4, int **v1, int g1)
{
	if (l4 == g1) {
		for (int i = 0; i < l3; i++) {
			for (int j = 0; j < l4; j++) {

				matrixDyn[0][1] = matrixDyn[0][1] + matrix1Dyn[i][j] * v1[0][j];
			}
		}
		vyvod_vect(matrixDyn, g1);
	}
	else { cout << "Uncountable" << endl; }
}

void vect_skal(int &otv, int **v1, int g1, int ** v2, int g2)
{
	if (g1 == g2) {
		otv = 0;
		for (int i = 0; i < 3; i++) {

			otv = otv + v1[0][i] * v2[0][i];
		}
		cout << otv << endl;
	}
	else { cout << "Uncountable" << endl; }
}
void vect_vect(int **& matrixVectDyn, int **v1, int g1, int ** v2, int g2, int**& vectSumDyn)
{
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 3; j++) {

				matrixVectDyn[i][j] = 1;
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < 3; j++) {

					matrixVectDyn[i][j] = v1[0][j];

				}
			}
			else {
				for (int j = 0; j < 3; j++) {

					matrixVectDyn[i][j] = v2[0][j];

				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		vectSumDyn[0][i] = 0;
	}
	for (int i = g1 - 1; i > -1; i--) { //ПРИДУМАТЬ РЕШЕНИЕ ДЛЯ МАТРИЦ НЕ 3х3
		(i == 0) ?
			(vectSumDyn[0][i] = matrixVectDyn[1][(i + 1) / 3] * matrixVectDyn[2][i + 1] - matrixVectDyn[1][i + 1] * matrixVectDyn[2][(i + 1) / 3])
			:
			(vectSumDyn[0][i] = matrixVectDyn[1][(i + 1) / 3] * matrixVectDyn[2][2] - matrixVectDyn[1][2] * matrixVectDyn[2][(i + 1) / 3]);
	}
	vyvod_vect(vectSumDyn, g1);
}


int main()
{
	int l1;

	int l2;

	int l3;

	int l4;

	int l5;

	int l6;



	int g2;
	int g1;

	cout << "Enter first matrix length " << endl;

	cin >> l3;
	l1 = l3;
	cout << "Enter first matrix width " << endl;

	cin >> l4;
	l2 = l4;
	cout << "Enter second matrix length " << endl;

	cin >> l5;

	cout << "Enter second matrix width " << endl;

	cin >> l6;

	cout << "Enter first vector length " << endl;

	cin >> g1;

	cout << "Enter second vector length " << endl;

	cin >> g2;
	int ** matrixVectDyn = new int *[l3];
	for (int i = 0; i < l1; i++)
	{
		matrixVectDyn[i] = new int[l2];

	}

	int ** matrixDyn = new int *[l1];

	int ** matrix1Dyn = new int *[l3];

	int ** matrix2Dyn = new int *[l5];

	for (int i = 0; i < l1; i++)
	{
		matrixDyn[i] = new int[l2];

	}
	for (int i = 0; i < l1; i++)
	{
		matrix1Dyn[i] = new int[l4];

	}
	for (int i = 0; i < l1; i++)
	{
		matrix2Dyn[i] = new int[l6];

	}


	int ** vectDyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vectDyn[i] = new int[g1];

	}

	int ** vect1Dyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vect1Dyn[i] = new int[g1];

	}

	int ** vect2Dyn = new int *[1];
	for (int i = 0; i < 1; i++)
	{
		vect2Dyn[i] = new int[g2];

	}


	for (int i = 0; i < g1; i++) {
		vect1Dyn[0][i] = rand() % 5;
	}
	for (int i = 0; i < g2; i++) {
		vect2Dyn[0][i] = rand() % 5;
	}

	for (int i = 0; i < l3; i++) {
		for (int j = 0; j < l4; j++)
		{
			matrix1Dyn[i][j] = rand() % 5;

		}
	}
	for (int i = 0; i < l5; i++) {
		for (int j = 0; j < l6; j++)
		{
			matrix2Dyn[i][j] = rand() % 5;

		}
	}
	int matrix_vect[3][3];

	int otv = 0;

	int matrix1[3][3] = { { 1, 2, 3 },
	{ 4, 5, 6 },
	{ 7, 8, 9 } };

	int matrix2[3][3] = { { 10, 11, 12 },
	{ 13, 14, 15 },
	{ 16, 17, 18 } };

	int matrix_sum[3][3] = { { 0,0,0 },
	{ 0,0,0 },
	{ 0,0,0 } };

	int v1[1][3] = { 1, 2, 3 };

	int v2[1][3] = { 1, 2, 3 };

	int v_sum[1][3] = { 0,0,0 };

	cout << endl << endl;
	cout << "Matrix Sum" << endl;
	matrix_slozh(matrixDyn, matrix1Dyn, l3, l4, matrix2Dyn, l5, l6);

	cout << endl << endl;
	cout << "Vect Sum" << endl;

	vect_slozh(vectDyn, vect1Dyn, g1, vect2Dyn, g2);

	cout << endl << endl;
	cout << "Matr Prod" << endl;
	matrix_umnozh(matrixDyn, matrix1Dyn, l3, l4, matrix2Dyn, l5, l6);

	cout << endl << endl;
	cout << "Matr_X_Vect Prod" << endl;
	matrix_x_vect(vectDyn, matrix1Dyn, l3, l4, vect1Dyn, g1);

	cout << endl << endl;
	cout << "Skal Prod" << endl;

	vect_skal(otv, vect1Dyn, g1, vect2Dyn, g2);

	cout << endl << endl;
	cout << "Vect Prod" << endl;

	vect_vect(matrixVectDyn, vect1Dyn, g1, vect2Dyn, g2, vectDyn);



	cin >> l4;
	return 0;

}