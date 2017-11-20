// VectorMatrix.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

//сложение матриц, сложение векторов, умножение матриц,
//умножение матрицы на вектор, скалярное умножение векторов, 
//векторное умножение векторов реализовать программно

int main()
{
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
	// сложение матриц
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = matrix1[i][j] + matrix2[i][j];
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << " \t";
		}
		std::cout << std::endl;
	}

	//сложение векторов
	for (int i = 0; i < 3; i++) {
		v_sum[0][i] = v1[0][i] + v2[0][i];
	}

	std::cout << std::endl;

	std::cout << v_sum[0][0] << "\n" << v_sum[0][1] << "\n" << v_sum[0][2] << std::endl;

	std::cout << std::endl;

	//умножение матриц
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = 0;
			{
				for (int k = 0; k < 3; k++)
					matrix_sum[i][j] = matrix_sum[i][j] + matrix1[i][k] * matrix2[k][j];
			}
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << "\t ";
		}
		std::cout << std::endl;

	}
	std::cout << std::endl;


	//матрица на вектор
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][j] = 0;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			matrix_sum[i][0] = matrix_sum[i][0] + matrix1[i][j] * v1[0][j];
		}
	}
	std::cout << std::endl;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			std::cout << matrix_sum[i][j] << " \t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
	//скалярное пр-ие
	otv = 0;
	for (int i = 0; i < 3; i++) {
		otv = otv + v1[0][i] * v2[0][i];
	}
	std::cout << otv << std::endl;
	std::cout << std::endl;
	//векторное произведение
	int matrix_vect[3][3]; //объявление матрицы для последующего вычисления определителя
	for (int i = 0; i < 3; i++) {
		if (i == 0) {
			for (int j = 0; j < 3; j++) {
				matrix_vect[i][j] = 1; //присвоение элементам первой строки значений единицы (т.к. там единичные векторы)
			}

		}
		else {
			if (i == 1) {
				for (int j = 0; j < 3; j++) {
					matrix_vect[i][j] = v1[0][j];  //присвоение второй строке значений первого вектора
				}
			}
			else {
				for (int j = 0; j < 3; j++) {
					matrix_vect[i][j] = v2[0][j]; //присвоение третьей строке значений второго вектора
				}
			}
		}
	}

	for (int i = 0; i < 3; i++) {
		v_sum[0][i] = 0; //обнуление вектора в который будет записываться результат
	}

	v_sum[0][0] = matrix_vect[1][1] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][1];
	std::cout << v_sum[0][0] << "\n";
	v_sum[0][1] = matrix_vect[1][0] * matrix_vect[2][2] - matrix_vect[1][2] * matrix_vect[2][0];
	std::cout << v_sum[0][1] << "\n";
	v_sum[0][2] = matrix_vect[1][0] * matrix_vect[2][1] - matrix_vect[1][1] * matrix_vect[2][0];
	std::cout << v_sum[0][2] << "\n";  //вычисление определителя матрицы matrix_vect, запись результата и его вывод
	getchar();
	return 0;
}