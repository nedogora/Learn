#include "FillRand.h"

void FillRand(int arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}

void FillRand(double arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}

void FillRand(char arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}