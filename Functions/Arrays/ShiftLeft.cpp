#include "ShiftLeft.h"

template <typename T>
void ShiftLeft(T arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			T Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

template <typename T>
void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, int c)
{
	for (int r = 0; r < ROWS; r++) ShiftLeft(arr[r], COLS, c);
}