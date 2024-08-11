#pragma once
#include<iostream>
using namespace std;

#include "FillRand.h"

template <typename T> double Avg(T arr[], const int n);		//Возвращает среднее арифметическое
template <typename T> double Avg(T arr[ROWS][COLS], const int ROWS, const int COLS);