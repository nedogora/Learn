#include "ShiftRight.h"

template <typename T>
void ShiftRight(T arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

template <typename T>
void ShiftRight(T arr[ROWS][COLS], const int ROWS, const int COLS, int c)
{
	ShiftLeft(arr, ROWS, COLS, COLS - c);
}