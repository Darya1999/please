// Динамические массивы дз.cpp : Defines the entry point for the console application.

#include "stdafx.h"
#include "Matrix.h"
#include "Vector.h"

int main()
{
	int  a = 3;
	int b = 3;

	int ** A = new int *[a];
	for (int i = 0; i < a; i++)
	{
		A[i] = new int[b];
	}
	Matrix Matrix1(A, a, b);
	Matrix Matrix2();

	system("pause");
	return 0;
}