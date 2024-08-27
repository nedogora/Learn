#pragma once
#include "stdafx.h"

template <typename T> T* Pop_back(T* Arr, int &n);	// Удаление последнего элемента массива
template <typename T> T* Pop_front(T* Arr, int &n);	// Удаление первого элемента массива
template <typename T> T* Erase(T* Arr, int &n, int index);	// Удаление элемента по индексу

template <typename T> T** Pop_row_back(T** Arr, int& rows, const int cols);	// Удаление последней строки массива
template <typename T> T** Pop_row_front(T** Arr, int& rows, const int cols);	// Удаление первой строки массива
template <typename T> T** Erase_row(T** Arr, int& rows, const int cols, int index);	// Удаление строки по индексу

template <typename T> void Pop_col_back(T** Arr, const int rows, int& cols);	// Удаление последнего столбца массива
template <typename T> void Pop_col_front(T** Arr, const int rows, int& cols);	// Удаление первого столбца массива
template <typename T> void Erase_col(T** Arr, const int rows, int& cols, int index);	// Удаление столбца по индексу