#include "FillRand.h"


void FillRand(int Arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % (max - min) + min;
	}
}

void FillRand(float Arr[], const int n, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < n; i++)
	{
		Arr[i] = float(rand() % (max - min) + min) / 100;
	}
}

void FillRand(double Arr[], const int n, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < n; i++)
	{
		Arr[i] = double(rand() % (max - min) + min) / 100;
	}
}

void FillRand(char Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand();
	}
}


void FillRand(int** Arr, const int rows, const int cols, int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = rand() % (max - min) + min;
		}
	}
}

void FillRand(float** Arr, const int rows, const int cols, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = float(rand() % (max - min) + min) / 100;
		}
	}
}

void FillRand(double** Arr, const int rows, const int cols, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = double(rand() % (max - min) + min) / 100;
		}
	}
}

void FillRand(char** Arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = rand();
		}
	}
}
