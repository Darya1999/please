// ДЗ №1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;


int main()
{
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
	int vect2[1][3] = { 4, 5, 6 };
	int vect_res[1][3] = { 0,0,0 };
	int otv = 0;
	int vect_vect[3][3];
	
	//сложение матриц

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_res[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix_res[i][j] << " \t";
		}
		cout << endl;
	}
	cout << endl;

	//сложение векторов

	for (int j = 0; j < 3; j++)
	{
		vect_res[0][j] = 0;
		vect_res[0][j] = vect1[0][j] + vect2[0][j];
	}
	cout << vect_res[0][0] << endl;
	cout << vect_res[0][1] << endl; 
	cout << vect_res[0][2] << endl;
	cout << endl;

	//умножение матриц

	cout << endl;
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
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix_res[i][j] << " \t";
		}
		cout << endl;
	}
	cout << endl;

	//умножение матрицы на вектор

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			matrix_res[i][j] = 0;
			matrix_res[i][0] = matrix_res[i][0] + matrix1[i][j] * vect1[0][j];
		}
	}
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matrix_res[i][j] << " \t";
		}
		cout << endl;
	}
	cout << endl;

	//скалярное умножение векторов

	otv = 0;
	for (int j = 0; j < 3; j++)
	{
		otv = otv + vect1[0][j] * vect2[0][j];
	}
	cout << otv << endl;
	cout << endl;

	// векторное умножение векторов

	for (int i = 0; i < 3; i++)
	{
		if (i == 0) 
		{
			for (int j = 0; j < 3; j++) 
			{
				vect_vect[i][j] = 1; //присвоение элементам первой строки значений единицы (т.к. там единичные векторы)
			}

		}
		else 
		{
			if (i == 1) 
			{
				for (int j = 0; j < 3; j++) 
				{
					vect_vect[i][j] = vect1[0][j];  //присвоение второй строке значений первого вектора
				}
			}
			else 
			{
				for (int j = 0; j < 3; j++) 
				{
					vect_vect[i][j] = vect2[0][j]; //присвоение третьей строке значений второго вектора
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) 
	{
		vect_res[0][i] = 0; //обнуление вектора в который будет записываться результат
	}

	vect_res[0][0] = vect_vect[1][1] * vect_vect[2][2] - vect_vect[1][2] * vect_vect[2][1];
	cout << vect_res[0][0] << "\n";

	vect_res[0][1] = vect_vect[1][0] * vect_vect[2][2] - vect_vect[1][2] * vect_vect[2][0];
	cout << vect_res[0][1] << "\n";

	vect_res[0][2] = vect_vect[1][0] * vect_vect[2][1] - vect_vect[1][1] * vect_vect[2][0];
	cout << vect_res[0][2] << "\n";  //вычисление определителя матрицы matrix_vect, запись результата и его вывод

	system("pause");
	return 0;
}
