#pragma once
#include "stdafx.h"

template <typename T> T* Pop_back(T* Arr, int &n);	// �������� ���������� �������� �������
template <typename T> T* Pop_front(T* Arr, int &n);	// �������� ������� �������� �������
template <typename T> T* Erase(T* Arr, int &n, int index);	// �������� �������� �� �������

template <typename T> T** Pop_row_back(T** Arr, int& rows, const int cols);	// �������� ��������� ������ �������
template <typename T> T** Pop_row_front(T** Arr, int& rows, const int cols);	// �������� ������ ������ �������
template <typename T> T** Erase_row(T** Arr, int& rows, const int cols, int index);	// �������� ������ �� �������

template <typename T> void Pop_col_back(T** Arr, const int rows, int& cols);	// �������� ���������� ������� �������
template <typename T> void Pop_col_front(T** Arr, const int rows, int& cols);	// �������� ������� ������� �������
template <typename T> void Erase_col(T** Arr, const int rows, int& cols, int index);	// �������� ������� �� �������