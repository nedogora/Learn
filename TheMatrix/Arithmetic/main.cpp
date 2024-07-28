#include <iostream>
using namespace std;

//#define Addition
#define Substraction

void main()
{
	setlocale(LC_ALL, "");

	const int M = 3;	//Количество строк
	const int N = 3;	//Количество столбцов
	int Arr[M][N] = {};
	int Brr[M][N] = {};
	int Crr[M][N] = {};	//Результат

	//Заполенение случайными числами
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Arr[i][j] = rand() % 10;
			Brr[i][j] = rand() % 10;
		}
	}

	//Вывод
	cout << "Матрица А:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Матрица B:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Brr[i][j]  << "  ";
		}
		cout << endl;
	}
	cout << endl;

#ifdef Addition

	//Сложение
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Crr[i][j] = (Arr[i][j] + Brr[i][j]);
		}
	}

#endif // Addition

#ifdef Substraction

	//Вычитание
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Crr[i][j] = (Arr[i][j] - Brr[i][j]);
		}
	}

#endif // Substraction

	//Вывод результата:
	cout << "Матрица C:\n\n";
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Crr[i][j] << "  ";
		}
		cout << endl;
	}
}