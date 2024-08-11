#pragma once
#include "stdafx.h"
#include "constants.h"

void FillRand(int arr[], const int n, int min, int max);	//Заполняет массив случайными числами. Обычно массив заполняется случайными числами от 0-100, но при необходимости пользователь может передать пределы генерации случайных чисел
void FillRand(double arr[], const int n, int min = 0, int max = 100);
void FillRand(char arr[], const int n);
void FillRand(int arr[ROWS][COLS], const int ROWS, const int COLS, int min = 0, int max = 100);