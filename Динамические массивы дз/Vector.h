#pragma once
class Vector
{
private:
	int g;
	int ** B = new int *[1];

public:
	Vector();
	Vector(int **B1, int f);

	void write_matrix(int **B, int f);
	void s_proizvedenie(int **& B1, int f, int **& B2, int g, int & C);
	void v_proizvedenie(int **& B1, int f, int **& B2, int g, int **& B);
	void matrix_vector(int **& A1, int c, int d, int **& B1, int f, int **& B);

	~Vector();
};