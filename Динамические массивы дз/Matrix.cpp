#include "stdafx.h"
#include "Matrix.h"
#include <iostream>

using namespace std;

void Matrix::write_matrix(int ** A, int a, int b)
{
	for (int i = 0; i < a; i++) {
		for (int j = 0; j < b; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix::slozhenie(int **& A1, int c, int d, int **& A2, int e, int l, int **& A)
{
	if (c == e && d == l)
	{
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < d; j++)
			{
				A[i][j] = 0;
				A[i][j] = A1[i][j] + A2[i][j];
			}
		}
	}
	else 
	{ 
		cout << "Impossible" << endl; 
	}
}

void Matrix::umnozhenie(int **& A1, int c, int d, int **& A2, int e, int l, int **& A)
{
	if (c == l)
	{
		for (int i = 0; i < c; i++)
		{
			for (int j = 0; j < d; j++)
			{
				A[i][j] = 0;
				for (int k = 0; k < d; k++)
					A[i][j] = A[i][j] + A1[i][k] * A2[k][j];
			}
		}
	}
	else 
	{ 
		cout << "Impossible" << endl; 
	}
}



Matrix::Matrix()
{
	cin >> a;
	cin >> b;

	for (int i = 0; i < a; i++)
	{
		A[i] = new int[b];

	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			A[i][j] = 0;
		}
	}
}

Matrix::Matrix(int **A1, int c, int d)
{
	c = a;
	d = b;
	for (int i = 0; i < a; i++)
	{
		A[i] = new int[b];

	}

	for (int i = 0; i< a; i++)
	{
		for (int j = 0; j < b; j++) 
		{
			A[i][j] = A1[i][j];
		}
	}
}

Matrix::~Matrix()
{

}