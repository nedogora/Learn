#pragma once
#include "constants.h"
#include "stdafx.h"

#define tab "\t"

template <typename T> void Print(T arr[], const int n);		//Выводит массив на экран
template <typename T> void Print(T arr[ROWS][COLS], const int ROWS, const int COLS);