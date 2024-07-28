#include <iostream>
using namespace std;

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

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < M; j++)
		{
			for (int k = 0; k < N; k++)
			{
				Crr[i][j] += Arr[i][k] * Brr[k][j];
			}
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
			cout << Brr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

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