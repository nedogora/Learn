#pragma once
#include "constants.h"

template <typename T> void ShiftLeft(T arr[], const int n, int c);	//Циклически сдвигает массив на заданное к-во э-ов влево
template <typename T> void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, int c);