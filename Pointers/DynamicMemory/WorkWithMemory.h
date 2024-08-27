#pragma once
#include "stdafx.h"

// ��������� ������
template <typename T> T* Allocate(const int n);
template <typename T> T** Allocate(const int rows, const int cols);

// ������� ������
template <typename T> void Clear(T* Arr);
template <typename T> void Clear(T* Arr, const int rows);