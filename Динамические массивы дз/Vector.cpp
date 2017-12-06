#include "stdafx.h"
#include "Vector.h"
#include <iostream>
using namespace std;

void Vector::write_matrix(int **B, int f)
{
	for (int i = 0; i < f; i++)
	{
		cout << B[0][i] << " \t";
	}
	cout << endl;
}

void Vector::s_proizvedenie(int **& B1, int f, int **& B2, int g, int & C)
{
	if (g == f)
	{
		C = 0;
		for (int i = 0; i < 3; i++)
		{
			C = C + B1[0][i] * B2[0][i];
		}
	}
	else 
	{ 
		cout << "Impossible" << endl; 
	}
}

void Vector::v_proizvedenie(int **& B1, int f, int **& B2, int g, int **& B)
{
	if (f != 3 || g != 3)
	{ 
		cout << "Impossible" << endl; 
	}
	else 
	{
		if (f == g)
		{
			for (int i = 0; i < f; i++)
			{
				B[0][i] = B1[0][(i + 1) % 3] * B2[0][(i + 2) % 3] - B1[0][(i + 2) % 3] * B2[0][(i + 2) % 3];

			}
		}
		else 
		{ 
			cout << "Impossible" << endl;
		}
	}
}

void Vector::matrix_vector(int **& A1, int c, int d, int **& B1, int f, int **& B)
{
	if (d == f)
	{
		for (int i = 0; i < d; i++) 
		{ 
			B[0][i] = 0; 
		}
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < f; j++)
			{
				B[0][i] = B[0][i] + A1[i][j] * B1[0][j];
			}
		}
	}
	else 
	{ 
		cout << "Impossible" << endl;
	}
}

Vector::Vector()
{
	cin >> g;
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[g];

	}
	for (int i = 0; i < g; i++)
	{
		B[0][i] = 0;

	}

}
Vector::Vector(int **B1, int f)
{
	for (int i = 0; i < 1; i++)
	{
		B[i] = new int[f];

	}
	for (int i = 0; i < f; i++)
	{
		B[0][i] = B1[0][i];

	}
}

Vector::~Vector()
{
}