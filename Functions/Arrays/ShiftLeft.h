#pragma once
#include<iostream>
using namespace std;

#include "FillRand.h"

template <typename T> void ShiftLeft(T arr[], const int n, int c);	//���������� �������� ������ �� �������� �-�� �-�� �����
template <typename T> void ShiftLeft(T arr[ROWS][COLS], const int ROWS, const int COLS, int c);