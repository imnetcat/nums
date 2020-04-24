#include "matrix.h"

Matrix::Matrix()
{
	rows = 0;
	colums = 0;
}
Matrix::Matrix(int num_rows, int num_cols)
{
	Reset(num_rows, num_cols);
}
void Matrix::Reset(int num_rows, int num_cols)
{
	rows = num_rows;
	colums = num_cols;
	if (num_rows < 0 || num_cols < 0)
		throw out_of_range("");

	if (num_rows == 0 || num_cols == 0)
	{
		matrix.clear();
		return;
	}

	matrix.assign(num_rows, vector<matrix_item>(num_cols, 0));
}

ostream& Matrix::operator<<(ostream& out) const
{
	out << this->GetNumRows() << " " << this->GetNumColumns() << endl;
	for (int row = 0; row < this->GetNumRows(); ++row) {
		for (int column = 0; column < this->GetNumColumns(); ++column) {
			if (column > 0) {
				out << " ";
			}
			out << this->At(row, column);
		}
		out << endl;
	}

	return out;
}
int Matrix::At(int m, int n) const
{
	if ((n < 0) || (n > rows)) {
		stringstream s;
		this->operator<<(s);
		throw std::out_of_range("m = " + to_string(m) + " n = " + to_string(n) + " matrix = " + s.str());
	}
	if ((m < 0) || (m > colums)) {
		stringstream s;
		this->operator<<(s);
		throw std::out_of_range("m = " + to_string(m) + " n = " + to_string(n) + " matrix = " + s.str());
	}
	return matrix.at(m).at(n);
}
int & Matrix::At(int m, int n)
{
	if ((m < 0) || (m > rows)) {
		stringstream s;
		this->operator<<(s);
		throw std::out_of_range("m = " + to_string(m) + " n = " + to_string(n) + " matrix = " + s.str());
	}
	if ((n < 0) || (n > colums)) {
		stringstream s;
		this->operator<<(s);
		throw std::out_of_range("m = " + to_string(m) + " n = " + to_string(n) + " matrix = " + s.str());
	}
	return matrix.at(m).at(n);
}
int Matrix::GetNumRows() const
{
	return matrix.size();
}
int Matrix::GetNumColumns() const
{
	if (!matrix.size())
	{
		return 0;
	}

	return matrix.at(0).size();
}
	
istream& operator>>(istream& in, Matrix& matrix) {
	int num_rows, num_columns;
	in >> num_rows >> num_columns;

	matrix.Reset(num_rows, num_columns);
	for (int row = 0; row < num_rows; ++row) {
		for (int column = 0; column < num_columns; ++column) {
			in >> matrix.At(row, column);
		}
	}

	return in;
}
ostream& operator<<(ostream& out, const Matrix& matrix) {
	out << matrix.GetNumRows() << " " << matrix.GetNumColumns() << endl;
	for (int row = 0; row < matrix.GetNumRows(); ++row) {
		for (int column = 0; column < matrix.GetNumColumns(); ++column) {
			if (column > 0) {
				out << " ";
			}
			out << matrix.At(row, column);
		}
		out << endl;
	}

	return out;
}
bool operator == (Matrix matrix1, Matrix matrix2)
{
	int m1 = matrix1.GetNumRows(),
		n1 = matrix1.GetNumColumns(),
		m2 = matrix2.GetNumRows(),
		n2 = matrix2.GetNumColumns();
	if (m1 != m2 || n1 != n2)
		return false;

	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			if (matrix1.At(i, j) != matrix2.At(i, j))
				return false;
		}
	}

	return true;
}

Matrix operator + (Matrix matrix1, Matrix matrix2)
{
	int m1 = matrix1.GetNumRows(),
		n1 = matrix1.GetNumColumns(),
		m2 = matrix2.GetNumRows(),
		n2 = matrix2.GetNumColumns();
	if (m1 != m2 || n1 != n2)
		throw invalid_argument("");

	Matrix result(m1, n1);
	for (int i = 0; i < m1; i++)
	{
		for (int j = 0; j < n1; j++)
		{
			result.At(i, j) = matrix1.At(i, j) + matrix2.At(i, j);
		}
	}

	return result;
}

