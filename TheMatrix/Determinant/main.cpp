#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");
	const int N = 3;
	int Arr[N][N] = {};
	int Brr[N][N * 2] = {};

	int mul = 1;
	int sum_main = 0;
	int sum_second = 0;

	//Заполнение исходного случайныи числами:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Arr[i][j] = rand() % 10;
		}
	}

	//Заполнение расширенного массива
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Brr[i][j + N] = Brr[i][j] = Arr[i][j];
		}
	}

	//Вывод
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Arr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	cout << "Расширенная матрица:" << endl;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N * 2; j++)
		{
			cout << Brr[i][j] << "  ";
		}
		cout << endl;
	}
	cout << endl;

	//Сумма главной диагонали
	for (int i = 0; i < N; i++)
	{
		mul = 1;
		for (int j = 0; j < N; j++)
		{
			mul *= Brr[j][i + j];
		}
		sum_main += mul;
	}


	//Разница побочной диагонали
	for (int i = 0; i < N; i++)
	{
		mul = 1;
		for (int j = 0; j < N; j++)
		{
			mul *= Brr[(N - 1) - j][i + j];
		}
		sum_second += mul;
	}

	cout << endl;
	cout << "Determinant = " << sum_main - sum_second << endl;
}