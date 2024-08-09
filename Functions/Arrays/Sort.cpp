#include "Sort.h"

void Sort(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}

void Sort(double arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}
void Sort(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				int Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}