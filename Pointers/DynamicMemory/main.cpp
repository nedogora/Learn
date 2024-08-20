#include<iostream>
using namespace std;

void FillRand(int Arr[], const int n);
void Print(int Arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* Arr = new int[n];

	FillRand(Arr, n);
	Print(Arr, n);

	delete[] Arr;
}

void FillRand(int Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void Print(int Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << '\t';
	}
	cout << endl;
}