#include "WorkWithMemory.h"

template <typename T>
T* Allocate(const int n)
{
	return new T[n];
}

template <typename T>
T** Allocate(const int rows, const int cols)
{
	T** Arr = new T*[rows];
	for (int i = 0; i < rows; i++)
	{
		Arr[i] = new T[cols]{};
	}
	return Arr;
}


template <typename T>
void Clear(T* Arr)
{
	delete[] Arr;
}

template <typename T>
void Clear(T* Arr, const int rows)
{
	for (int i = 0; i < rows; i++)
	{
		delete[] Arr[i];
	}
	delete[] Arr;
}