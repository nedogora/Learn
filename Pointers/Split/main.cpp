/*
	Есть массив заполненный случайными числами, нужно создать еще 2 массива минимально возможного размера even и odd.
	В массив even нужно скопироовать все четные числа из исходного  массива, а в массив odd все нечетные
*/
#include <iostream>
using namespace std;

#define tab '\t'

int* Append(int* Arr, int &n, int number);

void main()
{
	setlocale(LC_ALL, "");
	int n, e = 0, o = 0;
	cout << "Введите количество элементов массива: "; cin >> n;
	
	int* Arr = new int[n];
	int* even = new int[e];
	int* odd = new int[o];

	//Заполнение случайными числами
	for (int i = 0; i < n; i++) Arr[i] = rand() % 100;

	//Вывод
	for (int i = 0; i < n; i++) cout << Arr[i] << tab;
	cout << endl;

	//Поиск четных/нечетных
	for (int i = 0; i < n; i++)
	{
		if (Arr[i] % 2 == 0) even = Append(even, e, Arr[i]);
		else odd = Append(odd, o, Arr[i]);
	}

	cout << "\n------------ Even ------------" << endl;
	for (int i = 0; i < e; i++) cout << even[i] << tab;
	cout << endl;

	cout << "\n------------ Odd ------------" << endl;
	for (int i = 0; i < o; i++) cout << odd[i] << tab;
	cout << endl;

	delete[] Arr;
	delete[] even;
	delete[] odd;
}

int* Append(int* Arr, int &n, int number)
{
	int* new_Arr = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		new_Arr[i] = Arr[i];
	}
	
	new_Arr[n] = number;
	n++;
	
	delete[] Arr;
	return new_Arr;
}