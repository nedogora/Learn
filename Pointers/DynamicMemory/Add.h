#pragma once
#include "stdafx.h"

template <typename T> T* Push_back(T* Arr, int &n, T element);	// Добавление элемента в конец массива
template <typename T> T* Push_front(T* Arr, int &n, T element);	// Добавление элемента в начало массива
template <typename T> T* Insert(T* Arr, int &n, T element, int index);	// Добавление элемента по индексу

template <typename T> T** Push_row_back(T** Arr, int& rows, const int cols);	// Добавление строки в конец массива
template <typename T> T** Push_row_front(T** Arr, int& rows, const int cols);	// Добавление строки в начало массива
template <typename T> T** Insert_row(T** Arr, int& rows, const int cols, int index);	// Добавление строки по индексу

template <typename T> void Push_col_back(T** Arr, const int rows, int& cols);	// Добавление столбца в конец массива
template <typename T> void Push_col_front(T** Arr, const int rows, int& cols);	// Добавление столбца в начало массива
template <typename T> void Insert_col(T** Arr, const int rows, int& cols, int index);	// Добавление столбца по индексу