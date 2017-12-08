#pragma once
class Matrixx
{
private:
	int n;
	int l;
	int ** A = new int *[n];

public:
	Matrixx();
	Matrixx(int **A, int a, int b);
	void umnozh(Matrixx matr1, Matrixx matr2, Matrixx matr3);
	void slozh(Matrixx obj1, Matrixx obj2, Matrixx obj3);
	void write(Matrixx obj3);

	~Matrixx();
};