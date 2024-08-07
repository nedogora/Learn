#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n, int min, int max);	//Заполняет массив случайными числами. Обычно массив заполняется случайными числами от 0-100, но при необходимости пользователь может передать пределы генерации случайных чисел
void Print(int arr[], const int n);		//Выводит массив на экран
int Sum(int arr[], const int n);	//Возвращает сумму э-ов массива
double Avg(int arr[], const int n);		//Возвращает среднее арифметическое
int MinValueIn(int arr[], const int n);		//Мin значение
int MaxValueIn(int arr[], const int n);		//Max значение
void Sort(int arr[], const int n);	//Сортировка
void ShiftLeft(int arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов влево
void ShiftRight(int arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов вправо

void main()
{
	setlocale(LC_ALL, "");
	const int n = 5;
	int arr[n];
	
	FillRand(arr, n, 0, 10);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	cout << "\nShift Left:" << endl;
	ShiftLeft(arr, n, 2);

	Print(arr, n);

	cout << "\nShift Right:" << endl;
	ShiftRight(arr, n, 2);

	Print(arr, n);

	cout << "\nSum: " << Sum(arr, n) << endl;
	cout << "Avg: " << Avg(arr, n) << endl;
	cout << "Min: " << MinValueIn(arr, n) << endl;
	cout << "Max: " << MaxValueIn(arr, n) << endl;
}

void FillRand(int arr[], const int n, int min, int max)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % (max - min) + min;
	}
}
void Print(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

int Sum(int arr[], const int n)
{
	int s = 0;
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

int MaxValueIn(int arr[], const int n)
{
	int max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

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

void ShiftRight(int arr[], const int n, int c)
{
	for (int i = 0; i < c; i++)
	{
		for (int j = n - 1; j > 0; j--)
		{
			int Temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = Temp;
		}
	}
}