#include "Add.h"

template <typename T>
T* Push_back(T* Arr, int &n, T element)
{
	/*T* new_Arr = new T[n + 1];

	for (int i = 0; i < n; i++)
	{
		new_Arr[i] = Arr[i];
	}

	new_Arr[n] = element;
	n++;

	delete[] Arr;
	return new_Arr;*/

	return Insert(Arr, n, element, n);
}

template <typename T>
T* Push_front(T* Arr, int &n, T element)
{
	/*T* new_Arr = new T[n + 1];

	new_Arr[0] = element;
	for (int i = 0; i < n; i++)
	{
		new_Arr[i + 1] = Arr[i];
	}

	n++;
	delete[] Arr;
	return new_Arr;*/

	return Insert(Arr, n, element, 0);
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
	/*T** new_Arr = new T*[rows + 1];

	for
(int i = 0; i < rows; i++) new_Arr[i] = Arr[i];
	new_Arr[rows] = new T[cols]{};

	rows++;
	delete[] Arr;
	return new_Arr;*/

	/*T** new_Arr = Push_back(Arr, rows, new T[cols]{});
	return new_Arr;*/

	return Push_back(Arr, rows, new T[cols]{});
}

template <typename T>
T** Push_row_front(T** Arr, int& rows, const int cols)
{
	/*T** new_Arr = new T*[rows + 1];

	new_Arr[0] = new T[cols]{};
	for (int i = 0; i < rows; i++) new_Arr[i + 1] = Arr[i];

	rows++;
	delete[] Arr;
	return new_Arr;*/

	/*T** new_Arr = Push_front(Arr, rows, new T[cols]{});
	return new_Arr;*/

	return Push_front(Arr, rows, new T[cols]{});
}

template <typename T>
T** Insert_row(T** Arr, int& rows, const int cols, int index)
{
	/*if (index > rows)
	{
		cout << "Выход за пределы массива" << endl;
		return Arr;
	}

	T** new_Arr = new T*[rows + 1];

	for (int i = 0; i < rows; i++)
	{
		new_Arr[i < index ? i : i + 1] = Arr[i];
	}
	new_Arr[index] = new T[cols]{};

	rows++;
	delete[] Arr;
	return new_Arr;*/

	/*T** new_Arr = Insert(Arr, rows, new T[cols]{}, index);
	return new_Arr;*/

	return Insert(Arr, rows, new T[cols]{}, index);
}


template <typename T>
void Push_col_back(T** Arr, const int rows, int &cols)
{
	/*for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++)	Buffer[j] = Arr[i][j];

		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;*/

	cols++;
	for (int i = 0; i < rows; i++) Arr[i] = Push_back(Arr[i], --cols, {});
}

template <typename T>
void Push_col_front(T** Arr, const int rows, int& cols)
{
	/*for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < cols; j++) Buffer[j + 1] = Arr[i][j];

		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;*/

	cols++;
	for (int i = 0; i < rows; i++) Arr[i] = Push_front(Arr[i], --cols, {});
}

template <typename T>
void Insert_col(T** Arr, const int rows, int& cols, int index)
{
	/*for (int i = 0; i < rows; i++)
	{
		T* Buffer = new T[cols + 1]{};
		for (int j = 0; j < index; j++) Buffer[j] = Arr[i][j];
		for (int j = index; j < cols; j++) Buffer[j + 1] = Arr[i][j];

		delete[] Arr[i];
		Arr[i] = Buffer;
	}
	cols++;*/

	cols++;
	for (int i = 0; i < rows; i++) Arr[i] = Insert(Arr[i], --cols, {}, index);
}
