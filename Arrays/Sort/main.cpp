#include <iostream>
using namespace std;
char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int N = 5;
	int Arr[N];

	//Заполнение
	for(int i = 0; i < N; i++)
	{
		Arr[i] = rand() % N;
	}

	//Вывод
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	//Сортировка
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			if (Arr[j] < Arr[i])
			{
				int temp = Arr[i];
				Arr[i] = Arr[j];
				Arr[j] = temp;
			}
		}
	}

	//Вывод
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
}