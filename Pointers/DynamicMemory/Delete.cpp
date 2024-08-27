#include "Delete.h"

template <typename T>
T* Pop_back(T* Arr, int &n)
{
	/*T* new_Arr = new T[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;*/

	return Erase(Arr, n, n - 1);
}

template <typename T>
T* Pop_front(T* Arr, int &n)
{
	/*T* new_Arr = new T[--n];

	for (int i = 0; i < n; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;*/

	return Erase(Arr, n, 0);
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
	/*delete[] Arr[rows - 1];
	T** new_Arr = new T*[--rows];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i];
	delete[] Arr;
	return new_Arr;*/

	delete[] Arr[rows - 1];

	/*T** new_Arr = Pop_back(Arr, rows);
	return new_Arr;*/

	return Pop_back(Arr, rows);
}

template <typename T>
T** Pop_row_front(T** Arr, int& rows, const int cols)
{
	/*delete[] Arr[0];
	T** new_Arr = new T*[--rows];

	for (int i = 0; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;*/

	delete[] Arr[0];
	/*T** new_Arr = Pop_front(Arr, rows);
	return new_Arr;*/

	return Pop_front(Arr, rows);
}

template <typename T>
T** Erase_row(T** Arr, int& rows, const int cols, int index)
{
	/*if (index >= rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T** new_Arr = new T*[--rows];

	for (int i = 0; i < index; i++) new_Arr[i] = Arr[i];
	for (int i = index; i < rows; i++) new_Arr[i] = Arr[i + 1];
	delete[] Arr;
	return new_Arr;*/

	/*T** new_Arr = Erase(Arr, rows, index);
	return new_Arr;*/

	return Erase(Arr, rows, index);
}


template <typename T>
void Pop_col_back(T** Arr, const int rows, int& cols)
{
	/*for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j];

		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;*/

	cols--;
	for (int i = 0; i < rows; i++) Arr[i] = Pop_back(Arr[i], ++cols);
}

template <typename T>
void Pop_col_front(T** Arr, const int rows, int& cols)
{
	/*for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols - 1];
		for (int j = 0; j < cols - 1; j++)	Buffer[j] = Arr[i][j + 1];

		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols--;*/

	cols--;
	for (int i = 0; i < rows; i++) Arr[i] = Pop_front(Arr[i], ++cols);
}

template <typename T>
void Erase_col(T** Arr, const int rows, int& cols, int index)
{
	/*if (index >= cols)
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
	cols--;*/

	cols--;
	for (int i = 0; i < rows; i++) Arr[i] = Erase(Arr[i], ++cols, index);
}