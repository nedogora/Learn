#include <iostream>
using namespace std;

char tab = '\t';

//#define REPEATS
//#define SORT

void main()
{
	setlocale(LC_ALL, "");

	const int ROWS = 3;	//Количество строк/столбцов
	const int COLS = 8;	//Количество строк/столбцов
	int Arr[ROWS][COLS] = {};

	//Заполнение случайными числами
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			Arr[i][j] = rand() % 10;
		}
	}

	//Вывод исходного массива:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}

	cout << "\n=============================================\n";

	for (int i = 0; i < ROWS*COLS; i++)
	{
		for (int j = i + 1; j < ROWS*COLS; j++)
		{
			if (Arr[0][j] < Arr[0][i])
			{
				int temp = Arr[0][i];
				Arr[0][i] = Arr[0][j];
				Arr[0][j] = temp;
			}
		}
	}

	//Вывод отсортированного массива:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
	
#ifdef REPEATS
	//Поиск повторяющихся значений
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			bool metBefore = false;
			int enter = 1;
			for (int k = 0; k <= i; k++)
			{
				for (int l = 0; l < (k == i ? j : COLS); l++)
				{
					if (Arr[i][j] == Arr[k][l])
					{
						metBefore = true;
						break;
					}
				}
			}
			if (metBefore)continue;

			for (int k = i; k < ROWS; k++)
			{
				int l;
				for ((k == i) ? l = j + 1 : l = 0; l < COLS; l++)
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
	cout << "\n=============================================\n";
#endif // REPEATS

#ifdef SORT
	//Сортировка:
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			for (int k = i; k < ROWS; k++)
			{
				//int l;
				//for ((k == i) ? l = j + 1 : l = 0; l < N; l++)
				for (int l = k == i ? j + 1 : 0; l < COLS; l++)
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
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
#endif // SORT

}