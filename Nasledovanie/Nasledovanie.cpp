// Nasledovanie.cpp : Defines the entry point for the console application.
#include "stdafx.h"
#include "Vector.h"
#include "matrixx.h"
#include <iostream>

using namespace std;

int main()
{
	Matrixx m1;
	m1.set_size(3, 3); //матрица 1 размером 3х3 
	cout << m1 << endl; // вывод матрицы 
	m1.set_size(1, 4); //матрица 1 размером 1х4
	cout << m1 << endl; // вывод матрицы 
	for (int i = 0; i < m1.num_rows(); i++)
	{
		for (int j = 0; j < m1.num_cols(); j++)
		{
			m1.set(i, j, rand() % 100); // заполнение рандомными числами 
		}
	}
	cout << m1 << endl; // вывод матрицы 

	Matrixx m2(4, 1); //вторая матрица
	for (int i = 0; i < m2.num_rows(); i++)
	{
		for (int j = 0; j < m2.num_cols(); j++)
		{
			m2.set(i, j, rand() % 100); // заполнение рандомными числами 
		}
	}

	cout << m2 << endl; // вывод матрицы 

	cout << m1 * m2 << endl; //проверка перегрузки оператора * 


	Vector v1(3); // создание вектора 1 
	Vector v2(3); // создание вектора 2 

	for (int i = 0; i < v1.num_rows(); i++)
	{
		v1.set(i, 0, rand() % 100); // заполнение рандомными числами 
		v2.set(i, 0, rand() % 100); // заполнение рандомными числами 
	}
	cout << v1 << endl; // вывод первого вектора 
	cout << v2 << endl; // вывод второго вектора 
	cout << v1 + v2 << endl; // проверка перегрузки оператора +

	Vector v5(2); // создание вектора 5 
	Vector v6(2); // создание вектора 6 

	for (int i = 0; i < v5.num_rows(); i++)
	{
		v5.set(i, 0, rand() % 100); // заполнение рандомными числами
		v6.set(i, 0, rand() % 100); // заполнение рандомными числами
	}
	cout << v5 << endl; // вывод вектора 5 
	cout << v6 << endl; // вывод вектора 6 
	cout << v5 * v6 << endl; //проверка перегрузки оператора *

	system("pause");
	return 0;
}