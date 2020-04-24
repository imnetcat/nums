#pragma once
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
#include <sstream>
using namespace std;

class Matrix
{
public:
	Matrix();
	Matrix(int num_rows, int num_cols);
	void Reset(int num_rows, int num_cols);

	ostream& operator<<(ostream& out) const;
	int At(int m, int n) const;
	int & At(int m, int n);
	int GetNumRows() const;
	int GetNumColumns() const;
private:

	using matrix_item = int;
	using matrix_row = vector<matrix_item>;
	vector<matrix_row> matrix;
	int rows;
	int colums;
};

istream& operator>>(istream& in, Matrix& matrix);
ostream& operator<<(ostream& out, const Matrix& matrix);
bool operator == (Matrix matrix1, Matrix matrix2);
Matrix operator + (Matrix matrix1, Matrix matrix2);

