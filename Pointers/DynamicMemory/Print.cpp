#include "Print.h"

template <typename T>
void Print(T Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
}

template <typename T>
void Print(T** Arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
}
