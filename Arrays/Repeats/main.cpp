#include <iostream>
using namespace std;
char tab = '\t';

void main()
{
	setlocale(LC_ALL, "");
	const int N = 10;
	int Arr[N];	//Исходный массив
	int Brr[N];	//Массив, с повторяющимеся значениями
	int Crr[N];	//Массив с количеством повторений
	bool metBefore = false;
	int repeatIndex = 0;

	//Заполнение случайными числами
	for (int i = 0; i < N; i++) Arr[i] = rand() % 5;

	for (int i = 0; i < N; i++) Crr[i] = 1;

	//Вывод
	for (int i = 0; i < N; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;

	//Поиск повторяющихся значений
	for (int i = 0; i < N; i++)
	{
		metBefore = false;
		for (int j = 0; j < N; j++)
		{
			if (Arr[i] == Brr[j])
			{
				metBefore = true;
				break;
			}
		}

		if (metBefore == false)
		{
			for (int j = i + 1; j < N; j++)
			{
				if (Arr[i] == Arr[j])
				{
					Brr[repeatIndex] = Arr[i];
					Crr[repeatIndex]++;
				}
			}
			if (Arr[i] == Brr[repeatIndex]) repeatIndex++;
		}
	}

	//Вывод повторяющихся элементов
	for (int i = 0; i < repeatIndex; i++)
	{
		cout << "Элемент " << Brr[i] << " встречается " << Crr[i] << " раз." << endl;
	}
}