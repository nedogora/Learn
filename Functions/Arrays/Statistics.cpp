#include "Statistics.h"

int Sum(int arr[], const int n)
{
	int s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}

double Sum(double arr[], const int n)
{
	double s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}


double Avg(int arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}


int MinValueIn(int arr[], const int n)
{
	int min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

double MinValueIn(double arr[], const int n)
{
	double min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

char MinValueIn(char arr[], const int n)
{
	char min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}


int MaxValueIn(int arr[], const int n)
{
	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

double MaxValueIn(double arr[], const int n)
{
	double max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}
char MaxValueIn(char arr[], const int n)
{
	char max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}