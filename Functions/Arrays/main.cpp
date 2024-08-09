#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n, int min, int max);	//Заполняет массив случайными числами. Обычно массив заполняется случайными числами от 0-100, но при необходимости пользователь может передать пределы генерации случайных чисел
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n);

template <typename T> void Print(T arr[], const int n);		//Выводит массив на экран
template <typename T> T Sum(T arr[], const int n);	//Возвращает сумму э-ов массива
template <typename T> double Avg(T arr[], const int n);		//Возвращает среднее арифметическое
template <typename T> T MinValueIn(T arr[], const int n);		//Мin значение
template <typename T> T MaxValueIn(T arr[], const int n);		//Max значение
template <typename T> void Sort(T arr[], const int n);	//Сортировка
template <typename T> void ShiftLeft(T arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов влево
template <typename T> void ShiftRight(T arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов вправо

void main()
{
	setlocale(LC_ALL, "");
	const int n = 10;
	char arr[n] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	FillRand(arr, n);
	Print(arr, n);
	Sort(arr, n);
	Print(arr, n);

	//cout << "\nShift Left:" << endl;
	//ShiftLeft(arr, n, 5);

	//Print(arr, n);

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

void FillRand(double arr[], const int n, int min, int max)
{
	min *= 100;
	max *= 100;
	for (int i = 0; i < n; i++)
	{
		arr[i] = double(rand() % (max - min) + min)/100;
	}
}

void FillRand(char arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand();
	}
}

template <typename T>
void Print(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
}

template <typename T>
T Sum(T arr[], const int n)
{
	T s = 0;
	for (int i = 0; i < n; i++) s += arr[i];
	return s;
}

template <typename T>
double Avg(T arr[], const int n)
{
	return (double)Sum(arr, n) / n;
}

template <typename T>
T MinValueIn(T arr[], const int n)
{
	T min = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min) min = arr[i];
	}

	return min;
}

template <typename T>
T MaxValueIn(T arr[], const int n)
{
	T max = arr[0];

	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max) max = arr[i];
	}

	return max;
}

template <typename T>
void Sort(T arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n - 1; j++)
		{
			if (arr[i] > arr[j])
			{
				T Temp = arr[i];
				arr[i] = arr[j];
				arr[j] = Temp;
			}
		}
	}
}

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
void ShiftRight(T arr[], const int n, int c)
{
	ShiftLeft(arr, n, n - c);
}