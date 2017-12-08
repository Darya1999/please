#include "stdafx.h"
#include "Matrixx.h"
#include <iostream>

using namespace std;


void Matrixx::umnozh(Matrixx obj1, Matrixx obj2, Matrixx obj3)
{
	int a = obj1.n;
	int b = obj1.l;
	int d = obj2.n;
	int e = obj2.l;
	int otv;

	if ((a == e) && (b != 1) && (e != 1))
	{
		int n = a;
		int l = b;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < l; j++)
			{
				obj3.A[i][j] = 0;
				for (int k = 0; k < b; k++)
					obj3.A[i][j] = obj3.A[i][j] + obj1.A[i][k] * obj2.A[k][j];
			}
		}
		write(obj3);
	}
	if ((b == 1) && (e == 1)) 
	{
		int o = b;
		int y = e;
		if (o == y) 
		{
			int otv = 0;
			for (int i = 0; i < o; i++) {
				otv = otv + obj1.A[0][i] + obj2.A[0][i];
			}
		} cout << otv << endl;
	}
	else 
	{ 
		cout << "Impossible" << endl;
	}
}
void Matrixx::slozh(Matrixx obj1, Matrixx obj2, Matrixx obj3)
{}
void write(Matrixx obj3)
{}



Matrixx::Matrixx()
{
	cin >> n;
	cin >> l;

	for (int i = 0; i < n; i++)
	{
		A[i] = new int[l];

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < l; j++)
		{
			A[i][j] = 0;
		}
	}
}

Matrixx::Matrixx(int **A1, int a, int b)
{
	a = n;
	b = l;
	for (int i = 0; i <n; i++)
	{
		A[i] = new int [l];

	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < l; j++) {
			A[i][j] = A1[i][j];
		}
	}
}


Matrixx::~Matrixx()
{	
}