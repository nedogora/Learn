#include "Shift.h"

void ShiftLeft(int arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

void ShiftLeft(double arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}

void ShiftLeft(char arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			int Temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = Temp;
		}
	}
}



void ShiftRight(int arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

void ShiftRight(double arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}

void ShiftRight(char arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}