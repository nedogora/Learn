#include "Sum.h"

template <typename T>
T Sum(T arr[], const int n)
{
	T s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}

template <typename T>
T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS)
{
	T s = 0;
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			s += arr[i][j];
		}
	}

	return s;
}