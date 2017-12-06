#pragma once

#include <iostream>
using namespace std;

class Matrix
{
private:

	int a;
	int b;
	int ** A = new int *[a];

public:
	Matrix();
	Matrix(int **A, int a, int b);

	void slozhenie(int **& A1, int c, int d, int **& A2, int e, int l, int **& A);
	void umnozhenie(int **& A1, int c, int d, int **& A2, int e, int l, int **& A);
	void write_matrix(int **A, int a, int b);
	~Matrix();

};