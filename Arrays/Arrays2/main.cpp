#include <iostream>
using namespace std;

char tab = '\t';

#define SORT

void main()
{
	setlocale(LC_ALL, "");

	const int N = 5;	//Количество строк/столбцов
	int Arr[N][N] = {};

	//Заполнение случайными числами
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			Arr[i][j] = rand() % 100;
		}
	}

	//Вывод исходного массива:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << "\n=============================================\n";

#ifdef SORT

	//Сортировка:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = i; k < N; k++)
			{
				//int l;
				//for ((k == i) ? l = j + 1 : l = 0; l < N; l++)
				for (int l = k == i ? j + 1 : 0; l < N; l++)
				{
					int temp;
					if (Arr[k][l] < Arr[i][j])
					{
						temp = Arr[i][j];
						Arr[i][j] = Arr[k][l];
						Arr[k][l] = temp;
					}
				}
			}
		}
	}

	//Вывод:
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
#endif // SORT

	cout << "\n=============================================\n";

	//Поиск повторяющихся значений
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			bool metBefore = false;
			int enter = 1;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (k == i ? j : N); l++)
				{
					if (Arr[i][j] == Arr[k][l])
					{
						metBefore = true;
						break;
					}
				}
			}
			if (metBefore)continue;

			for (int k = 0; k <= i; k++)
			{
				int l;
				for ((k == i) ? l = j + 1 : l = 0; l < N; l++)
				{
					if (Arr[i][j] == Arr[k][l])
					{
						enter++;
					}
				}
			}

			if (enter > 1)cout << Arr[i][j] << " встречается " << enter << " раз." << endl;
		}
	}

}