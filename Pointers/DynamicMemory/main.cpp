#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'

/*
	??? push_row_back(???);
	??? push_row_front(???);
	??? insert_row(???);

	??? pop_row_back(???);
	??? pop_row_front(???);
	??? erase_row(???);

*/

void FillRand(int Arr[], const int n);
void FillRand(int** Arr, const int rows, const int cols, int min=0, int max=100);

void Print(int Arr[], const int n);
void Print(int** Arr, const int rows, const int cols);

int* Push_back(int* Arr, int &n, int number);	// Добавление элемента в конец массива
int* Push_front(int* Arr, int &n, int number);	// Добавление элемента в начало массива
int* Insert(int* Arr, int &n, int number, int index);	// Добавление элемента по индексу

int* Pop_back(int* Arr, int &n);	// Удаление последнего элемента массива
int* Pop_front(int* Arr, int &n);	// Удаление первого элемента массива
int* Erase(int* Arr, int &n, int index);	// Удаление элемента по индексу

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	int* Arr = new int[n];

	FillRand(Arr, n);
	Print(Arr, n);

	Arr = Push_back(Arr, n, 10);
	Print(Arr, n);

	Arr = Push_front(Arr, n, 0);
	Print(Arr, n);

	Arr = Insert(Arr, n, 111, 3);
	Print(Arr, n);

	Arr = Pop_back(Arr, n);
	Print(Arr, n);

	Arr = Pop_front(Arr, n);
	Print(Arr, n);

	Arr = Erase(Arr, n, 3);
	Print(Arr, n);

	delete[] Arr;
#endif // DYN

	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	int** Arr = new int*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new int[cols] {};
	}

	FillRand(Arr, rows, cols, 200, 300);
	Print(Arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}

void FillRand(int Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void FillRand(int** Arr, const int rows, const int cols, int min, int max)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = rand() % (max - min) + min;
		}
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

void Print(int** Arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << Arr[i][j] << tab;
		}
		cout << endl;
	}
}

int* Push_back(int* Arr, int &n, int number)
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

int* Push_front(int* Arr, int &n, int number)
{
	int* new_Arr = new int[n + 1];

	new_Arr[0] = number;
	for (int i = 0; i < n; i++)
	{
		new_Arr[i + 1] = Arr[i];
	}
	
	n++;
	delete[] Arr;
	return new_Arr;
}

int* Insert(int* Arr, int &n, int number, int index)
{
	if (index > n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int* new_Arr = new int[n + 1];

	/*for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	new_Arr[index] = number;
	for (int i = index; i < n; i++) new_Arr[i + 1] = Arr[i];*/
	for (int i = 0; i < n; i++)
	{
		//(i < index ? new_Arr[i] : new_Arr[i + 1]) = Arr[i];
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = number;

	n++;
	delete[] Arr;
	return new_Arr;
}

int* Pop_back(int* Arr, int &n)
{
	int* new_Arr = new int[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;
}

int* Pop_front(int* Arr, int &n)
{
	int* new_Arr = new int[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i+1];
	delete[] Arr;
	return new_Arr;
}

int* Erase(int* Arr, int &n, int index)
{
	if (index > n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	int* new_Arr = new int[--n];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < n; i++)new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}