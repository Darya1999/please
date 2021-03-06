// Templates.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include <iostream>
//ШАБЛОНЫ
using namespace std;
//в ходе изучения было выяснено, что во время выполнения программы можно менять размерности массива, но не его тип

//однако на уровне исходного кода (текста программы) можно использовать с минимальными изменениями 
//одни и те же фрагменты, а также целые функции и класы с различными типами данных
//Например, настроить вектора и матрицы из ДЗ на работу с double, long long, short, char с минимальной доработкой
template <typename SomeType>
int fnc1(SomeType p1, SomeType p2) {
	cout << typeid(SomeType).name() << endl;
	return p1 / p2;
}
template <typename SomeType,
	typename SomeType2,
	typename SomeType2,
	int n>
	int fnc1(SomeType p1, SomeType p2) {
	cout << typeid(SomeType).name() << endl;
	double tmp = p1;
	for (int i = 0; i < n; i++) {
		p1 /= p2;
	}
	return p1 / p2;
}
//Каждый раз, компилятор анализирует каждый вызов шаблонной функции и определяет, какой тип аргументов использвует
//и под каждый набор аргументов создает неявно от кодера реализацию-перегрузку данного типа
//то есть, вместо того, чтобы написать несколько перегрузок под разные типы данных
//программист задает неявное правило, по которому компилятор сам создает перегрузки
int main()
{
	double d = 10.5;
	char c = 15;
	unsigned long long l = 100500;

	fnc1(d, d);
	fnc1<int>(c, c); //в угловых скобках компилятору можно явно задать тип данных
	fnc1(l, l);

	getchar();
	return 0;
}
