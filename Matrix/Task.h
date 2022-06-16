#include <iostream>
#include "Matrix.cpp"

int main()
{
	cout << "Enter size of the Matrix: ";
	int size = 0;
	cin >> size;
	Matrix matrix = Matrix(size);

	matrix.FillMatrix();

	matrix.PrintMatrix();
	matrix.Sum();

	matrix.SumByRows();
	matrix.PrintRows();
	matrix.MaxRows();
	matrix.MinRows();

	matrix.SaveToFile();
	matrix.LoadFromFile();
}

