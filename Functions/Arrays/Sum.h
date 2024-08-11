#pragma once
#include<iostream>
using namespace std;

#include "FillRand.h"

template <typename T> T Sum(T arr[], const int n);	//Возвращает сумму э-ов массива
template <typename T> T Sum(T arr[ROWS][COLS], const int ROWS, const int COLS);