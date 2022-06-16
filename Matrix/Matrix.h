#include <iostream>
#include <fstream>
#include <string>

using namespace std;
class Matrix
{
public:
	int size;
	int** A;
	int* B;

	Matrix(int s)
	{
		size = s;
		A = new int* [size];
		B = new int[size];
	}

	void FillMatrix()
	{
		for (auto i = 0; i < size; i++)
		{
			A[i] = new int[size];
			for (auto j = 0; j < size; j++)
			{
				cout << "[" << i << "]" << "[" << j << "]= ";
				cin >> A[i][j];
			}
		}
		cout << endl;
	}

	void PrintMatrix()
	{
		cout << "Matrix A is:" << endl;
		for (auto i = 0; i < size; i++)
		{
			for (auto j = 0; j < size; j++)
			{
				cout << A[i][j] << " ";
			}
			cout << endl;
		}
	}

	void Sum()
	{
		int sum = 0;
		for (auto i = 0; i < size; i++)
		{
			for (auto j = 0; j < size; j++)
			{
				sum += A[i][j];
			}
		}
		cout << "Sum is: " << sum << endl << endl;
	}

	void SumByRows()
	{
		for (auto i = 0; i < size; i++)
		{
			int sum = 0;
			for (auto j = 0; j < size; j++)
			{
				sum += A[i][j];
			}
			B[i] = sum;
		}
	}

	void PrintRows()
	{
		cout << "Sum of rows (Array B): ";
		for (auto i = 0; i < size; i++)
		{
			cout << B[i] << " ";
		}
		cout << endl;
	}

	void MaxRows()
	{
		int max = B[0];
		for (auto i = 1; i < size; i++)
		{
			if (max < B[i])
			{
				max = B[i];
			}
		}
		cout << "Max element rows: " << max << endl;
	}

	void MinRows()
	{
		int min = B[0];
		for (auto i = 1; i < size; i++)
		{
			if (min > B[i])
			{
				min = B[i];
			}
		}
		cout << "Min element rows: " << min << endl << endl;
	}

	void SaveToFile()
	{
		ofstream myfile;
		myfile.open("Matrix.txt");
		myfile << size << endl;

		for (auto i = 0; i < size; i++)
		{
			for (auto j = 0; j < size; j++)
			{
				myfile << A[i][j] << " ";
			}
			myfile << endl;
		}
		myfile.close();
		cout << "Successfully saved to file!" << endl;
	}

	void LoadFromFile()
	{
		ifstream myfile;
		myfile.open("Matrix.txt");
		myfile >> size;
		string line;

		while (getline(myfile, line))
		{
			cout << line << endl;
		}
		myfile.close();
		cout << "Successfully loaded from file!" << endl;
	}
};
