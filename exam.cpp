#include "stdafx.h"
#include <iostream>
#include "exam.h"

using namespace std;


exam::exam()  //создание класса
{
	int x = 0;
	int *st = 0;
	int *new_st = 0;
}

exam::exam(const exam& other) // создание строки
{
	x = other.x;
	st = new char[x];
	for (int i = 1; i < x; i++)
	{
		st[i] = other.st[i];
	}
}

char exam::get(int i) // чтение строки
{
	if ((st != 0) && (i < x))
	{
	return st[i];
	}
	else
	{
		return 0;
	}
}

char exam::insert(int i, char val) // запись строки
{
	if ((st != 0) && (i < x))
	{
	st[i] = val;
	}
	else
	{
		return 0;
	}
}


exam::exam(const char *source)//копирует содержимое из массива char
{
	x = 0;
	while (source[x] != 0)
	{
		x++;
	}
	max = x;
	st = new char[max];
	for (int i = 0; i < x; i++)
	{
	str1_Dyn[i] = source[i];
	}
}

int exam::num() // размер строки
{
	return 0;
}

void exam::print() //вывод строки
{
	for (int i = 0; i < x; i++)
	{
		cout << get(i) << " ";
	}
}

void exam::add(char s) // добавление элемента в конец
{
	if (x + 1 > max)
	{
		grow();
	}
	st[x] = s;
	x = x + 1;
}

void exam::grow() // увеличение размера строки
{
	new_st = new char[2 * max + 1];
	for (int i = 0; i < x; i++)
	{
		new_st[i] = st[i];
	}
	delete[]st;
	st = new_st;
	max = 2 * max + 1;
}

void exam::clear() // удаление строки
{
	x = 0;
}
exam::~exam()
{
	delete[] st;
}
