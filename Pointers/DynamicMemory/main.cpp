﻿#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab '\t'

template <typename T> void FillRand(T Arr[], const int n);
template <typename T> void FillRand(T** Arr, const int rows, const int cols);

template <typename T> void Print(T Arr[], const int n);
template <typename T> void Print(T** Arr, const int rows, const int cols);

template <typename T> T* Push_back(T* Arr, int &n, T element);	// Добавление элемента в конец массива
template <typename T> T* Push_front(T* Arr, int &n, T element);	// Добавление элемента в начало массива
template <typename T> T* Insert(T* Arr, int &n, T element, int index);	// Добавление элемента по индексу

template <typename T> T** Push_row_back(T** Arr, int& rows, const int cols);	// Добавление строки в конец массива
template <typename T> T** Push_row_front(T** Arr, int& rows, const int cols);	// Добавление строки в начало массива
template <typename T> T** Insert_row(T** Arr, int& rows, const int cols, int index);	// Добавление строки по индексу

template <typename T> void Push_col_back(T** Arr, const int rows, int& cols);	// Добавление столбца в конец массива
template <typename T> void Push_col_front(T** Arr, const int rows, int& cols);	// Добавление столбца в начало массива
template <typename T> void Insert_col(T** Arr, const int rows, int& cols, int index);	// Добавление столбца по индексу

template <typename T> T* Pop_back(T* Arr, int &n);	// Удаление последнего элемента массива
template <typename T> T* Pop_front(T* Arr, int &n);	// Удаление первого элемента массива
template <typename T> T* Erase(T* Arr, int &n, int index);	// Удаление элемента по индексу

template <typename T> T** Pop_row_back(T** Arr, int& rows, const int cols);	// Удаление последней строки массива
template <typename T> T** Pop_row_front(T** Arr, int& rows, const int cols);	// Удаление первой строки массива
template <typename T> T** Erase_row(T** Arr, int& rows, const int cols, int index);	// Удаление строки по индексу

template <typename T> void Pop_col_back(T** Arr, const int rows, int& cols);	// Удаление последнего столбца массива
template <typename T> void Pop_col_front(T** Arr, const int rows, int& cols);	// Удаление первого столбца массива
template <typename T> void Erase_col(T** Arr, const int rows, int& cols, int index);	// Удаление столбца по индексу

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_2
#define DYNAMIC_MEMORY_3

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите количество элементов массива: "; cin >> n;
	char* Arr = new char[n];

	FillRand(Arr, n);
	Print(Arr, n);

	Arr = Push_back(Arr, n, 'B');
	Print(Arr, n);

	Arr = Push_front(Arr, n, 'F');
	Print(Arr, n);

	Arr = Insert(Arr, n, 'I', 3);
	Print(Arr, n);

	Arr = Pop_back(Arr, n);
	Print(Arr, n);

	Arr = Pop_front(Arr, n);
	Print(Arr, n);

	Arr = Erase(Arr, n, 2);
	Print(Arr, n);

	delete[] Arr;
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	char** Arr = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new char[cols] {};
	}

	FillRand(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Row Back -------" << endl;
	Arr = Push_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Row Front -------" << endl;
	Arr = Push_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert Row -------" << endl;
	Arr = Insert_row(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Row Back -------" << endl;
	Arr = Pop_row_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Row Front -------" << endl;
	Arr = Pop_row_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase Row -------" << endl;
	Arr = Erase_row(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
#endif // DYNAMIC_MEMORY_2

#ifdef DYNAMIC_MEMORY_3
	int rows, cols;
	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	char** Arr = new char*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new char[cols] {};
	}

	FillRand(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Col Back -------" << endl;
	Push_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Push Col Front -------" << endl;
	Push_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Insert Col -------" << endl;
	Insert_col(Arr, rows, cols, 3);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Col Back -------" << endl;
	Pop_col_back(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Pop Col Front -------" << endl;
	Pop_col_front(Arr, rows, cols);
	Print(Arr, rows, cols);

	cout << "\n------- Erase Col -------" << endl;
	Erase_col(Arr, rows, cols, 2);
	Print(Arr, rows, cols);

	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
#endif // DYNAMIC_MEMORY_3
}


template <typename T>
void FillRand(T Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
	}
}

template <typename T>
void FillRand(T** Arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			Arr[i][j] = rand();
		}
	}
}


