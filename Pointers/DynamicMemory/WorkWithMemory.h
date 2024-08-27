#pragma once
#include "stdafx.h"

// Выделение памяти
template <typename T> T* Allocate(const int n);
template <typename T> T** Allocate(const int rows, const int cols);

// Очистка памяти
template <typename T> void Clear(T* Arr);
template <typename T> void Clear(T* Arr, const int rows);