template <typename T>
void Print(T Arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << Arr[i] << tab;
	}
	cout << endl;
}

template <typename T>
void Print(T** Arr, const int rows, const int cols)
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


template <typename T>
T* Push_back(T* Arr, int &n, T element)
{
	T* new_Arr = new T[n + 1];

	for (int i = 0; i < n; i++)
	{
		new_Arr[i] = Arr[i];
	}

	new_Arr[n] = element;
	n++;

	delete[] Arr;
	return new_Arr;
}

template <typename T>
T* Push_front(T* Arr, int &n, T element)
{
	T* new_Arr = new T[n + 1];

	new_Arr[0] = element;
	for (int i = 0; i < n; i++)
	{
		new_Arr[i + 1] = Arr[i];
	}

	n++;
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T* Insert(T* Arr, int &n, T element, int index)
{
	if (index > n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T* new_Arr = new T[n + 1];

	/*for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	new_Arr[index] = number;
	for (int i = index; i < n; i++) new_Arr[i + 1] = Arr[i];*/
	for (int i = 0; i < n; i++)
	{
		//(i < index ? new_Arr[i] : new_Arr[i + 1]) = Arr[i];
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = element;

	n++;
	delete[] Arr;
	return new_Arr;
}


template <typename T>
T** Push_row_back(T** Arr, int& rows, const int cols)
{
	T** new_Arr = new T*[rows + 1];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i];
	new_Arr[rows] = new T[cols]{};

	rows++;
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T** Push_row_front(T** Arr, int& rows, const int cols)
{
	T** new_Arr = new T*[rows + 1];

	new_Arr[0] = new T[cols] {};
	for (int i = 0; i < rows; i++) new_Arr[i + 1] = Arr[i];

	rows++;
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T** Insert_row(T** Arr, int& rows, const int cols, int index)
{
	if (index > rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T** new_Arr = new T*[rows + 1];

	for (int i = 0; i < rows; i++)
	{
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = new T[cols] {};

	rows++;
	delete[] Arr;
	return new_Arr;
}


template <typename T>
void Push_col_back(T** Arr, const int rows, int &cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)	Buffer[j] = Arr[i][j];
		
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;
}

template <typename T>
void Push_col_front(T** Arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) Buffer[j + 1] = Arr[i][j];
		
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;
}

template <typename T>
void Insert_col(T** Arr, const int rows, int& cols, int index)
{
	if (index > cols)
	{
		cout << "Выход за пределы массива" << endl;
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++) Buffer[j] = Arr[i][j];
		for (int j = index; j < cols; j++) Buffer[j + 1] = Arr[i][j];
		
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;
}


template <typename T>
T* Pop_back(T* Arr, int &n)
{
	T* new_Arr = new T[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T* Pop_front(T* Arr, int &n)
{
	T* new_Arr = new T[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T* Erase(T* Arr, int &n, int index)
{
	if (index >= n)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T* new_Arr = new T[--n];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < n; i++)new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}


template <typename T>
T** Pop_row_back(T** Arr, int& rows, const int cols)
{
	delete[] Arr[rows-1];
	T** new_Arr = new T*[--rows];

	for (int i = 0; i < rows ; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T** Pop_row_front(T** Arr, int& rows, const int cols)
{
	delete[] Arr[0];
	T** new_Arr = new T*[--rows];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}

template <typename T>
T** Erase_row(T** Arr, int& rows, const int cols, int index)
{
	if (index >= rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T** new_Arr = new T*[--rows];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;
}


template <typename T>
void Pop_col_back(T** Arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j];
		
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}

template <typename T>
void Pop_col_front(T** Arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j + 1];
		
		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}

template <typename T>
void Erase_col(T** Arr, const int rows, int& cols, int index)
{
	if (index >= cols)
	{
		cout << "Выход за пределы массива" << endl;
		return;
	}

	for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols - 1];
		for (int j = 0; j < index; j++) Buffer[j] = Arr[i][j];
		for (int j = index; j < cols; j++) Buffer[j] = Arr[i][j + 1];
		
		delete[]  Arr[i];
		Arr[i] = Buffer;
	}
	cols--;
}